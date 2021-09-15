/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig <rarodrig@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:12:35 by rarodrig          #+#    #+#             */
/*   Updated: 2021/06/14 19:12:35 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*n_s;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	i = ft_strlen(s + start);
	if (i < len)
		len = i;
	n_s = (char *)malloc(sizeof(char) * (len + 1));
	if (n_s == NULL)
		return (NULL);
	ft_strlcpy(n_s, s + start, len + 1);
	return (n_s);
}

size_t	ft_strlen(const char *s)
{
	size_t	cont;

	cont = 0;
	while (*s != 0)
	{
		++s;
		cont++;
	}
	return (cont);
}

char	*ft_strdup(const char *string)
{
	char	*str;
	size_t	cont;

	cont = 0;
	str = (char *)malloc(sizeof(char) * ft_strlen(string) + 1);
	if (str == NULL)
	{
		return (NULL);
	}
	while (string[cont])
	{
		str[cont] = string[cont];
		cont ++;
	}
	str[cont] = '\0';
	return (str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	cont;

	if (n == 0)
		return (ft_strlen(src));
	cont = 0;
	while (cont < (n - 1) && src[cont])
	{
		dst[cont] = src[cont];
		cont++;
	}
	dst[cont] = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nstr;
	size_t	i;
	size_t	cont;

	i = ft_strlen(s1);
	nstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	cont = 0;
	if (nstr == NULL)
		return (NULL);
	if (!s1 || !s2)
		return (NULL);
	while (s1[cont])
	{
		nstr[cont] = s1[cont];
		cont++;
	}
	i = 0;
	while (s2[i])
	{
		nstr[cont] = s2[i];
		i++;
		cont++;
	}
	nstr[cont] = '\0';
	return (nstr);
}
