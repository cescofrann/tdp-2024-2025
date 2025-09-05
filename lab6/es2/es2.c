#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXC 5
#define MAXS 20
#define MAXP 25

void leggi_sequenze(FILE *fin, char seq[][MAXC], int n);
void strtolower(char stringa[], int n);

int main(){
    FILE *fp_sequenze, *fp_read;
    char sequenze[MAXS][MAXC];
    char parola[MAXP], temp_par[MAXP];
    int n, j=0, pos=1, bonus = 0;

    if((fp_sequenze=fopen("sequenze.txt", "r")) == NULL){
        printf("Errore nell'apertura del file sulle sequenze");
        return 1;
    }

    if((fp_read = fopen("text.txt", "r")) == NULL){
        printf("Errore nell'apertura del file di testo");
        return 2;
    }
    fscanf(fp_sequenze, "%d", &n);
    leggi_sequenze(fp_sequenze, sequenze, n);

for(int i=0; i<n; i++){
    pos=1;
    j=1;
    strtolower(sequenze[i], MAXC);
    
    while(fscanf(fp_read, "%s", parola) != EOF){

        for(int m=0; m<strlen(parola);m++){
            if(ispunct(parola[m])){
                if(parola[m] == '\'') bonus = 1;
                parola[m]='\0';
            }
        }

        strcpy(temp_par, parola);
        strtolower(parola, MAXP); 
        if(strstr(parola,sequenze[i]) && j<10){
            if(j==1) {  
                printf("La sequenza '%s' è contenuta in:\n", sequenze[i]);
            }
            printf("%s (posizione: %d)\n", temp_par, pos);
            j++;
        }
        pos+= bonus +1;
        bonus = 0;
    }
    rewind(fp_read);
}


    fclose(fp_read);
    fclose(fp_sequenze);
    return 0;
}

void leggi_sequenze(FILE *fin, char seq[][MAXC], int n){

    for(int i=0; i<n; i++){
        fscanf(fin, "%s", seq[i]);
    }
    
    return;
}

void strtolower(char stringa[], int n){
    for(int i= 0; i<n; i++){
        stringa[i]= tolower(stringa[i]);
    }
}