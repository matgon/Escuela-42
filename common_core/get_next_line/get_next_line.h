/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matgonza <matgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:26:20 by matgonza          #+#    #+#             */
/*   Updated: 2025/05/19 15:40:12 by matgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_H
# define	GET_NEXT_LINE_H

#ifndef	BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd);
#endif