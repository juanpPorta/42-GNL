/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:53:32 by jporta            #+#    #+#             */
/*   Updated: 2021/10/13 18:21:32 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char			*buf;
	ssize_t				nr_bytes;
	static char			*lineas;

	if (buf)
		free(buf);
	buf = malloc(BUFFER_SIZE * sizeof(char));
	if (!buf)
		return (0);
	if (ft_strrchr(lineas, '\n') == 0)
		nr_bytes = read (fd, buf, BUFFER_SIZE);
	else
		free(lineas);
	lineas = getmyline(buf);
	return (lineas);
}

int	main(void)
{
	int		fd;
	char	*pepe;

	fd = open("/Users/jporta/Documents/getnext/pepe.txt", O_RDONLY);
	pepe = get_next_line(fd);
	if (pepe == 0)
	{
		printf("archivo vacio \n");
	}
	else
	{
		printf("segunda :%s\n", pepe);
		pepe = get_next_line(fd);
		printf("tercera :%s\n", pepe);
	}
	close(fd);
	return (0);
}
