#include <stdio.h>

int main(){
    char segno;
    float op1, op2, ris;
    printf("Scrivi il segno dell'operazione ");
    segno  = getchar();

    printf("Scrivi i due operatori separati da uno spazio: ");
    scanf(" %f %f", &op1, &op2);

    switch (segno){
        case '+':
            ris = op1 + op2;
            break;
        case '-':
            ris = op1 - op2;
            break;
        case '/':
            ris = op1 / op2;
            break;
        case '*':
            ris = op1 * op2;
            break;
        default: 
            printf("Errore di scelta");
            break;
    }

    printf("%c %2.f", segno, ris);
}