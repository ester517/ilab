#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "onegin.h"

int scmp(const void *p1, const void *p2) 
{ 
	const char *s1, *s2; 
	s1 = * (const char **) p1; 
	s2 = * (const char **) p2; 
	return strcmp(s1, s2); 
} 

void ex_handler() 
{ 
	fprintf(stderr, "can not find file!\n"); 
	exit(-1); 
} 
