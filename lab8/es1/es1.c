#include <stdio.h>

#define MAXC 50
#define MAXR 50

void leggiMatrice(FILE *fin, int mat[][MAXC], int *ncp, int *nrp);
void display_mat(int mat[][MAXC], int nc, int nr);
int core(int mat[][MAXC], int nc, int nr, int scelta);
int find_width(int mat[][MAXC], int nc, int nr, int coords[], int h);
int find_height(int mat[][MAXC], int nc, int nr, int coords[], int w);
int riconosciRegione(int mat[][MAXC], int nc, int nr, int r, int c, int *bp, int *hp);

int main(){
    FILE *fp_read;     
    int matrice[MAXR][MAXC];
    int nrighe, ncolonne, base, altezza;

    if((fp_read = fopen("input.txt", "r")) == NULL){
        printf("Errore nell'apertura del file");
        return 1;
    }

    
    leggiMatrice(fp_read, matrice, &ncolonne, &nrighe);

    display_mat(matrice, ncolonne, nrighe);

    if(riconosciRegione(matrice, nrighe, ncolonne, 1, 1, &base, &altezza)){
        printf("Rettangolo con estremo (%d,%d), base:%d, altezza:%d\n", 1,2, base, altezza);
    }else printf("Non è stato individuato l'inizio di un rettangolo in (%d,%d)\n", base, altezza);


    core(matrice, ncolonne, nrighe, 1);
    core(matrice, ncolonne, nrighe, 2);
    core(matrice, ncolonne, nrighe, 3);

    fclose(fp_read);
    return 0;
}

void leggiMatrice(FILE *fin, int mat[][MAXC], int *ncp, int *nrp){ 
    // *ncp -> valore di ncolonne
    // ncp -> indirizzo di ncolonne
    fscanf(fin, "%d %d", nrp, ncp);
    for(int i=0; i<*nrp; i++){
        for(int j=0; j<*ncp; j++){
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

int riconosciRegione(int mat[][MAXC], int nr, int nc, int r, int c, int *bp, int *hp){
    int coords[]= {r, c};
    *bp=0;
    if(mat[r][c]==0) return 0;
    else{

        if((c==0 && r==0) || (c>0 && mat[r][c-1]!=1 && r==0) || (r>0 && c==0 && mat[c][r-1]!=1) || (c>0 && r>0 && mat[r-1][c]!=1 && mat[r][c-1]!=1)){
            while(mat[r][c]==1 && c<nc){
                c++;
                *bp+=1;
            }
            *hp=find_height(mat, nc,nr, coords, *bp);
            return 1;
        }

    }
    return 0;
}

int find_width(int mat[][MAXC], int nc, int nr, int coords[], int h){
    int l,flag=0,k=0, count;

    l=coords[0];
    count=1;
    while(l>0 && mat[l][coords[1]]==1 && !flag){            
        for(k=coords[1]; k<h && mat[coords[0]][k] == 1; k++);

        if(k==h){
            l--;
            count++;
        }else {
            flag=1;
        }
    }

    l=coords[0];
    while(l<nc && mat[l][coords[1]] == 1 && !flag){
        for(k=coords[1]; k<h && mat[coords[0]][k]==1; k++);

        if(k==h){
            l++;
            count++;
        }else{
            flag=1;
        }
    }
    return count;
}

int find_height(int mat[][MAXC], int nc, int nr, int coords[], int w){
    int row_in = coords[0], col_in = coords[1];
    int h = 1, flag; 
    
    for(int row = row_in + 1; row < nr; row++) {
        flag = 1;
        for(int col = col_in; col < col_in + w && col < nc; col++) {
            if(mat[row][col] != 1) {
                flag = 0;
                break;
            }
        }
        if(flag) {
            h++;
        } else {
            break;
        }
    }
    
    return h;
}

int core(int mat[][MAXC], int nc, int nr, int scelta){
    int count, max=0, temp_i, l=0,h=0;
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

            count=find_width(mat, nc, nr, coords,max);
            printf("Max altezza: estremo=(%d,%d), altezza=%d, larghezza=%d, area=%d\n", coords[0], coords[1], max, count, count*max);
            break;

        case 2://Larghezza
            for(int j=0; j<nr; j++){
                count = 0; 
                for(int i=0; i<nc; i++){
                    if(mat[j][i]==1){
                        temp_i = i;
                        while(mat[j][i]==1 && i<nc){
                            count++;
                            i++;
                        }
                        i--;

                        if(count>max){
                            max = count;
                            coords[0]=j;
                            coords[1]=temp_i;
                        }
                    }else count = 0;
                }
            }

            count=find_height(mat, nc, nr, coords, max);
            printf("Max larghezza: estremo=(%d,%d),altezza=%d, larghezza=%d, area=%d\n", coords[0], coords[1], count, max, max*count);
            break; 

        case 3: // Area
        int width, height, area, flag;
            for(int i = 0; i < nr; i++) {
                for(int j = 0; j < nc; j++) {
                    if(mat[i][j] == 1) {
                        l = 0;
                        h = 1;
                        while(j + l < nc && mat[i][j + l] == 1) {
                            l++;
                        }
                        
                        for(int row = i + 1; row < nr; row++) {
                            flag = 1;
                            for(int col = j; col < j + l; col++) {
                                if(mat[row][col] != 1) {
                                    flag = 0;
                                    break;
                                }
                            }
                            if(flag) h++;
                            else break;
                        }
                        
                        area = l * h;
                        if(area > max) {
                            max = area;
                            coords[0] = i;
                            coords[1] = j;
                            width = l;
                            height = h;
                        }
                        
                        j += l - 1; // -1 perché il for fa un j++ di troppo 
                    }
                }
            }
            printf("Max area: estremo=(%d,%d), altezza=%d, larghezza=%d, area=%d\n", coords[0], coords[1], height, width, max);
            break;
    }
 
    return 0;
}

