/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:09:13 by aguenel           #+#    #+#             */
/*   Updated: 2019/11/25 13:36:18 by aguenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strdel(char **as)
{
	if (as != NULL)
	{
		free(*as);
		*as = NULL;
	}
	return (0);
}

char	*ft_strnew(size_t size)
{
	char	*s;
	size_t	i;

	i = 0;
	s = (char*)malloc(size + 1);
	if (s == NULL)
		return (NULL);
	while (i < size)
		s[i++] = 0;
	s[size] = '\0';
	return (s);
}

int		ft_output(char *s, char **line, int ret)
{
	int		len;
	int		res;

	if (ret < 0)
		res = -1;
	else
	{
		len = 0;
		while (s[len] != '\0' && s[len] != '\n')
			len++;
		if (line)
			ft_strdel(line);
		*line = ft_substr(s, 0, len);
		res = 1;
	}
	if (ret == 0 && s[ft_strlen(*line)] == '\0')
		res = 0;
	return (res);
}

int		ft_fill_s(char **s, char **line, int fd)
{
	int		ret;
	char	*tmp;
	char	*buf;
	int		res;

	if ((!(buf = ft_strnew((BUFFER_SIZE + 1)))))
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(*s, buf);
		ft_strdel(&*s);
		*s = ft_strdup(tmp);
		ft_strdel(&tmp);
		if ((ft_bsn(buf)) == 1)
			break ;
	}
	free(buf);
	res = ft_output(*s, line, ret);
	return (res);
}

int		get_next_line(int fd, char **line)
{
	static char	*s;
	char		*tmp;
	int			res;

	if (BUFFER_SIZE == 0 || !line || (!s && !(s = ft_strnew(1))) ||\
		(!(*line = ft_strnew(0))) || (fd < 0))
		return (-1);
	res = ft_fill_s(&s, line, fd);
	if (s[ft_strlen(*line)] == '\n')
	{
		tmp = ft_strdup(s + ft_strlen(*line) + 1);
		ft_strdel(&s);
		s = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
	else if (s[ft_strlen(*line)] == '\0')
		ft_strdel(&s);
	return (res);
}
