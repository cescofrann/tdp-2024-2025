#include <stdio.h>

#define MAXC 50
#define MAXR 50

void leggi_mat(FILE *fin, int mat[][MAXC], int nc, int nr);
void display_mat(int mat[][MAXC], int nc, int nr);
int core(int mat[][MAXC], int nc, int nr, int scelta);

int main(){
    FILE *fp_read;     
    int matrice[MAXR][MAXC];
    int nr, nc;

    if((fp_read = fopen("input.txt", "r")) == NULL){
        printf("Errore nell'apertura del file");
        return 1;
    }

    fscanf(fp_read, "%d %d", &nr, &nc);
    leggi_mat(fp_read, matrice, nc, nr);

    display_mat(matrice, nc, nr);

    core(matrice, nc, nr, 1);

    fclose(fp_read);
    return 0;
}

void leggi_mat(FILE *fin, int mat[][MAXC], int nc, int nr){
    for(int i=0; i<nr; i++){
        for(int j=0; j<nc; j++){
            fscanf(fin, "%d", &mat[i][j]);
        }
    }
    return;
}

void display_mat(int mat[][MAXC], int nc, int nr){
    for(int i=0; i<nr; i++){
        for(int j=0; j<nc; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int core(int mat[][MAXC], int nc, int nr, int scelta){
    int count=0, max=0, temp_i, larg=0;
    int coords[2];

    switch (scelta){
        case 1: //Altezza
            for(int j=0; j<nc; j++){
                count = 0;
                for(int i=0; i<nr; i++){
                    if(mat[i][j] == 1) {
                        temp_i=i;
                        while(mat[i][j]==1 && i<nr){
                            count++;
                            i++;
                        }
                        i--;
                        if(count > max){
                            max = count;
                            coords[1]=j; 
                            coords[0]=temp_i;
                        }
                    }
                    else count = 0;

                }
            }
            for(int k=0; k<max; k++){
                // conta la larghezza controllando di non sforare si a dx che a sx
            }
            printf("Altezza: %d,%d, altezza: %d", coords[0], coords[1], count);
            break;
        case 2:
            break; //Larghezza
        case 3: //Area
            break;
    }
 
    return 0;
}