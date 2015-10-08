#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "onegin.h"

#define MAXLINE 4096 
#define IFNAME "onegin.txt" 
#define OFNAME "onegin_sort.txt" 

int main(void) 
{ 
	FILE *ifp, *ofp; 
	char *lineptr[MAXLINE]; 
	char s[MAXLINE]; 
	int i, nl; 

	ifp = fopen(IFNAME, "r");
	if (ifp == NULL) 
	ex_handler(); 
	ofp = fopen(OFNAME, "w");
	if (ofp == NULL) 
	ex_handler(); 

	for(i = 0; i < MAXLINE; )
	{ 
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
