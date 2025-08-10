#include <stdio.h>

int main(){
    int num1, num2, resto = 1, maggiore, minore;

    printf("Scrivi due interi positivi separati dallo spazio e ti dirò il loro mcm: ");
    scanf("%d %d", &num1, &num2);
    
    if (num1 < 0 || num2<0){
        printf("Errore di diciarazione");
        return 1;
    }

    if (num2 > num1) {
        maggiore = num2;
        minore = num1;
    }else{
        maggiore = num1;
        minore = num2;
    }

    while(resto != 0){
        resto = maggiore % minore;
        maggiore = minore;
        minore = resto;
    }

    printf("Il massimo comun divisore è: %d", maggiore);

    
    return 0;
}