// main.h
#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>

#define PORT_NUMBER "1069"
#define SOCKET_ERROR_HANDLER (-1) // Define SOCKET_ERROR_HANDLER value
#define SENDTO_ERROR_HANDLER (-1) // Define SENDTO_ERROR_HANDLER value

#define BUFFER_SIZE 516 // Define BUFFER_SIZE, here 512 bytes of data + 4 bytes for the header
#define BUFFER_OFFSET 2 // Define BUFFER_OFFSET to reach the filname-part
#define END_OF_FILE_BUFFER_OFFSET 1 // Define END_OF_FILE_BUFFER_OFFSET to reach the EOF-part

#define TFTP_OPCODE_RRQ 1 // RRQ Code for the TFTP Server
#define TFTP_OPCODE_WRQ 2 // WRQ Code for the TFTP Server
#define TFTP_OPCODE_DATA 3 // Data Code for the TFTP Server
#define TFTP_OPCODE_ACK 4 // ACK Code for the TFTP Server
#define TFTP_OPCODE_ERR 5 // ERR Code for the TFTP Server

#define FOPEN_MODE "wb" // Define the fopen function mode, "wb" is to open an empty file and write in it
#define RECV_FLAG_QUANTITY 0 // Define the number of flags waited on the received message, here none

int gettftp();

#endif
