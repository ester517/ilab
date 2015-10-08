#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#define MAXLINE 4096 
#define IFNAME "onegin.txt" 
#define OFNAME "onegin_sort.txt" 

int scmp(const void *p1, const void *p2) 
{ 
	const char *s1, *s2; 
	s1 = * (const char **) p1; 
	s2 = * (const char **) p2; 
	return strcmp(s1, s2); 
} 

void ex_handler() 
{ 
	fprintf(stderr, "ALL IS REALLY BAD!\n"); 
	exit(-1); 
} 
