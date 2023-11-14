/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:53:15 by cnatanae          #+#    #+#             */
/*   Updated: 2023/11/14 18:09:49 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_char	*ft_node(char c)
{
	t_char	*new_node;
	new_node = malloc(sizeof(t_char));
	if (!new_node)
	{
		printf("erro 1");
		return (NULL);
	}
	new_node->character = c;
	new_node->next = NULL;
	return (new_node);
}

int	ft_lstsize(t_char *lst, t_list *struc)
{
	int	idx;

	idx = 0;
	while (lst->character != '\n' || !lst)
	{
		lst = lst->next;
		idx++;
	}
	struc->len = idx;
	if (lst->character == '\n')
	{
		struc->len++;
	}
	
	return (idx);
}

char	*ft_build_string(t_list *struc)
{
	size_t	size_lk;
	char	*line;
	int		idx;

	idx = 0;
	size_lk = ft_lstsize(struc->string, struc);
	line = malloc(sizeof(char) * size_lk + 1);
	if (!line)
	{
		printf("erro 2");
		return (NULL);
	}
	while (struc->string && struc->string->character != '\n')
	{
		line[idx++] = struc->string->character;
		struc->string = struc->string->next;
	}
	struc->string = struc->string->next;
	line[idx] = '\0';
	return (line);
}

int	ft_find_n(t_list *struc)
{
	t_char	*aux;

	aux = struc->string;
	while (aux)
	{
		if (aux->character == '\n')
			return (1);
		aux = aux->next;
	}
	return (0);
}
char	*ft_add_lk(t_list *struc)
{
	t_char	*aux;
	t_char	*new_node;
	int		exist_n;

	exist_n = 0;
	if (!struc->string)
		struc->string = ft_node(struc->buffer[struc->pos++]);
	aux = struc->string;
	while (aux->next)
		aux = aux->next;
	if (!aux)
	{
		printf("erro 3");
		return (NULL);
	}
		//exist_n = ft_find_n(struc);
	while (exist_n == 0)
	{
		while (struc->buffer[struc->pos])
		{
			new_node = ft_node(struc->buffer[struc->pos]);
			if (!new_node)
			{
				free_all(struc->string);
				printf("erro 4");
				return (NULL);
			}
			aux->next = new_node;
			aux = aux->next;
			struc->pos++;
		}
		exist_n = ft_find_n(struc);
		if (exist_n == 0)
		{
			struc->read = read(struc->fd, struc->buffer, BUFFER_SIZE);
			struc->pos = 0;
			if (struc->read == -1)
			{
				free_all(struc->string);
				printf("erro 5");
				return (NULL);
			}
		}
	}
	return(ft_build_string(struc));
}

char	*get_next_line(int fd)
{
	static t_list	struc;
	
	if (!fd || fd < 0 || BUFFER_SIZE <= 0)
	{
		printf("erro 6");
		return (NULL);
	}
	struc.pos = 0;
	struc.fd = fd;
	struc.read = read(fd, struc.buffer, BUFFER_SIZE);
	struc.buffer[struc.read] = '\0';
	if (struc.read == -1)
	{
		free_all(struc.string);
		printf("erro 7");
		return (NULL);
	}
	if (struc.string && !struc.string->character && struc.buffer[struc.pos] == '\0')
	{
		free_all(struc.string);
		return (NULL);
	}
	return (ft_add_lk(&struc));
}
