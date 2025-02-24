#include <stdlib.h>
#include <stdio.h>

void ft_rev_int_tab(int *tab, int size) {
    int temp, i;

    i = 0;
    while(i < size / 2)
    {        
        temp = tab[i];
        tab[i] = tab[size - 1 - i];
        tab[size - 1 - i] = temp;
        i++;
    }
}

int main(){
    int intArr[] = {1, 2, 3, 4, 5, 6};
    ft_rev_int_tab(intArr, 6);
    for (size_t i = 0; i < 6; i++) printf("%d\n", intArr[i]);
}
