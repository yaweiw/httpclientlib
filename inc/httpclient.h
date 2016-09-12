// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> /* close */
#include <netdb.h> /* gethostbyname */
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR, *PSOCKADDR;
typedef struct in_addr IN_ADDR, *PIN_ADDR;

typedef struct hostent HOSTENT, *PHOSTENT;

extern int Connect(char *hostname);

#ifdef __cplusplus
}
#endif

#endif
