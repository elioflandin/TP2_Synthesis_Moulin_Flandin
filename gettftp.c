#include "main.h"

int main(int argc, char *argv[]) {
        if (argc != 3) { // Error handler if not enough arguments
        	fprintf(stderr, "Usage: %s <server> <file>\n", argv[0]);
        	return 1;
    	}
	
	//Retrieved values
	char *server = argv[1];
	char *file = argv[2];
	
	printf("Server: %s \n", server);
	printf("File: %s \n", file);

    	struct addrinfo hints, *res;
    	int sockfd;
    	
	// Setup hints for getaddrinfo
    	memset(&hints, 0, sizeof hints);
    	hints.ai_family = AF_UNSPEC; // AF_INET or AF_INET6 to force version
   	hints.ai_socktype = SOCK_DGRAM; // TFTP is over UDP
    	
	// Get server address info
    	if (getaddrinfo(server, PORT_NUMBER, &hints, &res) != 0) {
        	perror("getaddrinfo");
        	return 2;
    	}
    	
	// Create a socket
    	sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    	if (sockfd == SOCKET_ERROR_HANDLER) { // Socket error handler
        	perror("socket");
        	freeaddrinfo(res);
        	return 3;
    	}
    	
	printf("Downloading file '%s' from server '%s'\n", file, server);
    
	// Implement the TFTP download logic here
    	freeaddrinfo(res);
    	close(sockfd);

    	return 0;
}
