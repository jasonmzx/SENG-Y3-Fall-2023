<details>
<summary style="font-size: 30px; font-weight: 500; cursor: pointer;"> Week 6 | System Calls (Continued.) </summary>

### 1. `execl`, `execv`, `execlp`, `execvp`
These are part of the `exec` family of functions. They replace the current process image with a new process image. This is used for executing a different program within a process. The difference between them is mainly in how they accept arguments:

- `execl` and `execlp` take a variable number of arguments.
- `execv` and `execvp` take an array of strings.

#### Example of `execl`:
```c
#include <unistd.h>
#include <stdio.h>

int main() {
    printf("Starting program...\n");
    execl("/bin/ls", "ls", "-l", (char *) NULL);
    printf("This won't be printed if execl is successful\n");
    return 0;
}
```
This code will print a starting message, then replace the current process with the `ls` command, listing files in the long format.

### 2. `chdir()`
`chdir()` changes the current working directory of the calling process to the directory specified in its argument.

#### Example:
```c
#include <unistd.h>
#include <stdio.h>

int main() {
    system("pwd"); //Display current working dir.

    if (chdir("/tmp") == 0) { //If change dir was success
        printf("Changed directory to /tmp\n");
    } else {
        perror("chdir failed");
    }
    return 0;
}
```
This code attempts to change the working directory to `/tmp`. If successful, it prints a confirmation.
chdir fn. def `int chdir(const char* path)`
- Successful response: `0`
- Erroneous Response: `-1`

### 3. `pause()`
`pause()` causes the calling process to sleep until a signal is received that either terminates the process or causes the invocation of a signal-catching function.

#### Example:
```c
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void signal_handler(int signal) {
    printf("Signal received: %d\n", signal);
}

int main() {
    signal(SIGINT, signal_handler); // Catch interrupt signal (Ctrl+C)
    printf("Pausing. Press Ctrl+C to send signal.\n");
    pause();
    printf("This will be printed after a signal is received.\n");
    return 0;
}
```
This code sets up a signal handler and then pauses the process. It resumes when an interrupt signal (Ctrl+C) is received.

### 4. `kill()`
`kill()` sends a signal to a process or a group of processes, specified by `pid`.

#### Example:
```c
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

int main() {
    pid_t pid = /* PID of the target process */;
    if (kill(pid, SIGTERM) == 0) {
        printf("Sent SIGTERM to process %d\n", pid);
    } else {
        perror("kill failed");
    }
    return 0;
}
```
This code sends a `SIGTERM` signal to a process with a specified PID. Replace `/* PID of the target process */` with an actual PID.
Kill() function definition `int kill(pid_t pid, int sigCode)`
- If **pid = 0** All processes of the sender's process group are killed!
- If **pid = -1** And the cmd is sent by super-user: Kill() is sent to all processes! *(including sender)*
- If **pid = -1** And the cmd is NOT sent by super-use: Kill() Owner specific processes! *(excluding sender)*

---

# Process Groups & More Signals

*The concepts of pausing and resuming processes in Unix-like systems are closely associated with signals and process groups.*

### Process Groups and Control Terminals
- **Process Groups**: A process group is a collection of one or more processes, usually associated with the same job, that can receive signals from the same terminal. A process group is identified by its **process group ID.**
- **Control Terminal**: This is the terminal from which the process was initiated. It can send signals to the process group that is associated with it. *(Master Control Terminal of Process Group)*

### Signals

- **SIGSTOP:**  *Process Suspension* This signal stops a process in its tracks, effectively suspending its execution. The process will remain in a stopped state until it receives a signal to continue. The SIGSTOP signal cannot be caught, blocked, or ignored by the process, making it a reliable way to pause a process.

- **SIGCONT:** *Process Resuming* This signal is used to resume a process that has been stopped by SIGSTOP or another stopping signal like SIGTSTP (which is the signal sent by the Ctrl+Z key combination in a terminal). When a process receives SIGCONT, it continues its execution from where it was stopped.

- **SIGINT** (Signal Interrupt): This signal is typically sent when the user types the interrupt character *(normally Ctrl+C)* at the keyboard. SIGINT tells the process to immediately terminate. 

#### Example 1: Pausing and Resuming a Child Process
```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main() {
    pid_t pid = fork(); // Create a child process
    
    if (pid == 0) { // Child process
        printf("Child process started with PID: %d\n", getpid());
        while(1) {
            // Infinite loop to simulate a long-running process
        }
    } else { // Parent process
        printf("Parent process with PID: %d\n", getpid());
        sleep(2); // Give the child process time to start
        kill(pid, SIGSTOP); // Pause the child process
        printf("Child process paused\n");
        sleep(5); // Wait for 5 seconds
        kill(pid, SIGCONT); // Resume the child process
        printf("Child process resumed\n");
        sleep(2); // Give the child process time to run
        kill(pid, SIGINT); // Terminate the child process
        printf("Child process terminated\n");
    }
    
    return 0;
}
```

use of *kill()* to sent the Signals to the child, given it's PID and SigCode (SIGTERM)

#### Example 2: Handling SIGTTIN
```c
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sigttin_handler(int sig) {
    printf("Received SIGTTIN, process is not in the foreground group.\n");
}

int main() {
    struct sigaction sa;
    sa.sa_handler = sigttin_handler; // Set the handler
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGTTIN, &sa, NULL); // Register the handler for SIGTTIN

    pid_t pid = fork(); // Fork a child process

    if (pid == 0) { // Child process
        setpgid(0, 0); // Change the process group
        printf("Child process with different group, PID: %d\n", getpid());
        char c;
        read(STDIN_FILENO, &c, 1); // Try to read from terminal (will fail)
    } else { // Parent process
        printf("Parent process, PID: %d\n", getpid());
        sleep(2); // Give the child process time to change its group and attempt to read
    }

    return 0;
}
```

The `setpgid(0, 0)` call in the child process changes its process group, making it different from the parent's process group. When the child process attempts to read from the terminal (`read(STDIN_FILENO, &c, 1)`), it will receive a `SIGTTIN` because it is not in the foreground process group of the terminal. The signal handler `sigttin_handler` is invoked, which prints a message indicating that the signal was received.

These examples demonstrate how a process can be paused and resumed, and how the terminal signals like `SIGTTIN` are handled in Unix-like systems.

---

![sys6a](../static/SYS_6_a.png)

Process groups in Unix-like systems are collections of one or more processes that are usually related in some way, often because they were initiated as a job from the same shell. They share the same process group ID (PGID), which is used for delivering signals to the group, like when you hit Ctrl+C in a terminal.

Here's a more detailed explanation with examples:

### Creating Process Groups
Every process is a member of a process group. When a process is started, it inherits its parent's process group. You can also create a new process group by setting the child process's PGID to its own PID (process ID).

### Example: Creating and Using Process Groups
Consider a shell script that starts multiple processes:

```bash
#!/bin/bash

# Start three background processes
sleep 30 &
sleep 30 &
sleep 30 &

# List all jobs with process group IDs
jobs -l
```

Running this script would start three background processes, each running `sleep 30`. The shell assigns them to the same process group, which is typically the PID of the shell script's process.

### C Code Snippet: Creating a Process Group

```c
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid1, pid2;

    // Create a new child process
    pid1 = fork();
    if (pid1 == 0) {
        // This is the first child process
        setpgid(0, 0); // Create a new process group with the child's PID
        printf("First child process with PGID: %d\n", getpgrp());
        // ... child does its work ...
        exit(0);
    }

    // Create another child process
    pid2 = fork();
    if (pid2 == 0) {
        // This is the second child process
        setpgid(0, pid1); // Join the first child's process group
        printf("Second child joined first child's group, PGID: %d\n", getpgrp());
        // ... child does its work ...
        exit(0);
    }

    // Parent process continues...
    printf("Parent's process group ID: %d\n", getpgrp());
    // Parent waits for children to finish
    wait(NULL);
    wait(NULL);

    return 0;
}
```

In this example:

- The first child process creates a new process group with `setpgid(0, 0)`, setting its own PGID to its PID.
- The second child process joins the first child's process group with `setpgid(0, pid1)`, making its PGID the same as the first child's PID.
- The `getpgrp()` function returns the calling process's process group ID.
- The parent process prints its process group ID, which has not changed, because it didn't join a new group or create one.

### Signals and Process Groups
Signals can be sent to every process in a process group. For example, sending a SIGINT to a process group ID will attempt to interrupt every process in that group:

```c
kill(-pgid, SIGINT);
```

Here, the negative sign before the process group ID indicates that `SIGINT` should be sent to the entire group rather than a single process.

Process groups are especially useful for managing jobs in a shell. When you start a background job, the shell creates a new process group for that job. If you start several background jobs, each will typically have its own process group. This allows the shell to manage these jobs collectively or individually, sending signals to pause, resume, or terminate them as needed.

---

### General System Calls for Process Grouping (Getter & Setter)

#### `pid_t setpgid(pid_t pid, pid_t, pGrpId)`
Function *setpgid()* will set a Process' group Id, with **pid**, to the second param **pGrpId**
- If **pid** param is 0, the caller's pGrpId is set. *(The calling process is set to given pGrpId)*

**This function call only works if**
- Either the Caller process, and the PID where their group is being changed, have the same "Owner"
- Or, the caller is owned by a **Super-user**

---

#### `pid_t getpgid(pid_t pid)`
Function *getpgid()* will get a Process (pid)'s Process Group ID!
- If **pid** param is 0, the function will get the *Caller's Process Group ID* (PGID)
</details>

<details>
  <summary style="font-size: 30px; font-weight: 500; cursor: pointer;">Week 6 | Pipe</summary>

```c
int pipe(int fd[2])
```

- **pipe()** creates an unnamed pipe and returns two file
descriptors;
- The descriptor associated with the *"read"* end of the pipe
is stored in fd[0].
- The descriptor associated with the *"write"* end of the
pipe is stored in fd[1].

#### Unnamed Pipes

- **Definition**: Unnamed pipes provide a form of interprocess communication (IPC) that allows data to be transferred in one direction (i.e., no bidirectional communication like sockets).
- **Use Case**: They are often used to enable communication between a parent and its child process.
- **Mechanism**:
  1. The parent process creates an unnamed pipe with the `pipe()` system call, which creates two file descriptors: 
     - `fd[0]` for reading from the pipe.
     - `fd[1]` for writing to the pipe.
  2. The parent process then creates a child process using `fork()`.
  3. In typical use:
     - The writing process (usually the parent) closes the reading end `fd[0]`.
     - The reading process (usually the child) closes the writing end `fd[1]`.
- **Data Flow**: Data written to the writing end of the pipe by the writer is buffered by the kernel until it is read by the reader from the reading end of the pipe.

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2]; //Pipe File Descriptor
    pid_t cpid;
    char buf;
    const char *msg = "Hello from parent!\n";

    // Create a pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    cpid = fork();
    if (cpid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (cpid == 0) {    // Child process
        close(pipefd[1]); // Close unused write end

        // Read data from the pipe
        while (read(pipefd[0], &buf, 1) > 0) {
            write(STDOUT_FILENO, &buf, 1);
        }

        write(STDOUT_FILENO, "\n", 1);
        close(pipefd[0]); // Close read end
        _exit(EXIT_SUCCESS);

    } else {            // Parent process
        close(pipefd[0]); // Close unused read end

        // Write message to the pipe
        write(pipefd[1], msg, strlen(msg));
        close(pipefd[1]); // Reader will see EOF

        // Wait for child to finish
        wait(NULL);
        exit(EXIT_SUCCESS);
    }
}
```

 **pipefd[2]** declares an array named pipefd that contains two integers. These two integers serve as file descriptors that the *pipe()* system call uses to provide access to the two ends of the pipe.*(for Read/Write)*

**Here's a breakdown:** <br></br>
*pipefd[0]*: This is the read end of the pipe. The process can read data from the pipe through this file descriptor. <br></br>
*pipefd[1]*: This is the write end of the pipe. The process can write data to the pipe through this file descriptor.

![SP_63](../static/SP_6_4.png)

---

### Named Pipes (FIFOs) *FIFO is like Stack Data Struct.*

Named pipes, also known as FIFOs (First In, First Out), are a type of inter-process communication mechanism that provide several advantages over unnamed pipes:

- **Persistence**: Unlike unnamed pipes, named pipes have a presence in the file system. This means they persist until they are explicitly removed.
  
- **Accessibility**: They can be accessed by any process that has the appropriate permissions, not just the processes that have a parent-child relationship.
  
- **Communication Between Unrelated Processes**: Named pipes can facilitate communication between two unrelated processes, which is not possible with unnamed pipes.

Named pipes can be created using:

1. **The `mkfifo` command-line utility**: A simple shell command to create a FIFO in the filesystem.
   **EX**:  `mkfifo /path/to/myfifo`


2. **The `mkfifo()` system call**: This allows a FIFO to be created from within a C program.


```c
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define FIFO_NAME "/tmp/myfifo"

int main() {
 // Create a FIFO named pipe
 mkfifo(FIFO_NAME, 0666);

 // Writing to the named pipe
 int fd = open(FIFO_NAME, O_WRONLY);
 char *message = "Hello from the writer!";
 write(fd, message, strlen(message));
 close(fd);

 // Reading from the named pipe in the same process
 // (Usually, you would read in a separate process)
 fd = open(FIFO_NAME, O_RDONLY);
 char buf[128];
 read(fd, buf, sizeof(buf));
 close(fd);

 // Print the message read from the pipe
 printf("Received: %s\n", buf);

 // Cleanup the FIFO
 unlink(FIFO_NAME);

 return 0;
}
```

This program creates a named pipe, writes a message to it, and then reads the message back. Typically, the write and read operations would be done in separate processes. The **unlink()** function is called at the end to remove the named pipe from the filesystem.
</details>


<details>
  <summary style="font-size: 30px; font-weight: 500; cursor: pointer;"> Week 6 | Sockets </summary>

- Mechanism that allows processes to talk to each other even if they're on different machines.
- For example, the **rlogin** utility, which allows a user on one machine to log into a remote host, is implemented using sockets.

**Server Process**
- Creates the socket, which is accessible by client socket processes.
- Client processes can "talk" to the server.

**Client Process**
- Creates an `un-named socket` then requests it to be connected to a `server's named socket`
- Successful connection returns file descriptor to client, and to server
- Sockets are Bi-Directional! Unlike **pipe**

![](../static/SYS_6_1.png)

### 1. **Domains**

   **Definition**: Domains in socket programming define the communication space where both client and server operate.

   **Types**:
   - `PF_LOCAL` or `PF_UNIX`: 
     - **Usage**: Communication between client and server on the same machine.
     - **Example**: Inter-process communication in Unix systems.
     - **C Example**: 
       ```c
       struct sockaddr_un {
           sa_family_t sun_family;       /* AF_UNIX */
           char        sun_path[108];    /* pathname */
       };
       ```
   - `PF_INET`: 
     - **Usage**: For IPv4 Internet protocols.
     - **Example**: HTTP/FTP servers and clients.
     - **C Example**: 
       ```c
       struct sockaddr_in {
           short            sin_family;   /* AF_INET */
           unsigned short   sin_port;     /* Port number */
           struct in_addr   sin_addr;     /* Internet address */
       };
       ```
   - `PF_INET6`: 
     - **Usage**: For IPv6 Internet protocols.
     - **Example**: Modern web applications supporting IPv6.
     - **C Example**: 
       ```c
       struct sockaddr_in6 {
           sa_family_t     sin6_family;   /* AF_INET6 */
           in_port_t       sin6_port;     /* Port number */
           struct in6_addr sin6_addr;     /* IPv6 address */
       };
       ```

### 2. **Types**

   **Definition**: Socket types determine the nature of communication (data transmission) between client and server.

   **Types**:
   - `SOCK_STREAM`: 
     - **Usage**: Provides sequenced, reliable, two-way, connection-based byte streams.
     - **Example**: TCP (Transmission Control Protocol).
     - **C Example**: 
       ```c
       int sockfd = socket(AF_INET, SOCK_STREAM, 0);
       ```
   - `SOCK_DGRAM`:
     - **Usage**: Supports datagrams (connectionless, unreliable messages of a fixed maximum length).
     - **Example**: UDP (User Datagram Protocol).
     - **C Example**: 
       ```c
       int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
       ```

### 3. **Protocols**

   **Definition**: The protocol specifies the specific protocol mechanism being used by the sockets.

   **Usage**: Usually set to `0` to choose the default protocol for the given domain and type.

   **Example**:
   - For a TCP socket, the default protocol is TCP.
   - For a UDP socket, the default protocol is UDP.

   **C Example**:
   ```c
   // For TCP
   int sockfd = socket(AF_INET, SOCK_STREAM, 0);

   // For UDP
   int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
   ```

### Summary:
- Domains (`PF_LOCAL`, `PF_INET`, `PF_INET6`) determine where clients and servers are located.
- Types (`SOCK_STREAM`, `SOCK_DGRAM`) define the communication method.
- Protocols are usually set to `0` to auto-select the standard protocol for the chosen domain and type.
- TCP is used with `SOCK_STREAM` for reliable connections, and UDP is used with `SOCK_DGRAM` for connectionless messages.

**View an Example:** *(in socket_ex/...)*
- Server Socket : `serversocket.c`
- Client Socket : `clientsocket.c`


# Some notes about the code:

- In both `clientsocket.c` & `serversocket.c` They share an exact Initialization and Setup procedure:

client's socket setup: *clientsocket.c*
```c
//* ------------  Step 1. Socket Creation: -------------

//! Socket Creation Setup: (SAME as SERVER!!!)
// AF_INET denotes an IPv4 Internet protocol. 
// SOCK_STREAM provides reliable, two-way, connection-based byte streams 
// (TCP). 0 is for default protocol (TCP).

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) 
        printf("ERROR opening socket"); 
    puts("Socket created");	

//* ------------  Step 2. Server Structure Configurations: -------------

    server.sin_addr.s_addr = inet_addr("127.0.0.1"); // Localhost, indicating machine-only comms. between processes
    server.sin_family =AF_INET; // Specify IPv4 again
    server.sin_port = htons( 8888 );  // Port
```

In this Snippet, it's clear that Both socket conns are being set for IPv4 connection, for a 2-way connection stream, on the default TCP protocol.

Then, upon configuration, they are connected to the same port, on both sockets *(client & server)* the server connection address is explicitly defined!

**clientsocket.c beginning**
```c
    int sock;
    struct sockaddr_in server;
```

**serversocket.c beginning**
```c
int socket_desc, c,read_size;    //* Server Socket Descriptor | c, read_size: Variables to store sizes and return values.
long unsigned int client_socket; //* Client's socket descriptor (Server knows which client is connected).
struct sockaddr_in server, client;
```

---

# Extra

Here you can see the Server Socket uses a client_socket socket descriptor, so it knows who to send back to. If there where more clients, we could potentially make an array of client_sockets?

multi_serversocket.c
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 10

// Client handling function
void *connection_handler(void *);

int main(int argc, char *argv[]) {
    int socket_desc, new_socket, c, *new_sock;
    struct sockaddr_in server, client;
    char *message;

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
    }
    puts("Socket created");

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    // Bind
    if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind failed. Error");
        return 1;
    }
    puts("bind done");

    // Listen
    listen(socket_desc, 3);

    // Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
    while ((new_socket = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&c))) {
        puts("Connection accepted");

        pthread_t sniffer_thread;
        new_sock = malloc(1);
        *new_sock = new_socket;

        if (pthread_create(&sniffer_thread, NULL, connection_handler, (void *)new_sock) < 0) {
            perror("could not create thread");
            return 1;
        }

        // Now join the thread, so that we don't terminate before the thread
        // pthread_join(sniffer_thread, NULL);
        puts("Handler assigned");
    }

    if (new_socket < 0) {
        perror("accept failed");
        return 1;
    }

    return 0;
}

// This will handle connection for each client
void *connection_handler(void *socket_desc) {
    // Get the socket descriptor
    int sock = *(int *)socket_desc;
    int read_size;
    char *message, client_message[2000];

    // Receive a message from client
    while ((read_size = recv(sock, client_message, 2000, 0)) > 0) {
        // Send the message back to client
        write(sock, client_message, strlen(client_message));
    }

    if (read_size == 0) {
        puts("Client disconnected");
        fflush(stdout);
    } else if (read_size == -1) {
        perror("recv failed");
    }

    // Free the socket pointer
    free(socket_desc);

    return 0;
}
```

The main function now contains an infinite loop that constantly accepts new connections.
When a new connection is accepted, it creates a new thread using pthread_create() and passes the new socket descriptor to the connection_handler() function.
    
Each client is handled concurrently because each one is running in a separate thread. **connection_handler()** function is used to handle communication with the client. It reads the message from the client and sends it back (echoes it).

It is important to note that we do not join the threads with **pthread_join()** in the main loop because we want the server to continue accepting new clients. If you wanted to clean up the threads properly, you would need to keep track of the thread IDs and join them when the server shuts down.


There is one main socket, referred to as `socket_desc`, which the server uses to listen for incoming connections. When a client attempts to connect to this listening socket, the `accept` system call creates a new socket for that particular client connection. This new socket is what the `new_socket` variable holds. The `accept` call generates a new file descriptor for each client that is used for communication with that specific client.

Here’s a breakdown of the flow:

1. **Server Socket Creation (`socket_desc`)**: The server starts by creating a listening socket using `socket()`. This socket listens for incoming connections.

2. **Binding**: The server binds the listening socket to a specific port (8888 in this case) using `bind()`.

3. **Listening**: The server calls `listen()` on the listening socket, which allows it to listen for incoming connection requests.

4. **Accepting Connections**: Inside an infinite loop, the server waits for incoming connections using `accept()`. When a client connects, `accept()` returns a new socket file descriptor (`new_socket`) that is unique to that connection.

5. **Handling Multiple Clients**: For each new connection, the server creates a new thread to handle communication with that client. The `new_socket` is passed to the `connection_handler()` function through a pointer to ensure that each thread has its own socket descriptor to communicate with its specific client.

6. **Connection Handler**: The `connection_handler()` function runs in a separate thread for each client. It receives messages from its assigned client and sends responses back.

Each client has its own unique `new_socket` file descriptor, and each of these sockets is managed by a separate thread. The `socket_desc` is only used for listening for new connections, not for communicating with connected clients. The actual communication with each client happens over their unique `new_socket` file descriptors.
</details>