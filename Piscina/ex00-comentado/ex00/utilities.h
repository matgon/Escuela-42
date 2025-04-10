/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgon <matgon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 20:53:10 by matgonza          #+#    #+#             */
/*   Updated: 2025/03/10 21:57:15 by matgon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 4096 //tamanio maximo de nuestro buffer (donde guardaremos cada linea del diccionario)

typedef struct s_node //estructura donde se guardara toda la info de cada linea del archivo del diccionario
{
	int		num_digits;
	char	*name;
	char	*num;
}	t_node;

typedef struct s_process_hundreds //encapsulacion de variables por la norminette (ni caso)
{
	char			*nbr;
	int				i;
	int				*eleven_flag;
	char			*h;
	const t_node	*dict;
}	t_process_hundreds;

//definicion de funciones para que todos los archivos conozcan sobre la existencia de estas y no den error.
char	*recursion(char *nbr, const t_node *dict);
char	*create_chain(char *nbr, int pos, const t_node *dict);
void	process_hundreds(t_process_hundreds params, char **ret);
void	append_to_result(char **ret, char *str, int free_ret);
char	*srch_n(char *nbr, int digits, const t_node *dict);
void	process_line(char *line, t_node *node);
void	set_vars(int *inx);
t_node	*load_dict(const char *filename, int *size);
int		is_imprimible(char c);
int		count_digits(const char *str);
int		count_file_lines(const char *filename);
int		ft_is_number(char c);
void	put_str(char *str);
int		ft_strncmp(const char *str1, const char *str2, int n);
char	*ft_strcat(const char *str1, const char *str2);
char	*ft_strncpy(char *dest, const char *src, int n);
int		ft_strlen(char *str);
void	init_h_and_i(char hundreds[3], int indexes[2], int *eleven_flag);
int		all_zeros(char *str);
