/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadzuki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 11:30:08 by iadzuki           #+#    #+#             */
/*   Updated: 2021/01/16 14:18:03 by iadzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			free_all(char **remainder, char **buf, int return_value)
{
	free(*remainder);
	*remainder = NULL;
	free(*buf);
	return (return_value);
}

static int	costyl(char **line, char **remainder, char **buf, char *p_strchr)
{
	char	*tmp;

	if (p_strchr)
	{
		*p_strchr = '\0';
		if ((*line = ft_strdup(*remainder)) == NULL)
			return (free_all(remainder, buf, -1));
		tmp = *remainder;
		if ((*remainder = ft_strdup(++p_strchr)) == NULL)
			return (free_all(remainder, buf, -1));
		return (free_all(&tmp, buf, 1));
	}
	if (*remainder)
	{
		if ((*line = ft_strdup(*remainder)) == NULL)
			return (free_all(remainder, buf, -1));
	}
	else if ((*line = ft_strdup("\0")) == NULL)
		return (free_all(remainder, buf, -1));
	return (free_all(remainder, buf, 0));
}

int			get_next_line(int fd, char **line)
{
	static char	*remainder;
	char		*buf;
	char		*p_strchr;
	char		*tmp;
	int			cnt_read_bytes;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || (read(fd, NULL, 0) < 0) ||
			!(buf = malloc(BUFFER_SIZE + 1)))
		return (-1);
	while ((p_strchr = ft_strchr(remainder)) == NULL &&
			(cnt_read_bytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[cnt_read_bytes] = '\0';
		tmp = remainder;
		if (remainder == NULL)
		{
			if ((remainder = ft_strdup(buf)) == NULL)
				return (free_all(&remainder, &buf, -1));
		}
		else if ((remainder = ft_strjoin(remainder, buf)) == NULL)
			return (free_all(&remainder, &buf, -1));
		free(tmp);
	}
	return (costyl(line, &remainder, &buf, p_strchr));
}
