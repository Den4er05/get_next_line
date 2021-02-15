/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iadzuki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 11:30:24 by iadzuki           #+#    #+#             */
/*   Updated: 2021/01/16 14:07:20 by iadzuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	int		i;
	int		j;

	if ((res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)) == NULL)
		return (NULL);
	i = 0;
	while ((res[i] = s1[i]) != '\0')
		++i;
	j = 0;
	while ((res[i++] = s2[j]) != '\0')
		++j;
	return (res);
}

char	*ft_strchr(const char *s)
{
	int		idx;

	if (s == NULL)
		return (NULL);
	idx = 0;
	while (s[idx])
	{
		if (s[idx] == '\n')
			return ((char *)s + idx);
		++idx;
	}
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*new;
	int		idx;

	if ((new = malloc(ft_strlen(s) + 1)) == NULL)
		return (NULL);
	idx = 0;
	while ((new[idx] = s[idx]) != '\0')
		++idx;
	return (new);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		++len;
	return (len);
}
