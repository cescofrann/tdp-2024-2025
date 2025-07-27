#include <stdio.h>

int main(){
    FILE *fp_read, *fp_write_odd, *fp_write_even;
    char file_string[100], name[20];
    int counter = 0;
    
    if((fp_read = fopen("./Bronte.txt", "r")) == NULL){
        printf("Errore durante l'apertura del file");
        return 1;
    }

    if((fp_write_odd = fopen("./output_odd.txt", "w")) == NULL){
        printf("Errore nell'apertura del file");
        return 2;
    }

    if((fp_write_even = fopen("./output_even.txt", "w")) == NULL){
        printf("Errore nell'apertura del file");
        return 3;
    }

    printf("Come ti chiami? ");
    gets(name);

    while(!feof(fp_read)){
        counter++;
        if (counter%2==0){
            fscanf(fp_read, "%s", file_string);
            if(!feof(fp_read)){
                printf("%s\nSto leggendo:\n%s\n\n", name, file_string);
                fprintf(fp_write_even, "%s", file_string);
            }
        } else {
            fgets(file_string, 100, fp_read);
            if (!feof(fp_read)){
                puts(name);
                puts("Sto leggendo: ");
                puts(file_string);
                fputs(file_string,fp_write_odd);
            }
        }
    }

    fclose(fp_read);
    fclose(fp_write_odd);
    fclose(fp_write_even);

    return 0;    
}