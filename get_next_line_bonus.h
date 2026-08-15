/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:52:42 by iskaraag          #+#    #+#             */
/*   Updated: 2024/05/30 14:52:46 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strdup(char const *s);
char	*ft_strjoin(char **s1, char const *s2, int len2);
char	*ft_cshift(char *s1, int shift);
char	*ft_errorfree(char **s1, char *s2);
int		f_getline(int fd, char **readed, int firstrun);
int		ft_strlenn(char const *s);
size_t	ft_strlen(char const *s);

#endif
