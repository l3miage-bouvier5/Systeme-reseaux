#ifndef CLIENT_H
#define CLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include "requete.h"
#include "type.h"

void client(int noPort);
void demandeNumero(int *numRequete);
void demandeRequete1(char* requeteComplete);

#endif