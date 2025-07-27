#include <stdio.h>

int main(){
    FILE *fp_read, *fp_write;
    char file_char, choice;

    // fopen cerca un file, se "r": in caso di inesistenza del file restituisce un valore nullo. Se "w": in caso di inesistenza del file lo crea

    // Provo ad aprire il file da leggere e lo assegno alla variabile fp_read
    if ((fp_read = fopen("./guide.txt", "r")) == NULL) {
        // Il file non è accessibile o non esiste
        printf("Errore nell'apertura del file\n");
        return 1;
    }

    // Provo ad aprire, o creare, il file di scrittura e lo assegno alla variabile fp_write
    if ((fp_write = fopen("./output.txt", "w")) == NULL) {
        // Non è stato possibile aprire il file
        printf("Errore nell'apertura del file\n");
        return 2;
    }

    printf("Scrittura in console (C) o su file (F): ");
    choice = getchar();

    while (!feof(fp_read)){
        file_char = fgetc(fp_read);
        if(!feof(fp_read)){
            switch (choice){
                case 'C':
                    printf("\nStampato su console: %c", file_char);
                    break;
                case 'F':
            }
        }
    }
}