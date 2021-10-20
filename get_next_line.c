/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:53:32 by jporta            #+#    #+#             */
/*   Updated: 2021/10/20 19:37:53 by jporta           ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	char				*buf;
	ssize_t				nr_bytes;
	static char			*lineas;
	static char			*saved;

	if (lineas)
		ft_maldel(lineas);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (BUFFER_SIZE == 0 || fd < 0 || read(fd, buf, 0) == -1)
		return (NULL);
	lineas = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!lineas)
		ft_maldel(lineas);
	if (!saved)
		saved = malloc(sizeof(char) * 15);
	if (!saved)
		return (0);
	lineas = saved + 1;
	while (ft_strrchr(lineas, '\n') == 0)
	{
		nr_bytes = read(fd, buf, BUFFER_SIZE);
		if (nr_bytes == 0)
			return (NULL);
		lineas = ft_strjoin(lineas, buf);
	}
	free (buf);
	saved = ft_strchr(lineas, '\n');
	lineas = get_my_line(lineas, saved);
	return (lineas);
}

int	main(void)
{
	int		fd;
	char	*pepe;

	fd = open("/Users/jporta/Documents/getnext/hola.txt", O_RDONLY);
	pepe = get_next_line(fd);
	printf("primera :%s\n", pepe);
	pepe = get_next_line(fd);
	printf("segunda :%s\n", pepe);
	pepe = get_next_line(fd);
	printf("tercera :%s\n", pepe);
	pepe = get_next_line(fd);
	printf("cuarta :%s\n", pepe);
	pepe = get_next_line(fd);
	printf("quinta :%s\n", pepe);
	close(fd);
	return (0);
}
