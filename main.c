#include <stdio.h>
#include <stdlib.h>
#include "A01.h"


int main(int argc, char **argv){
	if(argc != 2){ 
		printf("Need no more than input file");
		return EXIT_FAILURE;
	}
	
	char *f_name = argv[1]; 
	if(f_name == NULL){
		printf("No file detected");
		return EXIT_FAILURE;
	}	
	
		
	return EXIT_SUCCESS; 
}
