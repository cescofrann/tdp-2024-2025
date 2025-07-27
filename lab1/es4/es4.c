#include <stdio.h>

int main(){
    char choice, q_route;
    int dim;
    float area;

    printf("Calcolo l'area del cerchio (C) o del quadrato (Q)? ");
    scanf("%c", &choice);

    switch (choice){
        case 'Q':
            printf("Calcolo dell'area tramite diagonale (D) o lato (L)? ");
            scanf(" %c", &q_route);
            
            printf("Lunghezza: ");
            scanf(" %d", &dim);

            if(q_route == 'L'){
                area = dim*dim;
            }else if (q_route == 'D'){
                area = dim*dim/2.0;
            }
            printf("L'area del quadrato è %.2f", area);
            break;

        case 'C':
            break;
    }
}