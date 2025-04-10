#include <stdlib.h>
#include <stdio.h>

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	pivot;
	int	i;
	int	j;

	pivot = tab[size / 2];
	i = 0;
	j = size - 1;
	while (i <= j)
	{
		while (tab[i] < pivot)
			i++;
		while (tab[j] > pivot)
			j--;
		if (i <= j)
		{
			swap(&tab[i], &tab[j]);
			i++;
			j--;
		}
	}
	if (j > 0)
		ft_sort_int_tab(tab, j + 1);
	if (i < size)
		ft_sort_int_tab(tab + i, size - i);
}
