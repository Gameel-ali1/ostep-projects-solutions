#include <stdio.h>
#include <stdlib.h>


int main (int argc, char *argv[]){
	if (argc ==1){
		printf("wzip: file1 [file2 ...]\n");
		exit(1);
	}
	int count = 0;
	char cc;
	char buffer[512];

	for (int i =1; i<argc; i++){
		FILE *fp = fopen(argv[i], "r");
		if (fp == NULL){
			printf("wzip: cannot open file\n");
			exit(1);
		}
		cc = fgetc(fp); // i got one char to initiate only
		count++; // start with 1 not zero
		while((fgets(buffer, sizeof(buffer), fp)) != NULL){
			for (int i =0; buffer[i] != '\0'; i++){
				if (cc == buffer[i]){
					count++;
				}
			
			else{
				fwrite(&count, sizeof(int), 1, stdout);
				fwrite(&cc, sizeof(char), 1, stdout);
				cc = buffer[i];
				count=1;
				}}
		}
	fclose(fp);}
			fwrite(&count, sizeof(int), 1, stdout);
			fwrite(&cc, sizeof(char), 1, stdout);
			exit(0);
}	
