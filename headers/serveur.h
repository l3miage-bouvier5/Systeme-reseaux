#ifndef SERVEUR_H
#define SERVEUR_H

#include "stdio.h"
#include "stdlib.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>



void serveur(int noPort);

void endChild();


#endif