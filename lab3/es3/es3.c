#include <stdio.h>

#define NOME "numeri.txt"

int checkNumbers(int prepreprecedente, int precedente, int numero);

int main(){
    FILE *fp_read;
    int numero, pre, prepre, max, min;
    int i=0, validita = 0, n = 0;

    if((fp_read = fopen(NOME, "r")) == NULL){
        printf("Errore nella lettura del file");
        return 1;
    }

    
    while (((fscanf(fp_read,"%d", &numero)) == 1)){
        i++;
        if(i==1){
            prepre = numero;
            max = numero;
            min = numero;
        }else if(i==2){
            pre = numero;
        }else{
            validita = checkNumbers(prepre, pre, numero);
            if(validita == 1){
                prepre = pre;
                pre = numero;
                if(numero > max){
                    max = numero;
                }else if(numero < min){
                    min = numero;
                }
            }else{
                n++;
            }
        }
        
    }
    
    printf("Numero massimo: %d\n", max);
    printf("Numero minimo: %d\n", min);
    if(n>0){
        printf("Numero degli scarti: %d\n", n);
    }
    
    
    fclose(fp_read);
    return 0;
}

int checkNumbers (int preprecedente, int precedente, int numero){
    if((precedente + preprecedente) == numero){
        return 1;
    }else if((preprecedente - precedente) == numero){
        return 1;
    }else if((precedente * preprecedente) == numero){
        return 1;
    }else if(precedente != 0){
        if((preprecedente / precedente) == numero){
            return 1;
        }
    }
    
    return 0;
}