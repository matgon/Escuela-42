/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgon <matgon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 20:54:40 by matgonza          #+#    #+#             */
/*   Updated: 2025/03/10 22:08:43 by matgon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

//funcion para inicializacion de una estructura t_process_hundreds (encapsula variables para que no haya errores de la norminette)
t_process_hundreds	init_p(char *nbr, int indexes[2], char hundreds[3],
			const t_node *dict)
{
	t_process_hundreds	p;

	p.dict = dict;
	p.h = hundreds;
	p.i = indexes[0];
	p.nbr = nbr;
	return (p);
}

//concatena el string str a ret y gestiona la memoria para que no haya leaks.
void	append_to_result(char **ret, char *str, int free_ret)
{
	char	*temp;

	temp = ft_strcat(*ret, str);
	if (*ret && free_ret)
		free(*ret);
	*ret = ft_strcat(temp, " ");
	free(temp);
}

//procesa los numeros (tuve que haberla llamado process_numbers pero bueno...)
//voy a comentar dentro de la funcion para que sea mas claro.
void	process_hundreds(t_process_hundreds p, char **ret)
{
	if (p.nbr[p.i] != '0') //solamente hago cosas si el digito en el que estoy es diferente a 0
	{
		p.h[p.i] = p.nbr[p.i];
		if (p.i == 0) //si p.i es 0 significa que estoy en el primer digito de los tres
		{
			append_to_result(ret, srch_n(&p.h[p.i], 1, p.dict), 1); //pongo el numero
			p.h[p.i] = '1';
			append_to_result(ret, srch_n("100", 3, p.dict), 1); //pongo el hundred
		}
		else if (p.i == 1) //si p.i es 1 significa que estoy en el segudno digito de los tres
		{
			if (p.nbr[p.i] == '1') //si el segundo digito es igual a 1, significa que tengo que poner once, doce... son casos especiales
			{
				*p.eleven_flag = 1;//eleven_flag significa que no tengo que poner nada en el tercer numero ya que no puedo poner "once uno"
				p.h[p.i + 1] = p.nbr[p.i + 1];
				append_to_result(ret, srch_n(&p.h[p.i], 2, p.dict), 1);
			}
			else //si no es 1, trato el numero de forma normal, si es un 2 es veinte, 3 treinta...
				append_to_result(ret, srch_n(&p.h[p.i], 2, p.dict), 1);
		}
		else if (p.i == 2 && !(*p.eleven_flag)) //si estoy en el ultimo numero y no he puesto un once por ejemplo, pongo el numero normal
			append_to_result(ret, srch_n(&p.h[p.i], 1, p.dict), 1);
	}
}

//crea la cadena de caracteres de los tres numeros. EJ: 432 = four hundred thirty two.
//solamente cuando los tres numeros sean diferentes de 0.
//tengo que crear la estructura t_process_hundreds para no tener tantas variables por la norminette (y lineas)
char	*create_chain(char *nbr, int pos, const t_node *dict)
{
	int					indexes[3];
	char				*buffs[2];
	char				hundreds[3];
	t_process_hundreds	p;

	buffs[0] = ft_strcat("", "");
	init_h_and_i(hundreds, indexes, &indexes[2]);
	buffs[1] = (char *)malloc(sizeof(char) * pos);
	while (indexes[0] < 3)
	{
		p = init_p(nbr, indexes, hundreds, dict);
		p.eleven_flag = &indexes[2];
		process_hundreds(p, &buffs[0]);
		if (indexes[0] == 2 && pos > 3)
		{
			while (indexes[1] < pos)
				buffs[1][indexes[1]++] = '0';
			buffs[1][0] = '1';
			if (nbr[0] != '0' || nbr[1] != '0' || nbr[2] != '0')
				append_to_result(&buffs[0], srch_n(buffs[1], pos - 2, dict), 1);
		}
		indexes[0]++;
	}
	free(buffs[1]);
	return (buffs[0]);
}

//funcion de recursion. Va a tratar los digitos de tres en tres ya que tengo que ver cuando poner hundred y los demas (thousands, millions...)
char	*recursion(char *nbr, const t_node *dict)
{
	static int	pos;
	char		*str;
	char		*ret;
	char		*testing;

	if (*nbr)
	{
		str = recursion(nbr + 1, dict);
		pos++;
		if (pos % 3 == 0)
		{
			testing = create_chain(nbr, pos, dict);
			ret = ft_strcat(testing, str);
			free(testing);
			if (*str)
				free(str);
			return (ret);
		}
		return (str);
	}
	return ("");
}
