/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jporta <jporta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:22:23 by jporta            #+#    #+#             */
/*   Updated: 2021/10/21 18:50:48 by jporta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
char	*ft_strdup(const char *s1);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strjoin(char *lineas, char *buf);
char	*get_next_line(int fd);
char	*get_my_line(char *lienas, char *saved);
size_t	ft_strlen(const char *cadena);
char	*ft_strrchr(const char *s, int c);
char	*ft_strchr(const char *s, int c);
#endif