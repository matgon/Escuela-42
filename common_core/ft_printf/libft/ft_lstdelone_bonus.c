/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 22:36:18 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/12 23:02:54 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Toma como parámetro un nodo ’lst’ y libera la
/// memoria del contenido utilizando la función ’del’
/// dada como parámetro, además de liberar el nodo. La
/// memoria de ’next’ no debe liberarse.
/// @param lst: el nodo a liberar.
/// @param del: un puntero a la función utilizada para liberar
///el contenido del nodo.
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}
