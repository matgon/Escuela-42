#include <stdio.h>
#include <unistd.h>

typedef struct s_data 
{
    const int views[2][4][2];
    int matrix[4][4];
} t_data;

int	check_unique(t_data *data, const int row, const int col, int num)
{
	int	i;
	int	j;
	int ret;

	i = 0;
	j = 0;
	ret = 1;
	while (i < 4 && ret)
	{
		if (col != i)
			if(data->matrix[row][i] == num)
				ret = 0;
		i++;
	}
	while (j < 4 && ret)
	{
		if (row != j)
			if(data->matrix[j][col] == num)
				ret = 0;
		j++;
	}
	return (ret);
}

int check_views_row(t_data *data, const int row)
{
    int i;
    int j;
    int max_l;
    int max_r;
    int cont_l;
    int cont_r;
	int ret;

	ret = 1;
    max_l = 0;
    max_r = 0;
    i = 0;
    j = 3;
    cont_l = data->views[1][row][0];
    cont_r = data->views[1][row][1];
    while (i < 4 && j >= 0){
        if (data->matrix[row][i] > max_l)
		{
			max_l = data->matrix[row][i];
			cont_l--;
		}
		if (data->matrix[row][j] > max_r)
		{
			max_r = data->matrix[row][j];
			cont_r--;
		}
		i++;
		j--;
    }
	if (cont_l < 0 || cont_r < 0)
		ret = 0;
	if (cont_l == 0 && cont_r == 0)
		ret = -1;
	return (ret);
}

int check_views_col(t_data *data, const int col)
{
    int i;
    int j;
    int max_u;
    int max_d;
    int cont_u;
    int cont_d;
	int ret;

	ret = 1;
    max_u = 0;
    max_d = 0;
    i = 0;
    j = 3;
    cont_u = data->views[0][col][0];
    cont_d = data->views[0][col][1];
    while (i < 4 && j >= 0){
        if (data->matrix[i][col] > max_u)
		{
			max_u = data->matrix[i][col];
			cont_u--;
		}
		if (data->matrix[j][col] > max_d)
		{
			max_d = data->matrix[j][col];
			cont_d--;
		}
		i++;
		j--;
    }
	if (cont_u < 0 || cont_d < 0)
		ret = 0;
	if (cont_u == 0 && cont_d == 0)
		ret = -1;
	return (ret);
}

int	check_all_views(t_data *data)
{
	int	i;
	int j;
	int ret;

	i = 0;
	ret = 1;
	while(i < 4 && ret)
	{
		if (!check_views_row(data, i) || !check_views_col(data, i))
			ret = 0;
		i++;
	}
	i = 0;
	while (i < 4 && ret)
	{
		j = 0;
		while (j < 4 && ret)
		{
			if (!check_unique(data, i, j, data->matrix[i][j]))
				ret = 0;
			j++;
		}
		i++;
	}
	return ret;
}

int backtrack(t_data *data, int row, int col)
{
	int	i;

	i = 1;
    if (row == 4)
		if (!check_all_views(data))
			return (0);
		else return (1);
	if (col == 4)
		if (check_views_row(data, row) != -1)
			return 0;
		else return backtrack(data, row + 1, 0);
	while (i <= 4)
	{
		data->matrix[row][col] = i;
		// if (check_views_row(data, row) && check_views_col(data, col) && check_unique(data, row, col, i))
		if (backtrack(data, row, col + 1))
			return (1);
		data->matrix[row][col] = 0;
		i++;
	}
	return (0);
}

void	print_matrix(const int matrix[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			write(1, &(char){matrix[i][j] + '0'}, sizeof(char));
			j++;
		}
		write(1, "\n", sizeof(char));
		i++;
	}
}

int main(int argc, char *argv[]){

    t_data  data = {.views = {{{4,1},{3,2},{2,2},{1,2}}, 
                            {{4,1},{3,2},{2,2},{1,2}}},
                    .matrix = {0}};
	if (backtrack(&data, 0, 0))
		print_matrix(data.matrix);
	else
		write(1,"ERROR: No hay solucion...\n", sizeof(char) * 26);
}