#include <stdio.h>

int comprimi(FILE *fin, FILE *fout);
int decomprimi(FILE *fin, FILE *fout);

int main(){
    FILE *fp_read, *fp_write, *fp_dec;
    char scelta;
    
    if((fp_read = fopen("./sorgente.txt", "r")) == NULL) {
        printf("Errore di apertura del file");
        return 1;
    }
    
    if((fp_write = fopen("./compresso.txt", "w")) == NULL) {
        printf("Errore di apertura del file");
        return 2;
    }

    if((fp_dec = fopen("./decompresso.txt", "w")) == NULL) {
        printf("Errore di apertura del file");
        return 3;
    }

    printf("Scegli se comprimere (c) o decomprimere (d) il file: ");
    scanf("%c", &scelta);

    switch (scelta){
        case 'c':
            if (comprimi(fp_read, fp_write) != 0) printf("File compresso correttamente");
            else printf("Errore di compressione");
            break;
        case 'd':
            if (decomprimi(fp_read, fp_dec) != 0) printf("File decompresso correttamente");
            else printf("Errore di decompressione");
            break;
        default: 
            printf("Scegli un'alternativa tra c / d, hai inserito un carattere non accettabile");
    }


    fclose(fp_read);
    fclose(fp_write);
    fclose(fp_dec);
    return 0;
}

int comprimi(FILE *fin, FILE *fout){
    char c, successivo;
    int count = 0, n;

    c = fgetc(fin);
    while (!feof(fin)){
        successivo = fgetc(fin);
        
        if (c==successivo){
            while (c == successivo && count <9){
                count ++;
                successivo = fgetc(fin);
            }
            if(count > 1) {
                fprintf(fout, "%c$%d", c, count);
                n= n+3;
            }else {
                fprintf(fout, "%c%c", c, c);
                n = n+2;
            }
            c = successivo;
            count = 0;
        } else{
            fprintf(fout,"%c", c);
            n++;
            c = successivo;
        }
    }
    return n;   
}

int decomprimi(FILE *fin, FILE *fout){
    char c, successivo;
    int n = 0, i = 0;

    c = fgetc(fin);
    successivo = fgetc(fin);
    while (!feof(fin)){
        if (successivo != '$') {
            fprintf(fout, "%c%c", c, successivo);
            n = n+2;
        } else {
            fprintf(fout, "%c", c);
            for (i = 0; i < (successivo = fgetc(fin)); i++){
                fprintf(fout, "%c", c);
            }
            n = n + i + 1;
        }
        c = fgetc(fin);
        successivo = fgetc(fin);
    }
    fprintf(fout, "%c", c);
    return n;
}