#include <stdio.h>
#include <stdlib.h>

void ft_ultimate_div_mod(int *a, int *b){
    int tmp = *a;
    *a = tmp / *b;
    *b = tmp % *b;
}

int main(){
    int a = 5;
    int b = 2;
    ft_ultimate_div_mod(&a, &b);

    printf("a: %d, b: %d\n", a, b);
}