// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include "httpclient.h"

#define SOCKET_ERROR -1
#define IPv4_Protocol AF_INET

SOCKET Connect(char *hostname, unsigned short port)
{
    PHOSTENT hostinfo;
    SOCKADDR_IN sock_in = {0};
    SOCKET sock = socket(IPv4_Protocol, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET)
    {
        perror("socket()");
        return NULL;
    }
    hostinfo = gethostbyname(hostname);
    if (hostinfo == NULL)
    {
        perror("gethostbyname()");
        return NULL;
    }
    sock_in.sin_addr = *((PIN_ADDR)hostinfo->h_addr);
    sock_in.sin_port = htons(port);
    sock_in.sin_family = IPv4_Protocol;
    if (connect(sock, (PSOCKADDR)&sock_in, sizeof(SOCKADDR)) == SOCKET_ERROR)
    {
        perror("connect()");
        return NULL;
    }
    else
    {
        printf("connect success\r\n");
    }
    return sock;
}

int Send(SOCKET sock, char *requestbuffer)
{
    int result = 1;
    if (sock == NULL || requestbuffer == NULL)
    {
        perror("invalid params");
        return result;
    }
    if (send(sock, requestbuffer, strlen(requestbuffer), 0) < 0)
    {
        perror("send()");
        result = 0;
    }
    else
    {
        printf("send succeed\r\n");
        result = 1;
    }
    return result;
}

int Receive(SOCKET sock, char *responsebuffer, int count)
{
    int result = 1;
    if (sock == NULL || responsebuffer == NULL || count == 0)
    {
        perror("invalid params");
        return result;
    }
    if (read(sock, responsebuffer, count) == SOCKET_ERROR)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

int Close(SOCKET sock)
{
    int result = 1;
    if (sock == NULL)
    {
        perror("invalid params");
        return result;
    }
    if (close(sock) == SOCKET_ERROR)
    {
        result = 1;
    }
    else
    {
        resut = 0;
    }
    return result;
}