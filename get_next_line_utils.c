/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: splinta <splinta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 15:54:49 by outaouss          #+#    #+#             */
/*   Updated: 2025/12/10 01:02:58 by splinta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strdup(char *s)
{
	size_t	i;
	size_t	len_s;
	char	*dest;

	if (!s)
		return (NULL);
	i = 0;
	len_s = ft_strlen(s);
	dest = malloc(len_s + 1);
	if (!dest)
		return (NULL);
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new_string;

	if (!s1)
		return (ft_strdup(s2));
	i = 0;
	j = 0;
	new_string = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!new_string)
		return (NULL);
	while (s1[i] != '\0')
	{
		new_string[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		new_string[i] = s2[j];
		j++;
		i++;
	}
	// static int f = 1;
	// printf("[ %d ]", f);
	// f++;
	free(s1);
	new_string[i] = '\0';
	return (new_string);
}
