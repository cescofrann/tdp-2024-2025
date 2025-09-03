#include <stdio.h>
#include <string.h>

#define MAXR 30
#define MAXL 200

typedef struct {char chiave[MAXL+1]; int codice;} codifica;

int main(){
    FILE *fin_sorgente, *fin_dizionario;
    FILE *fp_write;

    char key[5], parola[15];
    char *pstr;
    char carattere;
    int cod, nr, flag = 0;
    int lparola, lchiave;

    
    if((fin_sorgente = fopen("sorgente.txt", "r")) == NULL){
        printf("Errore nell'apertura del file sorgente.txt");
        return 1;
    }
    if((fin_dizionario = fopen("dizionario.txt", "r")) == NULL){
        printf("Errore nell'apertura del file dizionario.txt");
        return 2;
    }
    if((fp_write = fopen("ricordificato.txt", "w")) == NULL){
        printf("Errore nell'apertura del file finale");
        return 3;
    }
    
    
    fscanf(fin_dizionario, "%d", &nr);
    codifica contenitore[MAXR];  

    for(int i=0; i<nr; i++){
        fscanf(fin_dizionario, " $%d$", &contenitore[i].codice);
        fscanf(fin_dizionario, "%s", contenitore[i].chiave);
    }

    
    while((fscanf(fin_sorgente, "%s", &parola))!= EOF){
        fscanf(fin_sorgente, "%c", &carattere);
        for(int j=0; j< nr && flag == 0; j++){
            if(strlen(parola) >= strlen(contenitore[j].chiave)){
                if((pstr = strstr(parola, contenitore[j].chiave)) != NULL){
                    // Qui ho trovato la prima sottostringa utile
                    lparola = strlen(parola);
                    lchiave = strlen(contenitore[j].chiave);
                    for(int n=0; n< (lparola - lchiave); n++){
                        printf("%c", parola[n]);
                    }
                    printf("$%d$", contenitore[j].codice);
                    flag = 1;
                }
            }
        }
        if(flag==0){
            printf("%s", parola);
        }
        flag = 0;
        if(carattere == ' '){
            printf(" ");
        }else if(carattere == '\n'){
            printf("\n");
        }
    }

    fclose(fin_sorgente);
    fclose(fin_dizionario);
    fclose(fp_write);
    return 0;
}