/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:56:32 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/13 10:33:19 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Crea un nuevo nodo utilizando malloc(3). La
/// variable miembro ’content’ se inicializa con el
/// contenido del parámetro ’content’. La variable
/// ’next’, con NULL.
/// @param content: el contenido con el que crear el nodo.
/// @return El nuevo nodo
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *) malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	if (!content)
		new->content = NULL;
	else
		new->content = content;
	new->next = NULL;
	return (new);
}
