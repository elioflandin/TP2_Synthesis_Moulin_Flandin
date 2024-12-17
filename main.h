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

#define PORT_NUMBER "69"
#define SOCKET_ERROR_HANDLER (-1)

int gettftp();

#endif
