/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:48:04 by jporta            #+#    #+#             */
/*   Updated: 2021/10/20 19:26:53 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *cadena)
{
	size_t	a;

	a = 0;
	while (cadena[a])
		a++;
	return (a);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		cont;

	if (!s1 || !s2)
		return (0);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	cont = 0;
	while (s2[cont] != '\0')
	{
		str[i] = s2[cont];
		cont++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*last;

	last = s;
	i = ft_strlen(s);
	s += i;
	while (s != last && c != *s)
		s--;
	if ((unsigned char)c == (unsigned char)*s)
		return ((char *)s);
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && (unsigned char)c != *s)
		s++;
	if ((unsigned char)c == *s)
		return ((char *)s);
	return (0);
}

char	*get_my_line(char *lineas, char *saved)
{
	char	*pepe;
	int		i;

	i = 0;
	pepe = malloc(sizeof(char) * BUFFER_SIZE);
	while (lineas[i] != saved[0])
	{
		pepe[i] = lineas[i];
		i++;
	}
	pepe[i] = '\0';
	return (pepe);
}