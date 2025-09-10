#include <stdio.h>

#define MAXC 10

void selection_sort(int vet[], int n1);
void display_vet(int vet[], int n1);
void clone_vet(int vet[], int vet2[], int n1);
void insertion_sort(int vet[], int n1);
void shell_sort(int vet[], int n1);


int main(){
    FILE *fp_read;
    int n=0, n1=0, i;
    int vet[MAXC], vet2[MAXC];
    
    if((fp_read = fopen("sort.txt", "r")) == NULL){
        printf("Errore nell'apertura del file");
        return 1;
    }
    
    fscanf(fp_read, "%d", &n);

    for(int j=0; j<n; j++){
        fscanf(fp_read, "%d", &n1);
        for(int i=0; i<n1; i++){
            fscanf(fp_read, "%d ", &vet[i]);
        }
        clone_vet(vet, vet2, n1);
        shell_sort(vet, n1);
        clone_vet(vet, vet2, n1);
        selection_sort(vet2, n1);
        clone_vet(vet, vet2, n1);
        insertion_sort(vet, n1);
    }


    


    
    fclose(fp_read);
    return 0;
}

void selection_sort(int vet[], int n1){
    int n_scambi=0, n_ext=0, n_int=0;
      
    int l=0, r=n1-1, i, j, max;
    int temp;
    for(i=l; i<r; i++){
        n_ext++;
        n_int =0;
        max = i;
        for(j=i+1; j<=r; j++){
            n_int++;
            if(vet[j] > vet[max]){
                max = j;
            }
        }
        if(max!=i){
            temp=vet[i];
            vet[i]=vet[max];
            vet[max]=temp;
            n_scambi++;
        }
    }
    
    printf("Selection sort:\n\tNumero scambi: %d, numero iterazioni ciclo ext: %d, numero iterazioni ciclo int: %d\n", n_scambi, n_ext, n_int);
    display_vet(vet, n1);
}

void insertion_sort(int vet[], int n1){
    int n_scambi=0, n_ext=0, n_int=0;

    int l=0, r=n1-1, i, j, x;
    for(i=l+1; i<=r; i++){
        n_ext++;
        n_int=0;
        x = vet[i];
        j = i-1;
        while(j>=l && x>vet[j]){
            vet[j+1] = vet[j];
            j--;
            n_scambi++;
            n_int++;
        }
        vet[j+1] = x;
    }
    
    printf("Inestion sort:\n\tNumero scambi: %d, numero iterazioni ciclo ext: %d, numero iterazioni ciclo int: %d\n", n_scambi, n_ext, n_int);
    display_vet(vet, n1);
}

void shell_sort(int vet[], int n1){
    int n_scambi=0, n_ext=0, n_int=0;

    int i, j, x, l=1, r=n1-1, h=l;
    while(h<=n1/3)
    h=3*h+1;
    while(h >= l){
        for(i=l + h; i<=r; i++){
            j=i;
            x=vet[i];
            while(j>=l+h && x<vet[j-h]){
                vet[j]=vet[j-h];
                j-=h;
                n_scambi++;
            }
            vet[j]=x;
        }
        h=h/3;
    }
    
    printf("Shell sort:\n\tNumero scambi: %d, numero iterazioni ciclo ext: %d, numero iterazioni ciclo int: %d\n", n_scambi, n_ext, n_int);
    display_vet(vet, n1);
}

void display_vet(int vet[], int n1){
   
    for(int j=0; j<n1; j++){
        printf("%d ", vet[j]);
    }
    printf("\n");
    
}


void clone_vet(int vet[], int vet2[], int n1){
    for(int j=0; j<n1; j++){
        vet2[j] = vet[j];
    }
}