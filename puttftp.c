#include "main.h"

int main(int argc, char *argv[]) {
        if (argc != 3) { // Error handler if not enough arguments
        	fprintf(stderr, "Usage: %s <server> <file>\n", argv[0]);
        	return 1;
    	}
	char *server = argv[1];
	char *file = argv[2];
	printf("Server: %s \n", server);
	printf("File: %s \n", file);

}

