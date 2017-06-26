#ifndef _COMMON_SERVER_H_
#define _COMMON_SERVER_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

#include <sys/socket.h>
#include <resolv.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>

typedef int (*per_connection_handler_t)(void);

int handle_connection(int, per_connection_handler_t);
int serve_forever(unsigned short, per_connection_handler_t);

#endif
