#include <stdlib.h>
#include <stdio.h>

void ft_sort_int_tab(int *tab, int size) {
    if (size <= 1) return;
    
    int pivot = tab[size / 2];
    int i = 0, j = size - 1;

    while (i <= j) {
        while (tab[i] < pivot) i++;
        while (tab[j] > pivot) j--;

        if (i <= j) {
            int temp = tab[i];
            tab[i] = tab[j];
            tab[j] = temp;
            i++;
            j--;
        }
    }

    if (j > 0) ft_sort_int_tab(tab, j + 1);
    if (i < size) ft_sort_int_tab(tab + i, size - i);
}

int main(){
    int intArr[] = {3,2,4,5,6};
    ft_sort_int_tab(intArr, 5);
    for (size_t i = 0; i < 5; i++) printf("%d\n", intArr[i]);
}