/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:53:12 by cnatanae          #+#    #+#             */
/*   Updated: 2023/11/14 18:10:00 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_all(t_char *str)
{
	t_char	*aux;

	aux = str;
	while (aux)
	{
		aux = str->next;
		free(str);
		str = aux;
	}
	aux = NULL;
	return (NULL);
}
