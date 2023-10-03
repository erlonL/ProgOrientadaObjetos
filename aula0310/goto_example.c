#include <stdio.h>

int main(void){
    comeco:
    int x;
    printf("Digite o valor de x: ");
    scanf("%d", &x);
    if(x < 0)
        goto comeco;
    
    printf("Valor de x: %d\n", x);
}