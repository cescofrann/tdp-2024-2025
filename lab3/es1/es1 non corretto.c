#include <stdio.h>
#include <string.h>
#include <ctype.h>

void counter(char c, int *counter, int nrealc, int *countnrealc, FILE *fout);

int main(){
    FILE *fp_read, *fp_write;
    char carattere, successivo;
    char *punteggiatura = ".,;:!?'()";
    int count = 0, nrealchar = 0, flag = 0;

    if ((fp_read = fopen("input.txt", "r")) == NULL) {
        printf("Errore di apertura del file");
        return 1;
    }

    if ((fp_write = fopen("output.txt", "w")) == NULL) {
        printf("Errore di apertura del file di output");
        return 2;
    }

    carattere = fgetc(fp_read);
    while (!feof(fp_read)){
        
        if(isdigit(carattere)) {

            counter('*', &count, 0, &nrealchar, fp_write);

        }else if (strchr(punteggiatura,carattere) != NULL){     

            counter(carattere,  &count, 1, &nrealchar, fp_write);
            flag = 1;

            
            
            if (carattere == '!' || carattere == '?' || carattere == '.'){
                
                carattere = fgetc(fp_read);
                while(!isalpha(carattere) && !feof(fp_read)){
                    counter(carattere,  &count, 1, &nrealchar, fp_write);
                    carattere = fgetc(fp_read);
                    flag = 0;
                }

                counter(toupper(carattere),  &count, 0, &nrealchar, fp_write);                
            }

        }else{
            if(carattere != ' ' && carattere != '\n' && flag == 1){
                counter(32, &count, 0, &nrealchar, fp_write);
            }
            flag = 0;
            counter(carattere, &count, 1, &nrealchar, fp_write);
        }
        carattere = fgetc(fp_read);
    }

    fclose(fp_read);
    fclose(fp_write);
}

// Ogni volta che viene inserito un carattere si richiama questa funzione che impone un limite a 25 caratteri per riga
void counter(char c, int *counter, int nrealc, int *countrealc, FILE *fout){
    *countrealc = *countrealc + nrealc;
    if(c=='\n' || c =='\0'){
        while(*counter < 25){
            *counter = *counter + 1;
            printf(" ");
        }
        *counter = 0;
        printf("| c:%d\n", *countrealc);
        *countrealc = 0;
    }else{
        printf("%c",c);
        *counter = *counter + 1;
        if(*counter == 25){
            *counter = 0;
            printf("| c:%d\n", *countrealc);
            *countrealc = 0;
        }
    }
    return;
}