/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: splinta <splinta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 09:46:09 by outaouss          #+#    #+#             */
/*   Updated: 2025/12/10 01:27:52 by splinta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <stddef.h>


///// GNL HUGE TEST

// #define malloc(x) my_malloc(x)

// #ifdef malloc
// #undef malloc

// static inline void* my_malloc(size_t size) 
// {
//     static int var;
//     void* ptr;
//     if (var > 156)
//         ptr = NULL;
//     else
//         ptr = malloc(size);
//     var++; 
//     return ptr;
// }
// #define malloc(x) my_malloc(x)
// #endif

// #define malloc(x) my_malloc(x)

////////////// GNL END OF THE HUGE TEST

char	*get_next_line(int fd);
char	*ft_strjoin(char *line, char *buff);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *s);
char	*ft_get_line(char *line);
char	*ft_read_line(int fd, char *line);
char	*ft_new_line(char *line);
char	*ft_strdup(char *s);

#endif