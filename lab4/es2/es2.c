#include <stdio.h>
#include <ctype.h>
#include <string.h>

void shift(int vett[], int dim, int direzione, int q);

int main(){
    int dim, direzione, qnt;
    
    printf("Quanto dev'esser grande il vettore? ");
    scanf("%d", &dim);

    int vett[dim];
    
    for (int i=0; i<dim; i++){
        printf("dichiara un valore del vettore: ", i);
        scanf("%d", &vett[i]);
    }

    printf("Dichiara il tipo di rotazione (sx=-1 o dx=1) e la grandezza dello shift separata da uno spazio: ");
    scanf("%d %d", &direzione, &qnt);
    shift(vett, dim, direzione, qnt);

    return 0;
}

void shift(int vett[], int dim, int dir, int q){
    int temp;
    switch (dir){
        case -1:
            for(int w=0; w<q; w++){
                temp = vett[0];
                for (int l = 0; l<dim-1; l++){
                    vett[l] = vett[l+1];
                }
                vett[dim-1] = temp;
            }
            break;
        case 1:
            for(int y=0; y<q; y++){
                temp = vett[dim-1];
                for (int c=dim-1; c>1; c--){   
                    vett[c] = vett[c-1];
                }
                vett[0] = temp;
            }
            break;
        default:
        printf("Scelta invalida");
            break;
    }

    printf("Vettore ruotato: ");
    for (int p = 0; p<dim; p++){
        printf("%d ", vett[p]);
    }
}