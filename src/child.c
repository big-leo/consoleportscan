/*
 Copyright (C) 2013 Bogdan Levkiv
 contact us at <raptor02 at ukr dot net>
 
 This program is free software of the GNU General Public License as published
  by the Free Software Foundation.
 */

#include "child.h"

void * child(void * arg) {
    int socket1;
    struct sockaddr_in server1;
    struct pthread_arg child_arg = *(struct pthread_arg *) arg;

    if ((socket1 = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "ERROR create socket1\n");
    }

    memset(&server1, '0', sizeof (server1));
    server1.sin_family = AF_INET;
    server1.sin_port = htons(child_arg.port);
    server1.sin_addr.s_addr = inet_addr(child_arg.addr);

    if (connect(socket1, (struct sockaddr *) &server1, sizeof (server1)) >= 0) {
        fprintf(stderr, "%s:%d\n", child_arg.addr, child_arg.port);
    }
    //else
    //fprintf(stderr, "ERROR connect to %s:%d\n", child_arg.addr, child_arg.port);
    close(socket1);

    pthread_exit(NULL);
    //return 0;
}