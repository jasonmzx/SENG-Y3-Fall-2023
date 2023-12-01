// Server side C/C++ program to demonstrate Socket programming 
#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include<arpa/inet.h>

int main(int argv, char *afgv[]){ 

//* ------------  Step 1. Socket Creation: -------------

int socket_desc, c,read_size;    //* Server Socket Descriptor | c, read_size: Variables to store sizes and return values.
long unsigned int client_socket; //* Client's socket descriptor (Server knows which client is connected).
struct sockaddr_in server, client;

//! Socket Creation Setup:
// AF_INET denotes an IPv4 Internet protocol. 
// SOCK_STREAM provides reliable, two-way, connection-based byte streams 
// (TCP). 0 is for default protocol (TCP).

socket_desc = socket(AF_INET, SOCK_STREAM,0); //create socket itself
if (socket_desc==-1){ 
	 printf("Could not create socket.");
}
puts("Socket created"); //! NOTE: puts is a simpler `printf`

//* ------------  Step 2. Server Structure Configurations: -------------

server.sin_addr.s_addr = inet_addr("127.0.0.1"); // Localhost, indicating machine-only comms. between processes
server.sin_family =AF_INET; // Specify IPv4 again
server.sin_port = htons( 8888 );  // Port

//* ------------  Step 3. Binding & Listening -------------

//* Binds the socket to the IP address and port number specified in server.
if(bind(socket_desc,(struct sockaddr *)&server, sizeof(server)) < 0){  //! if bind() < 0, something's wrong (no bind)
	perror("bind failed. error");
	return 1;
}

//start listening for incoming connections
puts("bind done");

listen(socket_desc,3); //! Passive Socket, Listening for Connections
// 3 is the maximum length of the queue of pending connections.

puts("waiting for incomming connections...");

//!In accept, we need to know a Socket Address Length, therefore C is computed, and passed in next line
c = sizeof(struct sockaddr_in);

//* ------------  Step 4. Accepting Client-Socket Connections -------------


// `accept()` extracts the first connection in the queue of pending connections and creates a new socket for this connection.
client_socket= accept(socket_desc,(struct sockaddr *)&client, (socklen_t*)&c);

// Error handing accept, it will send -1 indicating error in connection
if (client_socket == -1) {
      perror("accept failed");
      return 1;
    }
puts("Connection accepted");


//* ------------  Step 5. MAIN GAME/SERVER LOOP -------------

//!While Server is running, alloc Client-message buffer, receive message, print it, then write back to client 
// recv() receives data from the client.
// write() sends the received message back to the client.

while(1){
	char client_message[1000];
	recv(client_socket, client_message, 2000,0);
	puts(client_message);
	write(client_socket,client_message, strlen(client_message));	 
}
 

//(read_size == 0) if client disconnect, or if an error occurred (read_size == -1).
if(read_size <= 0){ 
  puts("client disconnected");

  //fflush(stdout) ensures that any buffered messages are written to the console.
  fflush(stdout);
}
else if(read_size==-1){
 perror("recv failed");
}
 
return 0;
}
