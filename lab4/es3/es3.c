#include <stdio.h>
#define N 20

void stampaMat(int mat[][N], int nrighe, int ncolonne, int n);

int main(){
    FILE *fp_read;
    char nfile[20];
    int nr, nc, dim, minimo, flag=1;

    printf("Nome del file: ");
    scanf("%s", nfile);

    if((fp_read = fopen(nfile, "r")) == NULL){
        printf("File non trovato.");
        return 1;
    }

    fscanf(fp_read, "%d %d", &nr, &nc);
    
    int matrice[N][N];

    for (int j = 0; j<nr; j++){
        for (int k=0; k<nc; k++){
            fscanf(fp_read, "%d", &matrice[j][k]);
        }
    }

    minimo = nr<nc?nr:nc;
    while(flag){
        printf("Dichiara la dimensione della sottomatrice quadrata (tra 1 e %d) ", minimo);
        scanf("%d", &dim);
        if(dim <1 || dim > minimo){
            printf("Valore non accettabile");
            flag=0;
        }else stampaMat(matrice, nr,nc,dim);
    }
    
    fclose(fp_read);
    return 0;
}

void stampaMat(int mat[][N], int nrighe, int ncolonne, int n){
    int somma = 0, max = 0, indice[2];
    for(int u = 0; u<=nrighe-n; u++){
        for (int v=0; v<=ncolonne -n; v++){

            for(int j=0; j<n; j++){
                for(int i=0; i<n; i++){
                    somma+= mat[u+j][v+i];
                    printf("%d ", mat[u+j][v+i]);
                }
                if(somma > max){
                    max = somma;
                    indice[0]=u;
                    indice[1]=v;
                }
                printf("\n");
            }
            printf("\n");
            somma = 0;
        }
    }

    printf("La sottomatrice con somma somma degli elementi massima (%d) è:\n", somma);

    for(int o=0; o<n; o++){
        for (int p=0; p<n; p++){
            printf("%d ", mat[indice[0]+o][indice[1]+p]);
        }
        printf("\n");
    }

    return;
}