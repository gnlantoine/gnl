/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:10:15 by aguenel           #+#    #+#             */
/*   Updated: 2019/11/25 14:43:28 by aguenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		get_next_line(int fd, char **line);
int		ft_output(char *s, char **line, int ret);
char	*ft_substr(char const *s, unsigned int strat, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_bsn(const char *s);
size_t	ft_strlen(const char *s);
int		ft_strdel(char **as);
int		ft_fill_s(char **s, char **line, int fd);
char	*ft_strnew(size_t size);

#endif
