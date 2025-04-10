#include "utilities.h"

//si el numero que me dan son todo ceros, devuelve 1, si no 0.
int all_zeros(char *str)
{
	int	i;

	i = 0;
	while(str[i]){
		if (str[i] != '0')
			return 0;
		i++;
	}
	return (1);
}
