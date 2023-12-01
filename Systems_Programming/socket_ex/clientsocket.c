#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>  
#include <string.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in server;

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

//* ------------  Step 3. Connect to the Server Socket (similar to Accept, but instead Connects) -------------

    if (connect(sock,(struct sockaddr *)&server,sizeof(server)) < 0){ 
        printf("ERROR connecting");
	return 1;
    }
    
    puts("Connected");


//* ------------  Step 4. MAIN GAME/SERVER LOOP -------------
while(1){
    
    char message[1000], server_reply[2000];
    printf("Please enter the message: ");
    scanf("%s",message);
    puts(message);
    
    if (send(sock,message,strlen(message),0)< 0){ 
        printf("ERROR writing to socket");
    	return 1;
	}
     
   if (recv(sock,server_reply,2000,0)<0){
	    puts("recv failed");
	    break;
	}

    puts("server reply"); //basically printf 
    puts(server_reply);
}

//* ------------  Step 5. Exit Server, (closing client socket) and return -------------
close(sock);
return 0;

}
