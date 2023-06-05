#include "zhheader.h"

#include <stdio.h>
#include <stdlib.h>

struct sorok
{
	int count;
	char* sor;
}sorok;

int strhossz(char* sor) {
	int hossz = 0;
	for(int j = 0; sor[j] != '\0' && sor[j]!=EOF; j++) {
		hossz++;
	}
	return hossz;
}

void konzolrolir() {
		int sorszamlalo = 0;
		char* sorok = (char*)malloc(sizeof(char)*4+1);
		if(sorok == NULL) {
			fprintf(stderr, "Memory allocation failed!\n");
		}
		int teljeshossz = 0;
		char sor[1025];
		while(fgets(sor, 1024, stdin)!=NULL) {
			sorszamlalo++;
			int hossz = strhossz(sor);
			if(hossz > 0){
				teljeshossz += hossz;
				
				if(teljeshossz <= 4) {
					for(int j = 0; j < hossz; j++) {
						sorok[j+teljeshossz - hossz] = sor[j];
					}
					sorok[teljeshossz] = '\0';
				}
				else {
					sorok = (char*)realloc(sorok, (teljeshossz+1)*sizeof(char));
					if(sorok == NULL) {
						fprintf(stderr, "Memory allocation failed!\n");
					}
					for(int j = 0; j < hossz; j++) {
						sorok[j+teljeshossz - hossz] = sor[j];
					}
					sorok[teljeshossz] = '\0';
				}
			}
		}
		int hossz = strhossz(sorok);
		printf("%d ", sorszamlalo--);
		for(int i = hossz-2; i >= 0; i--) {
			printf("%c", sorok[i]);
			if(sorok[i] == '\n') {
				printf("%d ", sorszamlalo--);
			}
		}
		printf("\n");
		free(sorok);
}

void fajlbolkiir(char* fajlnev) {
	FILE* fp = fopen(fajlnev, "r");
	if(fp == NULL) {
		fprintf(stderr, "File opening unsuccessful!\n");
		return;
	}
	
}