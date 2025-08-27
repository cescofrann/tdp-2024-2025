#include <stdio.h>
#define N 10

void sottoSequenze(int v[]);

int main(){
    int vett[N];
    for(int i = 0; i<N; i++ ){
        printf("Dichiara un numero o digita: ");
        scanf("%d", &vett[i]);
    } 

    sottoSequenze(vett);

    return 0;
}

void sottoSequenze(int v[]){
    int sequenze[N];
    int c=0, i = 0, maxl = 0;


    while(i <N){
        if(v[i] != 0){
            sequenze[c] = i;
            while(v[i] != 0 && i<N){
                i++;
            }
            if(i - sequenze[c] == maxl || maxl==0){
                maxl = i-sequenze[c];
                sequenze[++c] = i-1;
                c++;
                if(i==N){
                    sequenze[c]=i;
                    c++;
                }
            }else if(i - sequenze[c] > maxl && maxl!=0){
                maxl = i-sequenze[c];
                sequenze[0] = sequenze[c];
                c=0;
                sequenze[++c] = i-1;
                if(i!=N) c++;
            }
        }else{
            i++;
        }
    }

    for(int b=0; b<c; b=b+2){
        for(int t=sequenze[b]; t<= sequenze[b+1]; t++){
            printf("%d ", v[t]);
        }
        printf("\n");
    }
    
}
