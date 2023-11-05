

<details>
  <summary style="font-size: 30px; font-weight: 500; cursor: pointer;">System Calls Part #2 | Signals & Process Terminations </summary>

# **Exec Variants**

### execlp

**execlp** works like **execl** but does not require a full path to the executable. 
Instead, it searches the directories in the **PATH** environment variable for the executable.

```c
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Running ls with execlp\n");
    execlp("ls", "ls", "-l", (char *)NULL);

    printf("This will only print if execlp fails!\n");
    return 0;
}

```

### execv

**execv** takes two arguments: the path to the executable and an array of pointers to null-terminated strings that represent the argument list. 
This array must be terminated by a NULL pointer.

```c
#include <stdio.h>
#include <unistd.h>

int main() {
    char *args[] = { "ls", "-l", NULL };

    printf("Running ls with execv\n");
    execv("/bin/ls", args);

    printf("This will only print if execv fails!\n");
    return 0;
}
```

### execlp

**execlp** works like execl but does not require a full path to the executable. Instead, it searches the directories in the PATH environment variable for the executable.

```c
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Running ls with execlp\n");
    execlp("ls", "ls", "-l", (char *)NULL);

    printf("This will only print if execlp fails!\n");
    return 0;
}
```


### execvp

**execvp** is a combination of execv and execlp. It takes an array of pointers to strings for arguments like execv, and it searches the PATH for the executable like execlp.

```c
#include <stdio.h>
#include <unistd.h>

int main() {
    char *args[] = { "grep", "main", "file.txt", NULL };

    printf("Searching for 'main' in file.txt with execvp\n");
    execvp("grep", args);

    printf("This will only print if execvp fails!\n");
    return 0;
}
```

---

# chdir

When a new process is created, typically through a fork followed by an exec, it inherits the current working directory from its parent process. This means that, for example, if you're in a shell and your current working directory is `/home/user`, any program you start from that shell without changing the directory will start with `/home/user` as its current working directory.

The **chdir()** system call is used to change the current working directory of the process that invokes it. Here's a description and an example of using chdir() in a C program:

```c
#include <stdio.h>
#include <unistd.h>

int main() {
    // The current working directory is inherited from the parent process.
    // Let's say we want to change it to "/tmp".

    printf("Changing the current working directory to /tmp\n");
    if (chdir("/tmp") != 0) {
        perror("chdir failed");
        return 1; // Return a non-zero value to indicate an error.
    }

    // If successful, the current working directory is now /tmp.
    printf("Current working directory changed to /tmp successfully\n");

    // The rest of the program would go here.

    return 0;
}
```

Another Example of using `chdir` change dir
![sp61](../static/SP_6_1.png)


---

# Signals

Programs must sometimes deal with unexpected or unpredictable
events, such as:

- a floating-point error
- a power failure
- an alarm clock "ring"
- the death of a child process
- a termination request from a user (i.e., a Control-C)
- a suspend request from a user (i.e., a Control-Z)

These kind of events are sometimes called interrupts, as they must interrupt the regular flow of a program in order to be processed.


```c
#include <stdio.h>
#include <unistd.h> // For alarm() and pause()

// main function starts here
int main() {
    alarm(3); // Schedule an alarm signal to be sent in 3 seconds

    printf("Looping forever...\n");
    while(1); // Infinite loop, normally not a good idea, but for demo purposes.

    // This line will not be executed because the program will be terminated by the alarm signal
    printf("This line should never be executed\n");

    return 0; // Return 0, although the program will never reach this point due to the alarm
}
```


### Alarm with Signal Handler to do more upon Alarm:

```c
#include <stdio.h>
#include <unistd.h> // For alarm() and pause()
#include <signal.h> // For signal handling

int alarmFlag = 0; // Global variable to communicate between the signal handler and the main loop

void alarmHandler(); // Forward declaration of the alarm signal handler

// Signal handler definition
void alarmHandler() {
    printf("An alarm clock signal was received\n");
    alarmFlag = 1; // Set the flag to break the loop in main
}

// main function starts here
int main() {
    signal(SIGALRM, alarmHandler); // Register the alarmHandler function for the SIGALRM signal

    alarm(3); // Schedule an alarm signal in 3 seconds
    printf("Looping...\n");

    while(!alarmFlag) { // Loop until alarmFlag is set by the signal handler
        pause(); // Wait for a signal to arrive
    }

    printf("Loop ends due to alarm signal\n");

    return 0; // Return 0 to indicate success
}
```

![sp62](../static/SP_6_2.png)

* Signals are a separate mechanism from file sockets and General IO, and they are used for inter-process communication and handling asynchronous events.

### Protecting Critical Code and Chaining Interrupt Handlers

- The same techniques may be used to protect critical
pieces of code against Control-C attacks and other such
signals.
- In these cases, it's common to save the previous value of
the handler so that it can be restored after the critical
code has executed.
- Here's the source code of a program that protects itself
against SIGINT signals:

**CTRL+C Attack** refer to the action of a user sending an interrupt signal *(SIGINT)* to a running program by pressing Control-C on the keyboard. This key combination is commonly used in Unix-like operating systems to terminate a running process.

In many command-line interfaces (CLIs), pressing Control-C will send the interrupt signal to the foreground process group, which by default causes the process to terminate. However, this behavior can be customized or overridden within a program by changing the signal handler for SIGINT.

```c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// Global variable for original SIGINT handler to restore later
void (*originalSigintHandler)(int);

// Custom SIGINT handler
void customSigintHandler(int signalNumber) {
    // Do something specific to handle Control-C
    // Typically nothing, or print a message that this section cannot be interrupted
    printf("SIGINT received, but we're ignoring it due to critical operation!\n");
}

// Function to protect a critical section
void criticalSection() {
    // Install the custom SIGINT handler
    originalSigintHandler = signal(SIGINT, customSigintHandler);

    // Critical code goes here...
    printf("Critical section is running. Try pressing Ctrl-C and see what happens.\n");
    sleep(10);  // Pretend to do something important

    // Restore the original SIGINT handler
    signal(SIGINT, originalSigintHandler);
}

int main() {
    printf("Press Ctrl-C during the critical section to test the custom handler.\n");
    criticalSection();
    printf("Critical section finished, Ctrl-C will now stop the program as usual.\n");
    
    // This sleep is just to allow us time to try Ctrl-C after the critical section
    sleep(10);

    return 0;
}
```

In this program, **criticalSection()** changes the signal handler for SIGINT to a custom handler that ignores the Control-C during its execution. After the critical section is complete, it restores the original behavior, allowing the process to be terminated by Control-C as usual.

Protecting critical sections of code from interruption is important in various scenarios, such as when a program is in the middle of a transaction or updating shared resources where an unexpected termination could lead to data corruption or inconsistency.

---


### Sending Signals with `kill`

- A process can signal another with `kill()` system call.
- Misnamed as `kill()` since not all signals terminate processes.
- Historically, `kill()` was used mainly to terminate processes in UNIX.

### Syntax

```c
int kill(pid_t pid, int sigCode);
```

Sends sigCode to process with PID pid.

**kill()** succeeds if:
- Both processes belong to the same user.
- The sender is a super-user.

**Variations of kill()**

- `pid == 0`: The signal is sent to all processes in the sender's process group.

- `pid == -1` with super-user:
  - The signal is sent to all processes.
- `pid == -1` without super-user:
  - The signal is sent to all processes owned by the sender's user, except the sender itself.

- `pid < 0` and `pid != -1`: 
  - The signal is sent to all processes in the specified process group (`pid`).

- **Return Values of `kill()`**:
  - `0`: Signal was sent successfully.
  - `-1`: An error occurred while sending the signal.

---

### Suspension & Resuming of Processes 

```c
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {
    int pid1;
    int pid2;

    // Create first child process
    pid1 = fork();
    if (pid1 == 0) { // First child
        while (1) { // Infinite loop
            printf("pid1 is alive\n");
            sleep(1);
        }
    }

    // Create second child process
    pid2 = fork();
    if (pid2 == 0) { // Second child
        while (1) { // Infinite loop
            printf("pid2 is alive\n");
            sleep(1);
        }
    }

    // Parent process
    // If the fork calls were successful, pid1 and pid2 should be non-zero in the parent process
    if (pid1 > 0 && pid2 > 0) {
        sleep(3); // Give children time to start

        // Suspend first child
        kill(pid1, SIGSTOP);
        sleep(3);

        // Resume first child
        kill(pid1, SIGCONT);
        sleep(3);

        // Terminate first child
        kill(pid1, SIGINT);
        
        // Terminate second child
        kill(pid2, SIGINT);
    }

    return 0; // End of parent process
}
```

 In Unix-like operating systems, signals are used for inter-process communication. The SIGSTOP and SIGCONT signals are specifically used to control the execution of processes:

- **SIGSTOP:**  *Process Suspension* This signal stops a process in its tracks, effectively suspending its execution. The process will remain in a stopped state until it receives a signal to continue. The SIGSTOP signal cannot be caught, blocked, or ignored by the process, making it a reliable way to pause a process.

- **SIGCONT:** *Process Resuming* This signal is used to resume a process that has been stopped by SIGSTOP or another stopping signal like SIGTSTP (which is the signal sent by the Ctrl+Z key combination in a terminal). When a process receives SIGCONT, it continues its execution from where it was stopped.

- **SIGINT** (Signal Interrupt): This signal is typically sent when the user types the interrupt character *(normally Ctrl+C)* at the keyboard. SIGINT tells the process to immediately terminate. 

---

## Process Groups

- **Process Group:** A process group is a collection of one or more processes, usually associated with the same job, that can receive signals as a group. Every process belongs to a process group.

- **Inheritance of Process Group:** When a process (parent) creates a new process (child) through fork(), the child process inherits its parent's process group ID.

- **Changing Process Group:** A process can change its process group by calling setpgid(). *(Maybe dis-associate from parent group as a child proc?)*

- **Control Terminal:** This is the terminal device from which the process was initiated. Typically, it's the terminal you are using to interact with the shell.

- **Inheritance of Control Terminal:** Like process groups, when a process forks, the child process inherits its control terminal from the parent process.

- **Control Process:** The control process is a special process in a session that has a controlling terminal. It's the process group leader of the process group associated with the terminal.

- **Terminal Signals:** If you hit a control key *(like Control-C for SIGINT)* on a terminal, the terminal sends the signal to all processes in the foreground process group of the terminal.

The following C program demonstrates the concept of process groups and how signals like SIGINT (from Control-C) and SIGTTIN can affect processes. The program will create a child process, which will try to read from the terminal while being in a different process group.


```c
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid == -1) {
        // Error
        perror("fork");
        return EXIT_FAILURE;
    }

    if (pid == 0) { // Child process
        // Change the process group of the child
        if (setpgid(0, 0) == -1) {
            perror("setpgid");
            return EXIT_FAILURE;
        }

        // Attempt to read from the control terminal
        char input[10];
        printf("Child process group ID: %d\n", getpgrp());
        printf("Enter some text: ");
        fgets(input, sizeof(input), stdin);
        printf("Child read: %s\n", input);
        return EXIT_SUCCESS;
    } else { // Parent process
        printf("Parent process group ID: %d\n", getpgrp());
        // Wait for the child process to complete
        wait(NULL);
    }

    return EXIT_SUCCESS;
}
```
When you run this program and try to input text for the child process, if it's in the background, it should get suspended because it's trying to read from the terminal while not being in the foreground process group. If it's in the foreground, it should be able to read from the terminal normally.

![SP_63](../static/SP_6_3.png)

Also you can do `getpgid()` to get a Process's Group ID

`pid_t getpgid(pid_t pid)` returns Process Group ID of PID parameter, if PID is 0, the Process Group ID of caller is returned.
</details>

<details>
  <summary style="font-size: 30px; font-weight: 500; cursor: pointer;">Pipe</summary>

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

 **pipefd[2]** declares an array named pipefd that contains two integers. These two integers serve as file descriptors that the pipe() system call uses to provide access to the two ends of the pipe.*(for Read/Write)*

**Here's a breakdown:**

    *pipefd[0]*: This is the read end of the pipe. The process can read data from the pipe through this file descriptor.
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
  <summary style="font-size: 30px; font-weight: 500; cursor: pointer;">Sockets</summary>

</details>