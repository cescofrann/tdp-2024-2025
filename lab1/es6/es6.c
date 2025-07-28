#include <stdio.h>

int main(){
    char segno;
    float op1, op2, ris;

    FILE *fp_read, *fp_write;

    if ((fp_read = fopen("./operazioni.txt", "r")) == NULL) {
        printf("Errore durante l'apertura del file");
        return 1;
    }
    
    if ((fp_write = fopen("./risultato.txt", "w")) == NULL) {
        printf("Errore durante l'apertura del file");
        return 2;
    }

    while(!feof(fp_read)){
        segno = fgetc(fp_read);
        fscanf(fp_read, " %f %f", &op1, &op2);
        getc(fp_read); // in questo modo ignoro i caratteri \n

        // Controllo il segno perché il documento di lettura ha una struttura fissa. Il segno è sempre il primo carattere per ogni riga
        if (segno != EOF){
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
            }
            
            fprintf(fp_write, "%c %.2f\n", segno, ris);
        }
    }


    fclose(fp_read);
    fclose(fp_write);
    return 0;
}