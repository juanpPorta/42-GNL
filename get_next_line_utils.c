/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:48:04 by jporta            #+#    #+#             */
/*   Updated: 2021/10/21 18:53:45 by jporta           ###   ########.fr       */
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

char	*ft_strjoin(char *lineas, char *buf)
{
	char	*str;
	int		i;
	int		cont;

	if (!lineas || !buf)
		return (0);
	str = (char *)malloc(ft_strlen(lineas) + ft_strlen(buf) + 1);
	if (!str)
		return (0);
	i = 0;
	while (lineas[i] != '\0')
	{
		str[i] = lineas[i];
		i++;
	}
	cont = 0;
	while (buf[cont] != '\0')
	{
		str[i] = buf[cont];
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
	pepe = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (lineas[i] != saved[0])
	{
		pepe[i] = lineas[i];
		i++;
	}
	pepe[i] = '\0';
	return (pepe);
}