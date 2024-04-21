#include <stdio.h>
#include <stdlib.h>

int visinaDrevesa(int n, int *a, int *b, int vozlisce){

    if(vozlisce < 0 || vozlisce >= n){
        return 0;
    }
    if(a[vozlisce] == 0 && b[vozlisce] == 0){
        return 1;
    }

    int novaIndex = a[vozlisce] + vozlisce;
    int novbIndex = b[vozlisce] + vozlisce;

    if(a[vozlisce] == 0){
        return 1 + visinaDrevesa(n, a, b, b[novbIndex]);
    }
    if(b[vozlisce] == 0){
        return 1 + visinaDrevesa(n, a, b, a[novaIndex]);
    }
    
    int vejaA = 1 + visinaDrevesa(n, a, b, a[novaIndex]);
    int vejaB = 1 + visinaDrevesa(n, a, b, b[novbIndex]);

    if(vejaA > vejaB) ? vejaA : vejaB;
}

int main(){
    
    int n = 0;
    scanf("%d", &n);
    
    int *a = calloc(n, sizeof(int));
    int *b = calloc(n, sizeof(int));

    for(int i = 0; i < n; i++){
        scanf("%d %d", &a[i], &b[i]);
    }

    printf("%d\n", visinaDrevesa(n, a, b, 0));

    free(a);
    free(b);
    return 0;
}