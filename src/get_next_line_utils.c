/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ivarosic <ivarosic@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/04 09:43:02 by ivarosic     #+#   ##    ##    #+#       */
/*   Updated: 2021/05/27 10:23:11 by ivanrosic    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_next_line_cut(size_t i, char **line, char *str)
{
	if (i == 0)
		*line = ft_strdup("");
	else
		*line = ft_substr(str, 0, i);
	str[0] = '\0';
}

size_t		ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char		*ft_strdup(const char *s1)
{
	char		*str;
	size_t		i;
	size_t		tmp;

	i = 0;
	tmp = ft_strlen(s1);
	if (!(str = malloc(sizeof(*str) * (tmp + 1))))
		return (NULL);
	while (i < tmp)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;

	if (start > len)
		return (ft_strdup(""));
	i = 0;
	if (!(str = malloc(sizeof(*str) * len + 1)))
		return (NULL);
	while (i < len && s[i + start] != '\0')
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_strcpy(char *dest, const char *src)
{
	size_t		i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
