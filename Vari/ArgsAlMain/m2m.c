#include <stdio.h>
#include <string.h>
#include <ctype.h>

void fileToUpper(FILE *fin, FILE *fout);
void fileToLower(FILE *fin, FILE *fout);


int main(int argc, char * argv[]){
    FILE *fp_read, *fp_write;
    char scelta;
    
    if (argc != 4) {
        printf("Errore nella lettura degli argomenti necessari");
        return 1;
    }

    if ((fp_read = fopen(argv[2], "r")) == NULL) {
        printf("Errore nell'apertura del file da leggere");
        return 2;
    }

    if ((fp_write = fopen(argv[3], "w")) == NULL){
        printf("Errore nell'aperuta del file di scrittura");
        return 3;
    }


    scelta = tolower(argv[1][1]);
    switch (scelta){
        case 'l':
            fileToLower(fp_read, fp_write);
            break;
        case 'u':
            fileToUpper(fp_read, fp_write);
            break;
        case 'h':
            printf("Argomenti attesi: <funzione> <file di lettura> <file di output>. La funzione può esser -l (-L), -u (-U)");
            break;
        default:
            printf("Funzione incorretta.");
            break;
    }

    fclose(fp_read);
    fclose(fp_write);
    return 0;
}


void fileToLower(FILE *fin, FILE *fout){
    char carattere;

    while((carattere = fgetc(fin)) != EOF){
        fputc(tolower(carattere), fout);
    }

    return;
}

void fileToUpper(FILE *fin, FILE *fout){
    char carattere;

    while((carattere = fgetc(fin)) != EOF){
        fputc(toupper(carattere), fout);
    }
    
    return;
}

