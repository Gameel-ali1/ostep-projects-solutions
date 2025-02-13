#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE (64)
int main(int argc, char *argv[]){
	char buffer[BUFFER_SIZE];
	if (argc <2){
		return 0;
	}
	for (int i=1; i<argc; i++){

	FILE *fp = fopen(argv[i], "r");
	if(fp == NULL){ 
		fprintf(stderr, "wcat: cannot open file\n");
		exit(1);
	}
	else{
		while(fgets(buffer, BUFFER_SIZE, fp) != NULL){
			printf("%s", buffer);
		}
	}
	fclose(fp);
	}

	return 0;
	
}

