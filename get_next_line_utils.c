/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:48:04 by jporta            #+#    #+#             */
/*   Updated: 2021/10/13 18:20:06 by jporta           ###   ########.fr       */
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

int	ft_strrchr(const char *s, int c)
{
	while (s)
	{
		if ((unsigned char)*s != (unsigned char)c)
			s++;
		else
		{
			return (1);
		}
	}
	return (0);
}

size_t	ft_strlen_modif(const char *cadena)
{
	size_t	a;

	a = 0;
	while (cadena[a] != '\n')
		a++;
	return (a);
}

char	*getmyline(char *fd)
{
	static char	*linea;
	int			contador;
	int			i;

	if (!fd)
	{
		printf("no hay nada");
		return (0);
	}
	contador = 0;
	contador = ft_strlen_modif(fd);
	printf("contador :%d\n", contador);
	linea = malloc(sizeof(contador) * sizeof(char));
	i = 0;
	while (fd && i < contador)
	{
		linea[i] = fd[i];
		i++;
	}
	return (linea);
}
