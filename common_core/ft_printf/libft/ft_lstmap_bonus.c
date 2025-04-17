/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 22:58:56 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/13 12:14:57 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Itera la lista ’lst’ y aplica la función ’f’ al
/// contenido de cada nodo. Crea una lista resultante
/// de la aplicación correcta y sucesiva de la función
/// ’f’ sobre cada nodo. La función ’del’ se utiliza
/// para eliminar el contenido de un nodo, si hace
/// falta.
/// @param lst: un puntero a un nodo.
/// @param f: la dirección de un puntero a una función usada
///en la iteración de cada elemento de la lista.
/// @param del: un puntero a función utilizado para eliminar
///el contenido de un nodo, si es necesario. 
/// @return La nueva lista.
///NULL si falla la reserva de memoria.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*aux;
	void	*f_ret;

	ret = NULL;
	while (lst != NULL)
	{
		f_ret = f(lst->content);
		if (!f_ret)
		{
			ft_lstclear(&ret, del);
			return (NULL);
		}
		aux = ft_lstnew(f_ret);
		if (!aux)
		{
			del(f_ret);
			ft_lstclear(&ret, del);
			return (NULL);
		}
		ft_lstadd_back(&ret, aux);
		lst = lst->next;
	}
	return (ret);
}
