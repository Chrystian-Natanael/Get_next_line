/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:53:18 by cnatanae          #+#    #+#             */
/*   Updated: 2023/11/14 14:46:52 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 13
# endif

/**@brief Struct to store a character and a pointer to the next character.
 * 
 * @param character for the character.
 * @param *next the pointer to the next node.
*/
typedef struct s_char
{
	char			character;
	struct s_char	*next;
}					t_char;

/**@brief Struct to store a variable and a pointer to the next node.
 * 
 * @param fd The file descriptor.
 * @param pos The position of the buffer.
 * @param read The number of bytes read.
 * @param len The length of the struct s_list.
 * @param buffer The buffer.
 * @param *string The pointer to the next node.
*/
typedef struct s_list
{
	int				fd;
	int				pos;
	int				read;
	int				len;
	char			buffer[BUFFER_SIZE];
	t_char			*string;
}					t_list;

/**@brief Function to get the next line.
 * 
 * @param fd The file descriptor.
 * @return char* The next line.
*/
char	*get_next_line(int fd);

/**@brief Function to clear the linked list.
 * 
 * @param *str The pointer to the linked list.
 * @return char* The pointer to NULL.
*/
char	*free_all(t_char *str);

#endif
