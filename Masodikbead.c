#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

#define MAX_HOSSZ 100
#define MAX_SZALLITMANY 100
#define MIN_FELDOGOZAS 500

char buff[MAX_HOSSZ];

typedef struct {
    int id;
    int videk;
    char nev[MAX_HOSSZ];
    double mennyiseg;
    char fajta[MAX_HOSSZ];
} Szallitmany;

typedef struct {
    char fajta[MAX_HOSSZ];
    double mennyiseg;
} Alapanyag;

char* videk(int i) {
    if (i == 1) {
        return "Balatoni borvidek";
    } else if (i == 2) {
        return "Egri borvidek";
    } else if (i == 3) {
        return "Tokaji borvidek";
    } else {
        return "Nem letezik ilyen borvidek!";
    }
}

void listaz(Szallitmany* szallitmanyok, int szallitmany_szam) {
    printf("Szallitmanyok listaja:\n");
    printf("--------------------------\n");
    for (int i = 0; i < szallitmany_szam; i++) {
        printf("Azonosito: %i\n", szallitmanyok[i].id);
        printf("Videk: %s\n", videk(szallitmanyok[i].videk));
        printf("Termelo neve: %s\n", szallitmanyok[i].nev);
        printf("Mennyiseg: %.2lf kg\n", szallitmanyok[i].mennyiseg);
        printf("Szolo fajta: %s\n", szallitmanyok[i].fajta);
        printf("--------------------------\n");
    }
}

void Videklista(Szallitmany* szallitmanyok, int szallitmany_szam) {
    int vid_azon;
    int off = 0;
    printf("Valasszon borvideket: (1=Balatoni, 2=Egri, 3=Tokaji) ");
    fgets(buff, sizeof(buff), stdin);
    vid_azon = strtol(buff, NULL, 10);
    printf("\n%s:\n", videk(vid_azon));
    printf("--------------------------\n");
    for (int i = 0; i < szallitmany_szam; i++) {
        if (szallitmanyok[i].videk == vid_azon) {
            printf("Azonosito: %i\n", szallitmanyok[i].id);
            printf("Termelo neve: %s\n", szallitmanyok[i].nev);
            printf("Mennyiseg: %.2lf kg\n", szallitmanyok[i].mennyiseg);
            printf("Szolo fajta: %s\n", szallitmanyok[i].fajta);
            printf("--------------------------\n");
            off = 1;
        }
    }
    if (off == 0) {
        printf("Hibas videk bevitel\n");
    }
}

void hozzaad(Szallitmany* szallitmanyok, int szallitmany_szam) {
    printf("Uj adatok Megadasa:\n");
    printf("--------------------------\n");
    printf("Azonosito: ");
    fgets(buff, sizeof(buff), stdin);
    szallitmanyok[szallitmany_szam].id = strtol(buff, NULL, 10);
    printf("Videk: (1=Balaton, 2=Eger, 3=Tokaj) ");
    fgets(buff, sizeof(buff), stdin);
    szallitmanyok[szallitmany_szam].videk = strtol(buff, NULL, 10);
    printf("Termelo: ");
    fgets(szallitmanyok[szallitmany_szam].nev, sizeof(szallitmanyok[szallitmany_szam].nev), stdin);
    szallitmanyok[szallitmany_szam].nev[strcspn(szallitmanyok[szallitmany_szam].nev, "\n")] = '\0';
    printf("Mennyiseg: ");
    fgets(buff, sizeof(buff), stdin);
    szallitmanyok[szallitmany_szam].mennyiseg = strtod(buff, NULL);
    printf("Fajta: ");
    fgets(szallitmanyok[szallitmany_szam].fajta, sizeof(szallitmanyok[szallitmany_szam].fajta), stdin);
    szallitmanyok[szallitmany_szam].fajta[strcspn(szallitmanyok[szallitmany_szam].fajta, "\n")] = '\0';
    printf("--------------------------\n");
}

void modositas(Szallitmany* szallitmanyok, int szallitmany_szam) {
    int mod_azon;
    int off = 0;
    printf("Modositando szallitmany azonositoja:\n");
    fgets(buff, sizeof(buff), stdin);
    mod_azon = strtol(buff, NULL, 10);
    for (int i = 0; i < szallitmany_szam; i++) {
        if (szallitmanyok[i].id == mod_azon) {
            off = 1;
            printf("Uj adatok felvetele:\n");
            printf("--------------------------\n");
            printf("Videk: (1=Balaton, 2=Eger, 3=Tokaj) ");
            fgets(buff, sizeof(buff), stdin);
            szallitmanyok[i].videk = strtol(buff, NULL, 10);
            printf("Termelo: ");
            fgets(szallitmanyok[i].nev, sizeof(szallitmanyok[i].nev), stdin);
            szallitmanyok[i].nev[strcspn(szallitmanyok[i].nev, "\n")] = '\0';
            printf("Mennyiseg: ");
            fgets(buff, sizeof(buff), stdin);
            szallitmanyok[i].mennyiseg = strtod
            (buff, NULL);
            printf("Fajta: ");
            fgets(szallitmanyok[i].fajta, sizeof(szallitmanyok[i].fajta), stdin);
            szallitmanyok[i].fajta[strcspn(szallitmanyok[i].fajta, "\n")] = '\0';
            printf("--------------------------\n");
            printf("Sikeres adatmodositas.\n");
        }
    }
    if (off == 0) {
    printf("Nincs ilyen azonosito.\n");
    }
    printf("--------------------------\n");
    }

    void torol(Szallitmany* szallitmanyok, int szallitmany_szam) {
    int tor_azon;
    int off = 0;
    printf("Adja meg a torolni kivant szallitmany azonositojat:\n");
    fgets(buff, sizeof(buff), stdin);
    tor_azon = strtol(buff, NULL, 10);
    for (int i = 0; i < szallitmany_szam; i++) {
    if (szallitmanyok[i].id == tor_azon) {
    off = 1;
    for (int c = i; c < szallitmany_szam - 1; c++) {
    szallitmanyok[c] = szallitmanyok[c + 1];
    }
    printf("--------------------------\n");
    printf("Sikeres torles!\n");
    }
    }
    if (off == 0) {
    printf("Nincs ilyen azonosito.\n");
    }
    printf("--------------------------\n");
    }

    void iras(Szallitmany* szallitmanyok, int szallitmany_szam, FILE* file) {
    for (int i = 0; i < szallitmany_szam; i++) {
    fprintf(file, "%i,%i,%s,%.2lf,%s\n", szallitmanyok[i].id, szallitmanyok[i].videk, szallitmanyok[i].nev, szallitmanyok[i].mennyiseg, szallitmanyok[i].fajta);
    }
    }

    int osszegez(Alapanyag* alapanyagok, int alapanyagok_szam, char* nev, double mennyiseg) {
    int off = 0;
    int hely;
    for (int i = 0; i < alapanyagok_szam; i++) {
    if (strcmp(alapanyagok[i].fajta, nev) == 0) {
    off = 1;
    hely = i;
    }
    }
    if (off == 1) {
    alapanyagok[hely].mennyiseg += mennyiseg;
    } else {
    strcpy(alapanyagok[alapanyagok_szam].fajta, nev);
    alapanyagok[alapanyagok_szam].mennyiseg = mennyiseg;
    alapanyagok_szam++;
    }
    return alapanyagok_szam;
    }
    int alapanyagvizsgalat(Alapanyag* alapanyagok, int alapanyagok_szam) {
    int off = 0;
    for (int i = 0; i < alapanyagok_szam; i++) {
    if (alapanyagok[i].mennyiseg >= MIN_FELDOGOZAS) {
    off = 1;
    }
    }
    return off;
    }

    void handler(int signumber) {
    if (signumber == SIGUSR1) {
    printf("Feldolgozo keszen all!\n");
    } else if (signumber == SIGUSR2) {
    printf("Szallitmany beerkezett, bor keszitesenek megkezdese.\n");
    }
    }

    void feldolgozas(Alapanyag fogadott, Alapanyag* kesztermek, int darab) {
    srand(time(NULL));
    double x = ((double)rand() / RAND_MAX) * 0.2 + 0.6;
    printf("%.2lf liter bor varhato kilogrammonkent.\n", x);
    kesztermek[darab].mennyiseg = fogadott.mennyiseg * x;
    strcpy(kesztermek[darab].fajta, fogadott.fajta);
    }

    void adatkozles(Alapanyag* alapanyagok, int alapanyagok_szam) {
    Alapanyag fogadott;
    Alapanyag keszbor[MAX_SZALLITMANY];
    Alapanyag kesztermek[MAX_SZALLITMANY];
    int olvasott = 0;
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);

    int pipefd[2];
    int pipebd[2];

    if (pipe(pipefd) == -1 || pipe(pipebd) == -1) {
        perror("Pipe error!");
        exit(EXIT_FAILURE);
    }

    int darab = 0;

    pid_t child;
    
    if (alapanyagvizsgalat(alapanyagok, alapanyagok_szam) == 0) {
        printf("\nNincs elegendo mennyiseg a feldolgozashoz.\n");
    } else {
        child = fork();

        if (child < 0) {
            perror("Fork error");
            exit(EXIT_FAILURE);
        } else if (child == 0) {
            kill(getppid(), SIGUSR1);
            sleep(2);
            close(pipefd[1]);
            close(pipebd[0]);

            while (read(pipefd[0], &fogadott, sizeof(Alapanyag)) > 0) {
                kill(getppid(), SIGUSR2);
                sleep(2);
                printf("%s fajtabol, ", fogadott.fajta);
                feldolgozas(fogadott, kesztermek, darab);
                darab++;
            }
            close(pipefd[0]);

            write(pipebd[1], kesztermek, sizeof(kesztermek));

            close(pipebd[1]);
            exit(EXIT_SUCCESS);
        
        } else { 
            //parent
            close(pipefd[0]);
            close(pipebd[1]);

            for (int i = 0; i < alapanyagok_szam; ++i) {
                if (alapanyagok[i].mennyiseg >= MIN_FELDOGOZAS) {
                    write(pipefd[1], &alapanyagok[i], sizeof(Alapanyag));
                }
    }
    close(pipefd[1]);
    read(pipebd[0], keszbor, sizeof(keszbor));
            close(pipebd[0]);
            sleep(2);
            printf("Borkeszites vege.\n");
            printf("--------------------------\n");
            for (int i = 0; i < MAX_SZALLITMANY; ++i) {
                if (keszbor[i].mennyiseg != 0) {
                    printf("A(z) %s fajta szőlőből, %.2lf liter bor készült.\n", keszbor[i].fajta, keszbor[i].mennyiseg);
                }
            }
        }
    }}

    int main() {
    int menu;
    Szallitmany szallitmanyok[MAX_SZALLITMANY];
    Alapanyag alapanyagok[MAX_SZALLITMANY] = {0};
    int szallitmany_szam = 0;
    int alapanyagok_szam = 0;

    FILE* file;

    file = fopen("szolo.dat", "r");

    if (file == NULL) {
        perror("Open error!");
        return 1;
    } else {
        char sor[MAX_HOSSZ];
        while (fgets(sor, sizeof(sor), file)) {
            if (szallitmany_szam < MAX_SZALLITMANY) {
                char* token = strtok(sor, ",");
                if (token != NULL) {
                    szallitmanyok[szallitmany_szam].id = atoi(token);
                }
                token = strtok(NULL, ",");
                if (token != NULL) {
                    szallitmanyok[szallitmany_szam].videk = atoi(token);
                }
                token = strtok(NULL, ",");
                if (token != NULL) {
                    strcpy(szallitmanyok[szallitmany_szam].nev, token);
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

    do {

        printf("NSZT kft\n");
        printf("1. Adatok listazasa.\n");
        printf("2. Videk szerinti listazas.\n");
        printf("3. Uj szallitmany fogadas.\n");
        printf("4. Adat modositas.\n");
        printf("5. Szallitmany torles.\n");
        printf("6. Mentes (Fajlba iras).\n");
        printf("7. Szolo feldolgozasa.\n");
        printf("8. Kilepes.\n");

        fgets(buff, sizeof(buff), stdin);
        menu = strtol(buff, NULL, 10);

        switch (menu) {
            case 1:
                printf("\n");
                listaz(szallitmanyok, szallitmany_szam);
                break;
            case 2:
                printf("\n");
                Videklista(szallitmanyok, szallitmany_szam);
                break;
            case 3:
                printf("\n");
                hozzaad(szallitmanyok, szallitmany_szam);
                szallitmany_szam++;
                break;
            case 4:
                printf("\n");
                modositas(szallitmanyok, szallitmany_szam);
                break;
            case 5:
                printf("\n");
                torol(szallitmanyok, szallitmany_szam);
                szallitmany_szam--;
                break;
            case 6:
                freopen("szolo.dat", "w", file);
                iras(szallitmanyok, szallitmany_szam, file);
                printf("Elmentve.\n");
                break;
            case 7:
                for (int i = 0; i < MAX_SZALLITMANY; i++) {
                    strcpy(alapanyagok[i].fajta, "");
                    alapanyagok[i].mennyiseg = 0;
                }
                for (int i = 0; i < szallitmany_szam; i++) {
                    if (strlen(szallitmanyok[i].fajta) == 0) {
                        break;
                    }
                    alapanyagok_szam = osszegez(alapanyagok, alapanyagok_szam, szallitmanyok[i].fajta, szallitmanyok[i].mennyiseg);
                }
                adatkozles(alapanyagok, alapanyagok_szam);
                break;
            case 8:
                printf("Kilepes!\n");
                break;
            default:
                printf("Nincs ilyen valasztasi lehetoseg.\n");
                break;
        }
    } while (menu != 8);

    fclose(file);
    return 0;
}