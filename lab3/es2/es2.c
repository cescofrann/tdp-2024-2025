#include <stdio.h>
#include <string.h>
#include <ctype.h>

char skipline(FILE *fin, int *npar);

int main() {
    FILE *fp_read;
    char carattere, precedente = '_';
    char *operatori = "+-*/";
    int cparentesi = 0, nriga = 1;
    int flagnumerr = 0, flagoperr = 0, flagspz = 0, flagop = 0;

    if ((fp_read = fopen("expr.txt", "r")) == NULL) {
        printf("Errore nell'apertura del file da leggere\n");
        return 1;
    }

    carattere = fgetc(fp_read);
    while (!feof(fp_read)) {

        if (carattere == '\n' || carattere == EOF) {
            // notifiche errori
            if (cparentesi != 0)
                printf("Errore nella lettura di una parentesi (espressione %d)\n", nriga);
            if (flagnumerr != 0)
                printf("Errore nella lettura di un numero (espressione %d)\n", nriga);
            if (flagoperr != 0 || flagop != 0)
                printf("Errore nella lettura di un operatore (espressione %d)\n", nriga);

            nriga++;
            cparentesi = 0;
            flagnumerr = 0;
            flagoperr = 0;
            flagop = 0;
        }

        if (carattere == '(') {
            cparentesi++;
            if (precedente != '_' && precedente != '(' && !strchr(operatori, precedente)) {
                flagoperr = 1;
                carattere = skipline(fp_read, &cparentesi);
                continue;
            }
        } else if (isdigit(carattere)) {
            if (flagspz == 1) {
                flagnumerr = 1;
                carattere = skipline(fp_read, &cparentesi);
                continue;
            }
            if (precedente != '_' && precedente != '(' && !strchr(operatori, precedente)) {
                flagnumerr = 1;
                carattere = skipline(fp_read, &cparentesi);
                continue;
            }
        } else if (carattere == ')') {
            cparentesi--;
            if (precedente != ')' && !isdigit(precedente)) {
                flagoperr = 1;
                carattere = skipline(fp_read, &cparentesi);
                continue;
            }
        } else if (strchr(operatori, carattere)) {
            if (precedente != ')' && !isdigit(precedente)) {
                flagoperr = 1;
                carattere = skipline(fp_read, &cparentesi);
                continue;
            }
            flagop = 1;
        }

        if ((isdigit(carattere) || carattere == '(') && flagop == 1)
            flagop = 0;

        if (carattere != ' ' && carattere != '\n')
            precedente = carattere;
        else if (carattere == '\n')
            precedente = '_';

        if (carattere == ' ' && isdigit(precedente))
            flagspz = 1;
        else
            flagspz = 0;

        carattere = fgetc(fp_read);
    }

    fclose(fp_read);
    return 0;
}

char skipline(FILE *fin, int *npar) {
    char c = fgetc(fin);
    while (c != '\n' && c != EOF) {
        if (c == '(') (*npar)++;
        else if (c == ')') (*npar)--;
        c = fgetc(fin);
    }
    return c;
}
