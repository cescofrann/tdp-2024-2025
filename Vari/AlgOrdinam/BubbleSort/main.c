#include <stdio.h>

void BubbleSort(int vettore[], int N);
void OptBubbleSort(int vettore[], int N);

int main(){
    int vettore[] = {3,2,1,5,0};
    BubbleSort(vettore, 5);
    // OptBubbleSort(vettore, 5);
    for(int v = 0; v<5; v++){
        printf("%d ", vettore[v]);
    }

    return 0;
}

void BubbleSort(int vettore[], int N){
    int i, j, l=0, r=N-1;
    int temp;
    
    for(i=l; i<r; i++){
        for(j=l; j<r-i+l; j++){
            if(vettore[j] > vettore[j+1]){
                temp = vettore[j+1];
                vettore[j+1] = vettore[j];
                vettore[j] = temp;
            }
        }
    }
    return;
}


void OptBubbleSort(int vettore[], int N){
    int i, j, l=0, r=N-1;
    int temp;
    int flag = 1;

    for(i=l; i<r && flag == 1; i++){
        flag = 0; // L'utilizzo di questo flag permette di ridurre la complessità di caso medio, quella di caso peggiore è invariata.
        for (j=l; j<r-i+l;j++){
            if(vettore[j] > vettore[j+1]){
                temp = vettore[j+1];
                vettore[j+1] = vettore[j];
                vettore[j] = temp;
                flag = 1; // Se non vengono effetturati cambi vuol dire che il vettore è già ordinato e sarebbe superfluo continuare.
            }
        }
    }

}