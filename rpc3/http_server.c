/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */


#include "http.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>



void *
http_null_1_svc(void *argp, struct svc_req *rqstp)
{
	static char * result;

	/*
	 * insert server code here
	 */

	return (void *) &result;
}

response *
http_request1_1_svc(data1 *argp, struct svc_req *rqstp)
{
	static response  result;
	char port[8];
  	char *pos;
  	char buffer[256];
  	char root[256] = "public_html";
  	FILE* fichier = NULL;
	 /* Renseignement du port d'écoute */
  	printf("Port d'écoute : ");
  	fgets(port, 8, stdin);
  	if ((pos=strchr(port, '\n')) != NULL) *pos = '\0';
	if(strlen(port)==0){
     		port[0] = '8';
     		port[1] = '0';
  	}

    /* Verification de la demande*/
    char *tok = strtok(argp->request, " ");

	if(strcmp(tok, "GET") == 0){
  		printf("Requete acceptée\n");
	//On récupère la page demandée dans tok
  		tok = strtok(NULL, " ");
  		if(strcmp(tok, "/") == 0){
       		strcat(tok, "index.html");
  		}
  		strcat(root, tok);
  		printf("Tentative d'ouverture de -%s-\n",root);

  	}else{
      printf("Requete rejetée\n");
      /* Envoie du message au client */
      char buffer[32] = "Bad Request";
      result.fd = -1;
      result.char_read = NULL;
      result.byte_read_nbr = 0;
      return &result;
	}
	fichier = fopen(root, "r");
	result.fd = fgetc(fichier);
	memcpy(result.char_read,fichier);
	result.byte_read_nbr = sizeof(fichier);
 return &result;
}

response *
http_request2_1_svc(data2 *argp, struct svc_req *rqstp)
{
	static response  result;

      		if (argp->fd != -1 || argp->fd != (int) NULL){
          		printf("Envoi des données...\n");
          		while(fgetc(result->char_read)-1 != NULL){
	          
          		}
			fclose();
      		}
    
	return &result;
}
