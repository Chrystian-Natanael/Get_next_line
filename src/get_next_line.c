/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:53:15 by cnatanae          #+#    #+#             */
/*   Updated: 2023/11/17 11:37:48 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_build_string(t_list *struc)
{
	size_t				size_lk;
	char				*line;
	unsigned long int	idx;
	t_char				*aux;

	idx = 0;
	size_lk = ft_lstsize(struc->string, struc);
	line = malloc(sizeof(char) * size_lk + 2);
	if (!line)
	{
		free_all(&struc->string);
		return (NULL);
	}
	while (struc->string && struc->string->character != '\n')
	{
		aux = struc->string;
		line[idx++] = struc->string->character;
		struc->string = struc->string->next;
		free (aux);
	}
	aux = struc->string;
	if (struc->string)
		struc->string = struc->string->next;
	if (aux && aux->character == '\n')
		line[idx++] = '\n';
	free (aux);
	line[idx] = '\0';
	return (line);
}

char	*ft_add_lk(t_list *struc)
{
	t_char				*aux;
	int					exist_n;

	exist_n = 0;
	aux = struc->string;
	while (aux && aux->next)
		aux = aux->next;
	while (exist_n == 0 && struc->buffer[struc->pos] != '\0')
	{
		while (struc->buffer[struc->pos])
		{
			aux = add_node_to_end(struc, aux, struc->buffer[struc->pos++]);
			if (!aux)
				return (NULL);
		}
		struc->pos = 0;
		exist_n = ft_find_n(struc);
		if (exist_n == 0)
		{
			while (struc->pos <= BUFFER_SIZE)
				struc->buffer[struc->pos++] = '\0';
			struc->read = read(struc->fd, struc->buffer, BUFFER_SIZE);
			struc->pos = 0;
			if (struc->read == -1)
			{
				free_all(&struc->string);
				return (NULL);
			}
		}
	}
	return (ft_build_string(struc));
}

char	*get_next_line(int fd)
{
	static t_list	struc;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	struc.pos = 0;
	struc.fd = fd;
	while (struc.pos <= BUFFER_SIZE + 1)
		struc.buffer[struc.pos++] = '\0';
	struc.pos = 0;
	struc.read = read(fd, struc.buffer, BUFFER_SIZE);
	struc.buffer[struc.read] = '\0';
	if (struc.read == -1)
	{
		free_all(&struc.string);
		return (NULL);
	}
	if (!struc.string && struc.buffer[struc.pos] == '\0')
	{
		free_all(&struc.string);
		return (NULL);
	}
	return (ft_add_lk(&struc));
}
