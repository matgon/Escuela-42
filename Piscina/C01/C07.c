#include <stdlib.h>
#include <stdio.h>

void ft_rev_int_tab(int *tab, int size) {
    int temp, i;
    for (i = 0; i < size / 2; i++) {
        temp = tab[i];
        tab[i] = tab[size - 1 - i];
        tab[size - 1 - i] = temp;
    }
}

int main(){
    int intArr[] = {1, 2, 3, 4, 5, 6};
    ft_rev_int_tab(intArr, 6);
    for (size_t i = 0; i < 6; i++) printf("%d\n", intArr[i]);
}