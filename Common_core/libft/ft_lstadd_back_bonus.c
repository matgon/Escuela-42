/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 22:31:26 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/13 10:39:46 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Añade el nodo ’new’ al final de la lista ’lst’.
/// @param lst: el puntero al primer nodo de una lista. 
/// @param new: el puntero a un nodo que añadir a la lista.
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = ft_lstlast(*lst);
	if (last == NULL)
		*lst = new;
	else
		last->next = new;
}
