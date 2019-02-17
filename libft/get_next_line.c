/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 13:46:17 by gkessler          #+#    #+#             */
/*   Updated: 2019/01/06 17:31:22 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int				ft_strint(char *src, int c)
{
	if (!src)
		return (0);
	while (*src)
	{
		if (*src == c)
			return (1);
		src++;
	}
	if (*src == c)
		return (1);
	return (0);
}

static	char			*ft_to_line(char ***fresh, int fd)
{
	char	*tmp;
	char	*line;
	int		i;

	i = 0;
	if (!(*fresh)[fd])
		return (0);
	tmp = (*fresh)[fd];
	while (tmp[i] != '\n' && tmp[i])
		i++;
	line = NULL;
	line = ft_strsub(tmp, 0, i);
	if (i < (int)ft_strlen(tmp))
		(*fresh)[fd] = ft_strdup(&tmp[i + 1]);
	else
		(*fresh)[fd] = ft_strdup("\0");
	free(tmp);
	return (line);
}

static	char			*ft_newjoin(char *oldfresh, char *buf)
{
	char	*newfresh;

	if (oldfresh == 0)
		oldfresh = ft_strnew(0);
	if (!(newfresh = ft_strnew(ft_strlen(oldfresh) + ft_strlen(buf))))
		return (0);
	bzero(newfresh, ft_strlen(oldfresh) + ft_strlen(buf));
	ft_strcpy(newfresh, oldfresh);
	ft_strcat(newfresh, buf);
	free(oldfresh);
	return (newfresh);
}

int						get_next_line(int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char **fresh = 0;
	int			bt;

	bt = 0;
	if (!fresh && !(fresh = (char **)malloc(sizeof(char *) * 1000)))
		return (-1);
	if (!line || fd < 0 || fd > 999)
		return (-1);
	if ((ft_strint(fresh[fd], '\n')) == 0)
		while ((bt = read(fd, buf, BUFF_SIZE)) > 0)
		{
			buf[bt] = '\0';
			fresh[fd] = ft_newjoin(fresh[fd], buf);
			if (ft_strchr(buf, '\n'))
				break ;
		}
	if (bt < 0)
		return (-1);
	if (ft_strlen(fresh[fd]))
		return (!!(*line = ft_to_line(&fresh, fd)));
	return (0);
}
