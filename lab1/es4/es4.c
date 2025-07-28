#include <stdio.h>

#define P 3.14

int main(){
    char choice, q_route;
    int dim;
    float area;

    printf("Calcolo l'area del cerchio (C) o del quadrato (Q)? ");
    scanf("%c", &choice);

    switch (choice){
        case 'Q':
            printf("Calcolo dell'area tramite diagonale (D) o lato (L)? Specifica anche la relativa lunghezza senza spazi ");
            scanf(" %c%d", &q_route, &dim);

            if(q_route == 'L'){
                area = dim*dim;
            }else if (q_route == 'D'){
                area = dim*dim/2.0;
            }else{
                printf("Erroe di scelta");
            }
            printf("L'area del quadrato è: %.2f", area);
            break;

        case 'C':
            printf("Calcolo dell'area tramite diametro (D) o raggio (R)? Specifica anche la relativa lunghezza senza spazi ");
            scanf(" %c%d", &q_route, &dim);

            if (q_route == 'R'){
                area = P*dim*dim;
            }else if(q_route == 'D'){
                dim = dim/2;
                area = P*dim*dim;
            }
            else{
                printf("Erroe di scelta");
            }
            printf("L'area del cerchio è: %.2f", area);
            break;
        default:
            printf("Errore durante la scelta");
            break;
    }
}