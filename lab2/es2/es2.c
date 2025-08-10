#include <stdio.h>

int main(){
    int n, a = 0, b=1, ris = a+b;

    printf("Dichiara il numero di numeri per la successione di Fibonacci ");
    scanf("%d", &n);


    if(n>= 2){
        printf("%d %d ", a, b);
        for (int i = 0; i < n; i++){
            ris = a+b;
            a = b;
            b = ris;
            printf("%d ", ris);

        }

        // variante definita dalla dall'esercizio
        
        // unsigned int a_ = 1;
        // unsigned int b_ = 2;
        // unsigned int ris_ = a+b;

        // printf("%d %d ", a_, b_);
       
        // for (int i = 0; i < n; i++){
        //     ris_ = a_*b_;
        //     a_ = b_;
        //     b_ = ris_;
        //     printf("%d ", ris_);

        // }

        // Risposta: con questa variante si possono calcolare 9 iterazioni con variabili unsigned int mentre si può iterare 45 volte con base int prima che il calcolatore utilizzerà numeri negativi (irrealistici).
    }else if(n==1){
        printf("0");
    }else{
        printf("Numero non accettabile");
        return 1;
    }
    return 0;
}