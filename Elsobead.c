#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SZALLITMANYOK 100

#define MAX_VIDEKEK 5


typedef struct {
    char videk[50];
    char termelo_nev[50];
    double mennyiseg;
    char fajta[50];
} Szallitmany;

const char* videkek[] = {"Balatoni borvidek", "Egri borvidek", "Tokaji borvidek", "Random borvidek"};

int main() {
    Szallitmany szallitmanyok[MAX_SZALLITMANYOK];
    int szallitmany_szam = 0;
    

    FILE *file = fopen("szolo.dat", "r");
    if(file == NULL){
        printf("Hiba inicializalaskor!\n");
        return 1;
    } else{
        char darabol[100];
        while (fgets(darabol, sizeof(darabol), file)) {
            if (szallitmany_szam < MAX_SZALLITMANYOK) {
                char* token = strtok(darabol, ",");
                if (token != NULL) {
                    strcpy(szallitmanyok[szallitmany_szam].videk, token);
                }
                token = strtok(NULL, ",");
                if (token != NULL) {
                    strcpy(szallitmanyok[szallitmany_szam].termelo_nev, token);
                }
                token = strtok(NULL, ",");
                if (token != NULL) {
                    szallitmanyok[szallitmany_szam].mennyiseg = atof(token);
                }
                token = strtok(NULL, ",");
                if (token != NULL) {
                    token[strcspn(token, "\n")] = '\0'; 
                    strcpy(szallitmanyok[szallitmany_szam].fajta, token);
                }
                szallitmany_szam++;
            }
        }
    }
    

    int valasztas;

    do {
        printf("\nNSZT menu:\n");
        printf("1. Adatok listazasa\n");
        printf("2. Uj szallitmany fogadas\n");
        printf("3. Adat modositas\n");
        printf("4. Szallitmany torles\n");
        printf("5. Mentes\n");
        printf("0. Kilepes\n");
        scanf("%d", &valasztas);

        switch (valasztas) {
            case 1:
                printf("Adatok listazasa:\n");
                for (int i = 0; i < szallitmany_szam; i++) {
                    printf("Videk: %s\n", szallitmanyok[i].videk);
                    printf("Termelo nev: %s\n", szallitmanyok[i].termelo_nev);
                    printf("Mennyiseg: %.2f kg\n", szallitmanyok[i].mennyiseg);
                    printf("Szolo fajtaja: %s\n", szallitmanyok[i].fajta);
                    printf("\n");
                }
                break;

            case 2:
                if (szallitmany_szam < MAX_SZALLITMANYOK) {
                    printf("Uj szallitmany fogadas:\n");
                    printf("Melyik videkrol? (0-%d) (Balatoni borvidek, Egri borvidek, Tokaji borvidek, Random borvidek): ", MAX_VIDEKEK-2);
                    int valasztott;
                    scanf("%d", &valasztott);
                    if (valasztott >= 0 && valasztott < MAX_VIDEKEK) {
                        strcpy(szallitmanyok[szallitmany_szam].videk, videkek[valasztott]);
                        printf("Termelo neve? ");
                        scanf("%s", szallitmanyok[szallitmany_szam].termelo_nev);
                        printf("Adja meg a mennyiseget (kg): ");
                        scanf("%lf", &szallitmanyok[szallitmany_szam].mennyiseg);
                        printf("Milyen szolo fajta? ");
                        scanf("%s", szallitmanyok[szallitmany_szam].fajta);
                        szallitmany_szam++;
                        printf("Rogzitve!\n");
                    } else {
                        printf("Hiba! Valasszon 0-%d kozotti szamot!\n", MAX_VIDEKEK - 2);
                    }
                } else {
                    printf("Nem lehetseges tobb szallitmany!\n");
                }
                break;

            case 3:
                printf("Adat modositasa:\n");
                if (szallitmany_szam > 0) {
                    int modosit;
                    printf("Adja meg a modositani kivant szallitmany indexet (1-%d): ", szallitmany_szam);
                    scanf("%d", &modosit);
                    if (modosit >= 1 && modosit <= szallitmany_szam) {
                        modosit--;
                        printf("Uj szallitmany adatai:\n");
                        printf("Melyik videkrol? (0-%d) (Balatoni borvidek, Egri borvidek, Tokaji borvidek, Random borvidek): ", MAX_VIDEKEK-2);
                        int valasztott;
                        scanf("%d", &valasztott);
                        if (valasztott >= 0 && valasztott < MAX_VIDEKEK) {
                            strcpy(szallitmanyok[modosit].videk, videkek[valasztott]);
                        }
                        printf("Termelo neve: ");
                        scanf("%s", szallitmanyok[modosit].termelo_nev);
                        printf("Mennyisege (kg): ");
                        scanf("%lf", &szallitmanyok[modosit].mennyiseg);
                        printf("Szolo fajtaja: ");
                        scanf("%s", szallitmanyok[modosit].fajta);
                        printf("Az adatokat modositottuk!\n");
                    } else {
                        printf("Hiba! Valasszon 0-%d kozotti szamot!\n", szallitmany_szam);
                    }
                } else {
                    printf("Nincs meg rogzitett szallitmany!\n");
                }
                break;
            case 4:
                printf("Szallitmany torles:\n");
                if(szallitmany_szam > 0){
                    int torles;
                    printf("Adja meg a torolni kivant szallitmanyt (1-%d): ", szallitmany_szam);
                    scanf("%d", &torles);
                    if(torles >= 1 && torles <= szallitmany_szam){
                        torles--;
                        for( int i = torles; i < szallitmany_szam -1; i++){
                            szallitmanyok[i] = szallitmanyok[i+1];
                        }
                        szallitmany_szam--;
                        printf("Szallitmany torolve.\n");
                    } else {
                        printf("Hiba! Valasszon 0-%d kozotti szamot!\n", szallitmany_szam);
                    }
                } else {
                    printf("Meg nem talalhato rogzitett szallitmany.\n");
                }
                break;
            case 5:
                printf("Mentes\n");
                freopen("szolo.dat", "w", file);
                for (int i = 0; i < szallitmany_szam; i++) {
                     fprintf(file, "%s,%s,%.2f,%s\n",szallitmanyok[i].videk, szallitmanyok[i].termelo_nev, szallitmanyok[i].mennyiseg, szallitmanyok[i].fajta);
                }
                printf("Az adatok elmentve.\n");
                break;
            case 0:
                printf("Kilepes\n");
                
                break;
            default:
                printf("Nincs ilyen lehetoseg, valasszon masikat\n");
        }
    } while (valasztas != 0);

    fclose(file);
    return 0;
}
