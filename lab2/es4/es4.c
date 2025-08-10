#include <stdio.h>
#include <ctype.h>

char alphcript(char precedente, char carattere);
char numcript(char carattere, int *k);

int main(){
    FILE *fp_read, *fp_write;
    char carattere, precedente = ' ', nuovo_carattere;
    int k = 0, h = 0;

    if ((fp_read = fopen("./testo.txt", "r")) == NULL) {
        printf("Errore durante l'apertura del file");
        return 1;
    }

    if ((fp_write = fopen("./codificato.txt", "w")) == NULL) {
        printf("Errore durante l'apertura del file");
        return 2;
    }

    while((carattere = fgetc(fp_read)) != EOF ){
        if (isdigit(carattere)){
            precedente = numcript(carattere, &k);
        }else{
            precedente = alphcript(precedente, carattere);
        }
        fputc(precedente, fp_write);

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