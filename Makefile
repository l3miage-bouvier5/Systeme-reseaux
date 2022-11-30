CC= gcc -Wall
SRCCLIENT= sources/mainClient.c sources/client.c sources/requete.c
SRCSERVEUR= sources/mainServeur.c sources/requete.c sources/serveur.c sources/comparaison.c sources/parsingDocument.c sources/function.c sources/requete.c
OBJCLIENT= $(SRCCLIENT:.c=.o)
OBJSERVEUR= $(SRCSERVEUR:.c=.o)
EXEC= bin/client bin/serveur
all:$(EXEC)


bin/client: $(OBJCLIENT)
	$(CC) $^ -o $@

bin/serveur: $(OBJSERVEUR)
	$(CC) $^ -o $@

clean:
	rm $(OBJCLIENT) $(OBJSERVEUR) $(EXEC)