#include <stdio.h>
#include <ctype.h>

char alphcript(char precedente, char carattere);
char numcript(char carattere, int *k);
int codifica(FILE *fin, FILE *fout);
int decodifica(FILE *fin, FILE *fout);

int main(){
    FILE *fp_read, *fp_write;
    char choice;
    char nome_fin[15], nome_fout[15];
    

    printf("Vuoi codificare (c) o decodificare (d) un file ? ");
    scanf("%c", &choice);
    printf("Dichiara il nome del file da leggere e, separato da uno spazio, il nome del file da scrivere ");
    scanf(" %s %s", &nome_fin, &nome_fout);
    
    if ((fp_read = fopen(nome_fin, "r")) == NULL) {
        printf("Errore durante l'apertura del file");
        return 1;
    }

    if ((fp_write = fopen(nome_fout, "w")) == NULL) {
        printf("Errore durante l'apertura del file");
        return 2;
    }

    switch (choice){
        case 'c':
            codifica(fp_read, fp_write);
            break;
        case 'd':
            decodifica(fp_read, fp_write);
            break;
        default:
            printf("Scelta invalida");
            return 3;
    }

    
    fclose(fp_read);
    fclose(fp_write);
    
    printf("Programma eseguito correttamente");
    
    return 0;
}



char alphcript(char precedente, char carattere){
    int h;
    if ( isalpha(precedente) ){

        if (isupper(precedente)){
            h = precedente - 'A';
        }else{
            h = precedente - 'a';
        }

        if (isupper(carattere)){
            carattere = 'A' + (( carattere + h - 'A') % 26); // il carattere viene codificato come segue: calcoliamo la distanza tra A e il carattere (c + h), visto che ci sono solo 26 char accettabili e ordinati secodno codice ASCII, se supero 26 la divisione per lo stesso avrà un resto > 0. Dunque, sommando ad A il resto è come se rincominciassi l'alfabeto
        }else if(islower(carattere)){
            carattere = 'a' + ((carattere + h -'a') % 26); 
        }
        
    }
    return carattere;
}

char numcript(char carattere, int * k){
    carattere = '0' + ((carattere -'0'+ *k)%10);
    *k = 0 + ((*k+1)%10);
    return carattere;
}


int codifica (FILE *fin, FILE *fout){
    char carattere, precedente = ' ';
    int k = 0, h = 0, count = 0;
    
    while((carattere = fgetc(fin)) != EOF ){
            if (isdigit(carattere)){
                precedente = numcript(carattere, &k);
            }else{
                precedente = alphcript(precedente, carattere);
            }
            fputc(precedente, fout);
            count += 1;
        }

    return count;
}

int decodifica (FILE *fin, FILE *fout){
    char carattere, precedente = ' ';
    int f = 0, h = 0, count = 0;

    while ((carattere = fgetc(fin)) != EOF) {

        if (isdigit(carattere)) {
            carattere = '0' + ((carattere - '0' - f + 10) % 10);
            f = (f + 1) % 10;

        } else if (isalpha(precedente)) {
            if (isupper(precedente)) {
                h = precedente - 'A';
            } else {
                h = precedente - 'a';
            }

            if (isupper(carattere)) {
                carattere = 'A' + ((carattere - 'A' - h + 26) % 26);
            } else if (islower(carattere)) {
                carattere = 'a' + ((carattere - 'a' - h + 26) % 26);
            }
        }

        fputc(carattere, fout);
        precedente = carattere;
        count++;
    }

    return count;

}