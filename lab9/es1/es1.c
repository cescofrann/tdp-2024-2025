#include <stdio.h>

typedef struct {
    int numero_int;
    float numero_float;
} cifrario;

int main(){

    cifrario cfr = {1, 3.3};
    cifrario *structp = &cfr;
 
    printf("Struttura: %p\n\tnumero intero: %p, \n\tnumero float: %p,\n\tpuntatore: %p\n", &cfr, &cfr.numero_int, &cfr.numero_float, structp);

    structp->numero_float = 3.56;

    printf("Nuovo float: %f, indirizzo:%p", cfr.numero_float, &structp->numero_float);
    return 0;
}