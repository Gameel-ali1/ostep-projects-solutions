#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[]){
	char *line = NULL;
	size_t size = 0;
	if (argc == 1){
		fprintf(stdout, "wgrep: searchterm [file ...]\n");
		exit(1);
	}
	char *substring = argv[1];
	if (argc ==2 ){
			while(getline(&line, &size, stdin) != -1){
					if (strstr(line, substring) != NULL){
						printf("%s",line);	
				}
			}}
	if (substring != "\0"){
	for (int i=2; i<argc; i++){
		if (argc >2){
			FILE *fp = fopen(argv[i], "r");
			if(fp == NULL){ 
				fprintf(stdout, "wgrep: cannot open file\n");
				exit(1);
			}
			else{
				while(getline(&line, &size, fp) != -1){
					if (strstr(line, substring) != NULL){
						printf("%s",line);	
				}
			}
			fclose(fp);
			}
	}}}
	return 0;
	
}


