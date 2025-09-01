#include <stdio.h>
#define nfile "partita0.txt"

void playcore(char mat[][19]);
int checkwin(char mat[][19]);
void printBoard(char mat[][19]);


int main(){
    FILE *fp_read;
    char mat[19][19];
    int s = 0;
    char c;

    if((fp_read = fopen(nfile, "r")) == NULL){
        printf("Errore nella lettura del file");
        return 1;
    }else{
        printf("File caricato!\n");
    }

    for(int m = 0; m<19; m++){
        for (int l = 0; l<19; l++){
            if((c = fgetc(fp_read)) == '\n') fscanf(fp_read, "%c", &mat[m][l]);
            else mat[m][l] = c;
        }
    }
    playcore(mat);
    
    fclose(fp_read);
    return 0;
}

void playcore(char mat[][19]){
    int riga, colonna;
    int flag = 0, player = 0; // 0 nero, 1 bianco
    
    while(!flag){
        printBoard(mat);
        if(player){
            printf("Inserire la mossa del nero <riga> <colonna> ");
            if((scanf("%d %d", &riga, &colonna)) == 1){
                getchar();
            }
        }else{
            printf("Inserire la mossa del bianco <riga> <colonna> ");
            if((scanf("%d %d", &riga, &colonna)) == 1){
                getchar();
            }
        }

        if(riga>19 || colonna > 19 || riga < 0 || colonna < 0) printf("Mossa non valida: casella inesistente\n");
        else if(mat[riga][colonna] == '.'){
            if(player == 0){
                mat[riga][colonna] = 'B';
                player = 1;
                flag = checkwin(mat);
                if(flag) {
                    printf("Il bianco ha vinto\n");
                    printBoard(mat);
                }
            }else{
                mat[riga][colonna] = 'N';
                player = 0;
                flag = checkwin(mat);
                if(flag) {
                    printf("Il nero ha vinto\n");
                    printBoard(mat);
                }
            }
        }else{
            printf("Mossa non valida: casella gia occupata\n");
        }

    }
    
}

int checkwin(char mat[][19]){
    int j=0,c=0;
    
    for(int i = 0; i<19; i++){
        while(j<18){
            if(mat[i][j]==mat[i][j+1] && (mat[i][j] == 'B' || mat[i][j] == 'N')){
                c++;
                if(c==4) return 1;
            }else{
                c=0;
            }
            j++;
        }
        j=0;
    }

    c = 0;
    for(int k=0;k<19;k++){
        for(int e=0; e<18; e++){
            if(mat[e][k]==mat[e+1][k] && (mat[e][k] == 'B' || mat[e][k] == 'N')){
                c++;
                if (c== 4) return 1;
            }else{
                c=0;
            }
        }
    }

    for(int col = 0; col <= 14; col++){
        c = 0;
        for(int i = 0, j = col; i < 18 && j < 18; i++, j++){
            if(mat[i][j] == mat[i+1][j+1]&& (mat[i][j] == 'B' || mat[i][j] == 'N')){
                c++;
                if(c == 4) return 1;
            } else {
                c = 0;
            }
        }
    }

    for(int rig = 1; rig <= 14; rig++){
        c = 0;
        for(int i = rig, j = 0; i < 18 && j < 18; i++, j++){
            if(mat[i][j] == mat[i+1][j+1]&& (mat[i][j] == 'B' || mat[i][j] == 'N')){
                c++;
                if(c == 4) return 1;
            } else {
                c = 0;
            }
        }
    }

    for(int colonna = 4; colonna < 19; colonna++){
        c = 0;
        for(int i = 0, j = colonna; i < 18 && j > 0; i++, j--){
            if(mat[i][j] == mat[i+1][j-1]&& (mat[i][j] == 'B' || mat[i][j] == 'N')){
                c++;
                if(c == 4) return 1;
            } else {
                c = 0;
            }
        }
    }

        for(int riga = 1; riga <= 14; riga++){
        c = 0;
        for(int i = riga, j = 18; i < 18 && j > 0; i++, j--){
            if(mat[i][j] == mat[i+1][j-1]&& (mat[i][j] == 'B' || mat[i][j] == 'N')){
                c++;
                if(c == 4) return 1;
            } else {
                c = 0;
            }
        }
    }
    
    return 0;
}
void printBoard(char mat[][19]){
    printf("\n   ");
    for(int i = 0; i < 19; i++){
        printf("%2d ", i);
    }
    printf("\n");
   
    for(int i = 0; i < 19; i++){
        printf("%2d ", i);
        for(int j = 0; j < 19; j++){
            printf(" %c ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}