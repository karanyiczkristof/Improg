#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>

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
	
	char* sorok = (char*)malloc(sizeof(char)*4+1);
	if(sorok == NULL) {
		fprintf(stderr, "Memory allocation failed!\n");
	}
	int sorszamlalo = 0;
	int teljeshossz = 0;
	while(!feof(fp)) {
		char sor[1025];
		int i = 0;		
		char c;
		while(i < 1025) {
			c = fgetc(fp);
			if(c == '\n' || c == EOF) {
				sorszamlalo++;
				if(c == '\n') {
					sor[i++] = '\n';
				}
				sor[i++] = '\0';
				break;
			}
			sor[i++] = c;
		}
		int hossz = strhossz(sor);
		if(hossz > 0){
			if(c!= EOF)
				//sor[hossz++] = '\n';
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
	fclose(fp);
	
	int hossz = strhossz(sorok);
	
	int tmp = sorszamlalo;
	if(tmp > 1) {
		printf("%d ", --tmp);
	}
	for(int i = hossz-2; i >= 0; i--) {
		printf("%c", sorok[i]);
		if(sorok[i] == '\n') {
			printf("%d ", --tmp);
		}
	}
	if(sorszamlalo > 1) {
		printf("\n");
	}
	free(sorok);
}
#endif
