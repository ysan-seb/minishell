/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <ysan-seb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/01 13:33:38 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/05/18 11:46:35 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char	*ft_append(char *str, int fd, int *eof)
{
	char	*buffer;
	char	*tmp;
	int		ret;
	int		t;

	t = 0;
	if (!(buffer = ft_strnew(BUFF_SIZE)))
		return (NULL);
	while (!t || !(ft_strchr(str, '\n') || *eof))
	{
		if ((ret = read(fd, buffer, BUFF_SIZE)) == -1)
			return (NULL);
		t = 1;
		if (ret < BUFF_SIZE)
			*eof = 1;
		tmp = str;
		str = ft_strjoin(str, buffer);
		ft_strdel(&tmp);
		ft_strclr(buffer);
	}
	free(buffer);
	return (str);
}

int				get_next_line(const int fd, char **line)
{
	static char		*str[500] = {0};
	int				i;
	int				eof;

	i = 0;
	eof = 0;
	if (fd < 0 || !line || (str[fd] ? 0 : !(str[fd] = ft_strnew(BUFF_SIZE))))
		return (-1);
	if ((str[fd] = ft_append(str[fd], fd, &eof)) == NULL)
		return (-1);
	if (str[fd][0] == '\0' && eof)
	{
		ft_strdel(&str[fd]);
		free(str[fd]);
		return (0);
	}
	while (str[fd][i] && str[fd][i] != '\n')
		i++;
	*line = ft_strsub(str[fd], 0, i);
	ft_memmove(str[fd], str[fd] + i + 1, ft_strlen(str[fd]) - (i > 0 ? 1 : 0));
	return (1);
}
