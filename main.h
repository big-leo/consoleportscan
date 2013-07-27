/*
 Copyright (C) 2013 Bogdan Levkiv
 contact us at <raptor02 at ukr dot net>
 
 This program is free software of the GNU General Public License as published
 by the Free Software Foundation.
*/

#ifndef MAIN_H
#define MAIN_H

#include "lib/addr_to_int.h"
#include "child.h"

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

struct pthread_arg
{
 char * addr;
 int port;
};

#endif