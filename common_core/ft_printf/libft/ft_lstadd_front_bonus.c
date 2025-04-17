/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 22:16:42 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/12 22:24:43 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Añade el nodo ’new’ al principio de la lista ’lst’.
/// @param lst: la dirección de un puntero al primer nodo de una lista. 
/// @param new: un puntero al nodo que añadir al principio de la lista.
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = lst[0];
	lst[0] = new;
	new->next = temp;
}
