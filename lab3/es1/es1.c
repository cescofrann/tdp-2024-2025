#include <stdio.h>
#include <string.h>
#include <ctype.h>

void counter(char c, int *counter, int nrealc, int *countnrealc, FILE *fout);

int main(){
    FILE *fp_read, *fp_write;
    char carattere, successivo;
    char *punteggiatura = ".,;:!?'()";
    int count = 0, nrealchar = 0;

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
            
            if (carattere == '!' || carattere == '?' || carattere == '.'){
                
                carattere = fgetc(fp_read);

                if (carattere != ' ' && carattere != '\n' && carattere !=  EOF){
                    counter(32, &count, 0, &nrealchar, fp_write);
                }

                while(!isalpha(carattere) && !feof(fp_read)){
                    counter(carattere,  &count, 1, &nrealchar, fp_write);
                    carattere = fgetc(fp_read);
                }

                counter(toupper(carattere),  &count, 0, &nrealchar, fp_write);                
            }else{
                successivo = fgetc(fp_read);
                if (successivo != ' ' && successivo != '\n' && successivo !=  EOF){
                    counter(32, &count, 0, &nrealchar, fp_write);
                }  
                carattere = successivo;
                continue;
            }
        }else{
            counter(carattere, &count, 1, &nrealchar, fp_write);
        }
        carattere = fgetc(fp_read);
    }

    fclose(fp_read);
    fclose(fp_write);
}

// Ogni volta che viene inserito un carattere si richiama questa funzione che impone un limite a 25 caratteri per riga
void counter(char c, int *counter, int nrealc, int *countrealc, FILE *fout){
    if(c=='\n' || c == EOF){
        while(*counter < 25){
            *counter = *counter + 1;
            fprintf(fout, " ");
        }
        *counter = 0;
        fprintf(fout,"| c:%d\n", *countrealc);
        *countrealc = 0;
    }else{
        *countrealc = *countrealc + nrealc;
        fprintf(fout, "%c",c);
        *counter = *counter + 1;
        if(*counter == 25){
            *counter = 0;
            fprintf(fout,"| c:%d\n", *countrealc);
            *countrealc = 0;
        }
    }
    return;
}