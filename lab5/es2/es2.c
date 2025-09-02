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
    int cod, nr, flag = 0;
    int len_chiave;

    
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
        for(int j=0; j< nr && flag == 0; j++){
            if(strlen(parola) >= strlen(contenitore[j].chiave)){
                if((pstr = strstr(parola, contenitore[j].chiave)) != NULL){
                    // Qui ho trovato la prima sottostringa utile
                    if(strlen(contenitore[j].codice) == strlen(contenitore[j].chiave)){
                        len_chiave = strlen(contenitore[j].chiave);
                        strncpy(pstr, contenitore[j].chiave, len_chiave);
                    }else{
                        // Da aggiungere questa parte
                    }
                    flag = 1;
                }
            }
        }
        // Stampa su file da aggiungere
        flag = 0;
    }
    


    fclose(fin_sorgente);
    fclose(fin_dizionario);
    fclose(fp_write);
    return 0;
}