/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:53:32 by jporta            #+#    #+#             */
/*   Updated: 2021/10/21 18:55:20 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_maldel(char *str)
{
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
}

char	*Super_get(int fd, char *lineas)
{
	ssize_t	nr_bytes;
	char	*buf;
	char	*temp;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (BUFFER_SIZE == 0 || fd < 0 || read(fd, buf, 0) == -1)
	{
		free (buf);
		free (lineas);
		return (NULL);
	}
	nr_bytes = 1;
	while (nr_bytes > 0 && ft_strrchr(lineas, '\n') == 0)
	{
		nr_bytes = read(fd, buf, BUFFER_SIZE);
		buf[nr_bytes] = '\0';
		temp = ft_strjoin(lineas, buf);
		if (lineas[0] == '\0')
			lineas = NULL;
		free (lineas);
		lineas = temp;
	}
	free (temp);
	free (buf);
	return (lineas);
}

char	*ft_saved(char *saved, char *lineas)
{
	if (ft_strchr(lineas, '\n') != 0)
	{
		saved = ft_strchr(lineas, '\n');
		return (saved);
	}
	if (ft_strchr(lineas, '\0') != 0)
	{
		saved = ft_strchr(lineas, '\0');
		return (saved);
	}
	return (0);
}

char	*get_next_line(int fd)
{	
	char				*lineas;
	static char			*saved;

	lineas = malloc(sizeof(char *) * BUFFER_SIZE + 1);
	if (!lineas)
	{
		free (lineas);
		return (0);
	}
	if (!saved)
		saved = malloc(sizeof(char *));
	if (!saved)
	{
		free (saved);
		return (0);
	}
	lineas = saved + 1;
	lineas = Super_get(fd, lineas);
	if (lineas == NULL)
		return (NULL);
	saved = ft_saved(saved, lineas);
	lineas = get_my_line(lineas, saved);
	return (lineas);
}

int	main(void)
{
	int		fd;
	char	*pepe;

	fd = open("/Users/jporta/Documents/getnext/hola.txt", O_RDONLY);
	pepe = get_next_line(fd);
	system("leaks a.out");
	printf("primera :%s\n", pepe);
	free (pepe);
	/*pepe = get_next_line(fd);
	printf("segunda :%s\n", pepe);
	pepe = get_next_line(fd);
	printf("tercera :%s\n", pepe);
	pepe = get_next_line(fd);
	printf("cuarta :%s\n", pepe);
	pepe = get_next_line(fd);
	printf("quinta :%s\n", pepe);*/
	close(fd);
	return (0);
}
