#include <stdio.h>

int main(){
    FILE *fp_read;
    char nfile[20];
    int count, somma=0, max = 0, indice;
    int nc, nr;
    

    // printf("Dichiara il nome del file: ");
    // scanf("%s", nfile);

    if((fp_read = fopen("input.txt", "r")) == NULL){
        printf("Errore di apertura del file");
        return 1;
    }

    fscanf(fp_read, "%d %d", &nc, &nr);
    int mat[nc][nr];

    for(int y=0; y<nc; y++){
        for(int r=0; r<nr; r++){
            fscanf(fp_read, "%d", &mat[y][r]);
        }
    }
    
    for(int gg= 0; gg<nc; gg++){
        for(int i=0; i<nr; i++){
            count = 0;
            somma = 0;
            while (count <= gg){
                somma += mat[i][count];
                count++;
            }
            if(somma > max){
                max = somma;
                indice = i;
            }
        }
        printf("Nel giorno %d la squadra %d domina la classifica\n", gg, indice);
    }

    fclose(fp_read);
    return 0;
}