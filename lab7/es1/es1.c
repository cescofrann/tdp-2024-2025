#include <stdio.h>

#define MAXC 50
#define MAXR 50

void leggi_mat(FILE *fin, int mat[][MAXC], int nc, int nr);
void display_mat(int mat[][MAXC], int nc, int nr);
int core(int mat[][MAXC], int nc, int nr, int scelta);
int find_width(int mat[][MAXC], int nc, int nr, int coords[], int h);

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
    core(matrice, nc, nr, 2);
    core(matrice, nc, nr, 3);

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
    int l,flag=0,k=0, count;

    l=coords[1];
    count=1;
    while(l>0 && mat[coords[0]][l]==1 && !flag){            
        for(k=coords[0]; k<w && mat[k][coords[1]] == 1; k++);

        if(k==w){
            l--;
            count++;
        }else {
            flag=1;
        }
    }

    l=coords[1];
    while(l<nr && mat[coords[0]][l] == 1 && !flag){
        for(k=coords[0]; k<w && mat[k][coords[1]]==1; k++);

        if(k==w){
            l++;
            count++;
        }else{
            flag=1;
        }
    }
    return count;
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

