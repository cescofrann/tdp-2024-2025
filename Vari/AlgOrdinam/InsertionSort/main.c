#include <stdio.h>

void insertionSort(int vettore[], int N);

int main(){
    int vettore[5]={4,3,2,1,0};
    insertionSort(vettore, 5);
    
    for(int u=0; u<5; u++){
        printf("%d ", vettore[u]);
    }
    return 0;
}

void insertionSort(int vettore[], int N){
    int l=0, r=N-1, i, j, x;
    for (i=l+1; i<= r; i++){
        x = vettore[i]; // valore da ordinare
        j = i-1; // indice del numero più grande del sottovettore ordinato
        while(j>=l && x < vettore[j]){
            vettore[j+1] = vettore[j];
            j--;
        }
        vettore[j+1] = x;
    }

    return;
}