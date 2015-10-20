#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "onegin.h"

int main(void) 
{
	FILE *ifp, *ofp; 
	char **lineptr = (char**)(calloc(MAXLINE,sizeof(char)));
	char s[MAXLINE]; 
	int i, nl, n = 1; 

	ifp = fopen(IFNAME, "r");
	if (ifp == NULL) 
	{
		fclose(ifp);  
		ex_handler(); 
	}
	ofp = fopen(OFNAME, "w");
	if (ofp == NULL) 
	{
		fclose(ifp); 
		fclose(ofp); 
		ex_handler(); 
	}
	for(i = 0; i < MAXLINE; )
	{ 
		if ( (i - 1) % MAXLINE == 0){ 
			n = n + 1;
			lineptr = (char**)(realloc(lineptr, MAXLINE*n));
		}
		if(fgets(s, MAXLINE, ifp) == NULL) 
		break; 
	
		if(*s != '\n') 
		{ 
			lineptr[i] = (char *)malloc(sizeof(char) * (strlen(s) + 1)); 
			strcpy(lineptr[i], s); 
			i += 1; 
		} 
	}	 

	nl = i; 
	qsort(lineptr, nl, sizeof(char *), scmp); 

	for(i = 0; i < nl; i++) 
	{ 
		fprintf(ofp, "%s", lineptr[i]); 
		free(lineptr[i]); 
	} 

	fclose(ifp); 
	fclose(ofp); 
	return 0; 

}
