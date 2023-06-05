#include <stdio.h>
#include <stdlib.h>
#include "zhheader.h"

int main(int argc, char** argv) {
	if (argc == 1) {
		konzolrolir();
	}
	else if (argc > 1) {
		for(int i = 1; i < argc; i++) {
			fajlbolkiir(argv[i]);
		}
	}
	return 0;
}