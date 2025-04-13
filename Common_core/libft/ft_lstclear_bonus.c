/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 22:38:44 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/13 12:05:07 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Elimina y libera el nodo ’lst’ dado y todos los
/// consecutivos de ese nodo, utilizando la función
/// ’del’ y free(3).
/// Al final, el puntero a la lista debe ser NULL.
/// @param lst: la dirección de un puntero a un nodo. 
/// @param del: un puntero a función utilizado para eliminar
///el contenido de un nodo. 
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux1;
	t_list	*aux2;

	aux1 = *lst;
	while (aux1 != NULL)
	{
		aux2 = aux1->next;
		ft_lstdelone(aux1, del);
		aux1 = aux2;
	}
	*lst = NULL;
}
