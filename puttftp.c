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
    	
	printf("Uploading file '%s' from server '%s'\n", file, server);
	// Implement the TFTP download logic here

	// Build and send WRQ packet
	char buffer[BUFFER_SIZE];
	int opcode = htons(TFTP_OPCODE_WRQ);
	memcpy(buffer, &opcode, sizeof(opcode));  // Copy opcode to the buffer
	strcpy(buffer + BUFFER_OFFSET, file);
	strcpy(buffer + BUFFER_OFFSET + strlen(file) + END_OF_FILE_BUFFER_OFFSET, "octet");
	int len = BUFFER_OFFSET + strlen(file) + 1 + strlen("octet") + 1;
	
	if(sendto(sockfd, buffer, len, 0, res->ai_addr, res->ai_addrlen) == SENDTO_ERROR_HANDLER){
		perror("sendto");
		close(sockfd);
		freeaddrinfo(res);
		return 4;
	}

	// Open file
	FILE *fp = fopen(file, "rb");
	if (!fp) {
		perror("fopen");
		close(sockfd);
		freeaddrinfo(res);
		return 5;
	}

	// Send file in blocks
	int block_num = 0;
	struct sockaddr_storage from_addr;
	socklen_t from_len = sizeof(from_addr);
	int read_bytes, sent_bytes, received_bytes;




	close(sockfd);
	freeaddrinfo(res);

    	return 0;
}

