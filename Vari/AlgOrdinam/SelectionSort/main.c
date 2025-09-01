#include <stdio.h>

void SelectionSort(int vettore[], int N);

int main(){
    int vettore[] = {1,2,4,3,6};
    SelectionSort(vettore, 5);
    
    for(int v = 0; v<5; v++){
        printf("%d ", vettore[v]);
    }
    return 0;
}

void SelectionSort(int vettore[], int N){
    int i, j, l=0, r= N-1, min;
    int temp;

    for(i = l; i < r; i++){
        min = i;
        for(j=i+1; j <= r; j++){
            if(vettore[j] < vettore[min]){
                min = j;
            }
        }
        if (min != i){
            temp = vettore[i];
            vettore[i] = vettore[min];
            vettore[min] = temp;
        }
    }
    return;
}