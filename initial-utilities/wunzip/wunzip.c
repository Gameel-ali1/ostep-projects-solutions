#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main (int argc, char* argv[]){
	
	if (argc <=1){
		printf("wunzip: file1 [file2 ...]\n");
		exit(1);
	}
	int count;
	char cc;
	for (int i=1; i<argc; i++){
		FILE *fp = fopen(argv[i], "r");
		if (fp == NULL){
			printf("wunizp: cannot open file\n");
			exit(1);
		}
		
		while((fread(&count, sizeof(int), 1, fp))!= 0 && fread(&cc, sizeof(char), 1, fp)){
			for (int i =0; i< count; i++){
				printf("%c", cc);
			}
		}
		fclose(fp);
	}
	return 0;
}
