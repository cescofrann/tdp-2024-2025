#include <stdio.h>
#include <string.h>

#define N 30
#define MAXR 100

typedef enum {d_destra, d_sinistra, d_giu, d_su, d_errore} direzione;
typedef enum {s_colonna, s_riga, s_fine, s_errore} selettore;


void leggi_file(FILE *fin, int matrice[][N], int size[]);
void shift_vect(int mat[][N], int sel, int shift, int ind, int dim);
void shift_mat(int mat[][N], selettore s, direzione d, int shift, int indice, int dim);
void display_mat(int mat[][N], int size_mat[]);
int core(int mat[][N], int size_mat[]);


int main(){
    FILE *fp_read;
    char nfile[20], row[MAXR];
    int matrice[N][N], size[2];
    int esito;

    printf("Nome del file da aprire: ");
    scanf("%s", nfile);

    if((fp_read = fopen(nfile, "r")) == NULL){
        printf("Errore nell'apertura del file");
        return 1;
    }

    leggi_file(fp_read, matrice, size);
    display_mat(matrice, size);
    if((esito = core(matrice, size)) <0) printf("Errore, codice: %d\n", esito); 

    fclose(fp_read);
    return 0;
}

void leggi_file(FILE *fin, int mat[][N], int size[]){
    fscanf(fin, "%d %d", &size[0], &size[1]);
    for(int i=0; i<size[0]; i++){
        for(int j=0; j<size[1]; j++){
            fscanf(fin, "%d", &mat[i][j]);
        }
    }
    return;
}

void shift_vect(int mat[][N], int sel, int shift, int ind, int dim){
    int temp, j;
    int vet[]= {dim, dim};
    ind = ind-1;
    switch (sel){
        // shift su colonna
        case 0:
            if(shift < 0){
                shift = - shift;
                for(int i=0; i<shift; i++){
                temp = mat[dim-1][ind];
                j=dim-1;
                while(j>0){
                    mat[j][ind]=mat[j-1][ind];
                    j--;
                }
                mat[j][ind] = temp;
            }
            }else{
                for(int i=0; i<shift; i++){
                    temp = mat[0][ind];
                    j=0;
                    while(j<dim-1){
                        mat[j][ind] = mat[j+1][ind];
                        j++;
                    }
                    mat[j][ind] = temp;
                }
            }
                
            break;

        // shift su riga
        case 1:
            if(shift < 0){
                shift = - shift;
                for(int i=0; i<shift; i++){
                    temp = mat[ind][0];
                    j=0;
                    while(j<dim-1){
                        mat[ind][j]=mat[ind][j+1];
                        j++;
                    }
                    mat[ind][j] = temp;
                }
            }else{
                for(int i=0; i<shift; i++){
                    temp = mat[ind][dim-1];
                    j=dim-1;
                    while(j>0){
                        mat[ind][j]=mat[ind][j-1];
                        j--;
                    }
                    mat[ind][j] = temp;
                }
            }
            break;
    }
}

void shift_mat(int mat[][N], selettore s, direzione d, int shift, int indice, int dim){
    switch(s){
        case s_colonna:
            if(d==d_giu){
                shift = - shift;
                shift_vect(mat,0, shift, indice, dim);
            }else{
                shift_vect(mat,0,shift,indice, dim);
            }
            break;
        case s_riga:
            if(d==d_sinistra){
                shift = - shift;
                shift_vect(mat, 1, shift, indice, dim);
            }else{
                shift_vect(mat, 1, shift, indice, dim);
            }
            break;
    }
    return;
}

int core(int mat[][N], int size_mat[]){
    selettore s;
    direzione d;
    int flag = 0, index, shift;
    char sel[8], dir[9];
    char mat_selettori[3][10] = {"colonna", "riga", "fine"}, mat_direzioni [4][9]= {"destra", "sinistra", "giu", "su"};

    while(!flag){
        printf("\nRispetta il formato: <selettore> <indice> <direzione> <posizioni> ");
        scanf("%s", sel);
        if(strcmp(sel, "fine") == 0){
            flag = 1; 
            continue;
        }

        scanf("%d %s %d", &index, dir, &shift);

        if(shift <0) {printf("L'attributo posizioni non può esser negativo"); continue;}
        if(index <0) {printf("L'attributo indice non può esser negativo   "); continue;}

        s = s_colonna;
        d = d_destra;
        while(s<s_errore && strcmp(sel, mat_selettori[s]) !=0){
            s++;
        }
        if(s==s_errore) return -1;
        while(d<d_errore && strcmp(dir, mat_direzioni[d]) != 0){
            d++;
        } 
        if(d == d_errore) return -2;

        if(s==s_colonna && (d!= d_giu && d!= d_su)) return -3;
        if(s==s_riga && (d!=d_destra && d!=d_sinistra)) return -4;
        
        if(s==s_colonna) shift_mat(mat,s, d, shift, index, size_mat[1]);
        else shift_mat(mat,s, d, shift, index, size_mat[0]);

        display_mat(mat, size_mat);

    }
    return 0;
}

void display_mat(int mat[][N], int size_mat[]){
    for(int u=0; u<size_mat[0]; u++){
        for(int v=0; v<size_mat[1]; v++){
            printf("%d ", mat[u][v]);
        }
        printf("\n");
    }
    printf("\n");
}