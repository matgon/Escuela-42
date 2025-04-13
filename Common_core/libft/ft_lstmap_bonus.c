/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 22:58:56 by matgonza          #+#    #+#             */
/*   Updated: 2025/04/13 11:51:54 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// t_list	*ft_lstnew(void *content)
// {
// 	t_list	*new;

// 	new = (t_list *) malloc(sizeof(t_list));
// 	if (!new)
// 		return (NULL);
// 	if (!content)
// 		new->content = NULL;
// 	else
// 		new->content = content;
// 	new->next = NULL;
// 	return (new);
// }

// void	ft_lstdelone(t_list *lst, void (*del)(void*))
// {
// 	del(lst->content);
// 	free(lst);
// }

// void	ft_lstclear(t_list **lst, void (*del)(void*))
// {
// 	t_list	*aux1;
// 	t_list	*aux2;

// 	aux1 = *lst;
// 	while (aux1 != NULL)
// 	{
// 		aux2 = aux1->next;
// 		ft_lstdelone(aux1, del);
// 		aux1 = aux2;
// 	}
// 	*lst = NULL;
// }

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




// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include "libft.h"  // Asegúrate de incluir tu header

// t_list	*ft_lstlast(t_list *lst)
// {
// 	while (lst != NULL)
// 	{
// 		if (lst->next == NULL)
// 			return (lst);
// 		lst = lst->next;
// 	}
// 	return (NULL);
// }

// void	ft_lstadd_back(t_list **lst, t_list *new)
// {
// 	t_list	*last;

// 	last = ft_lstlast(*lst);
// 	if (last == NULL)
// 		*lst = new;
// 	else
// 		last->next = new;
// }

// // Función que transforma el contenido (duplica string y lo pasa a mayúsculas)
// void *map_to_upper(void *content)
// {
//     char *str = (char *)content;
//     char *new_str = strdup(str);  // Reservamos nuevo string
//     if (!new_str)
//         return NULL;

//     for (int i = 0; new_str[i]; i++)
//         if (new_str[i] >= 'a' && new_str[i] <= 'z')
//             new_str[i] -= 32;  // Convertimos a mayúscula

//     return (void *)new_str;
// }

// // Función para liberar memoria de un nodo
// void del_content(void *content)
// {
//     free(content);
// }

// // Función para imprimir una lista
// void print_list(t_list *lst)
// {
//     while (lst)
//     {
//         printf("%s -> ", (char *)lst->content);
//         lst = lst->next;
//     }
//     printf("NULL\n");
// }
// void *f_fail(void *c) { (void)c; return NULL; }

// int main(void)
// {
//     t_list *n1 = ft_lstnew(strdup("que"));
//     // t_list *n2 = ft_lstnew(strdup("que"));
//     // t_list *n3 = ft_lstnew(strdup("tal"));

//     // n1->next = n2;
//     // n2->next = n3;

//     printf("Lista original:\n");
//     print_list(n1);

//     t_list *mapped = ft_lstmap(n1, &f_fail, &del_content);

//     printf("\nLista mapeada:\n");
//     print_list(mapped);

//     // Liberar memoria
//     ft_lstclear(&n1, &del_content);
//     ft_lstclear(&mapped, &del_content);

//     return 0;
// }