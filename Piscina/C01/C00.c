#include <stdio.h>
#include <stdlib.h>

void ft_ft(int *nbr){
    *nbr = 42;
}

int main(){
    int *ptr = (int*) malloc(sizeof(int));

    ft_ft(ptr);
    printf("%d\n", *ptr);

    free(ptr);

    return 0;
}