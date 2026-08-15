/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:52:29 by iskaraag          #+#    #+#             */
/*   Updated: 2024/05/30 14:52:31 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	f_getline(int fd, char **readen, int first)
{
	int	i;

	if (first == 1)
	{
		if (*readen && first == 1)
			return (ft_strlenn(*readen));
		*readen = malloc((long int)BUFFER_SIZE + 1);
		if (!(*readen))
		{
			*readen = NULL;
			return (0);
		}
	}
	i = read(fd, *readen, BUFFER_SIZE);
	if (i >= 0)
	{
		(*readen)[i] = '\0';
		i = ft_strlenn(*readen);
	}
	else
	{
		free(*readen);
		(*readen) = NULL;
	}
	return (i);
}

char	*ft_errorfree(char **s1, char *s2)
{
	if ((*s1))
		free((*s1));
	(*s1) = NULL;
	return (s2);
}

char	*get_next_line(int fd)
{
	static char	*redded[2048];
	int			i;
	char		*res;

	res = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = f_getline(fd, &redded[fd], 1);
	while (i > 0)
	{
		res = ft_strjoin(&res, redded[fd], i);
		if (!res)
			return (ft_errorfree(&redded[fd], NULL));
		if (redded[fd][i - 1] == 10)
		{
			if (redded[fd][i] == 0)
				break ;
			redded[fd] = ft_cshift(redded[fd], i);
			return (res);
		}
		i = f_getline(fd, &redded[fd], 0);
	}
	return (ft_errorfree(&redded[fd], res));
}
