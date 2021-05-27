/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivarosic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:31:28 by ivarosic          #+#    #+#             */
/*   Updated: 2021/05/27 17:03:23 by ivarosic         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_skip_space(char **av, int i, int j)
{
	while ((av[i][j] == '\t') || (av[i][j] == '\n') || (av[i][j] == '\v')
			|| (av[i][j] == '\f') || (av[i][j] == '\r') || (av[i][j] == ' '))
		j++;
	return (j);
}

int	ft_space(char *str, int i)
{
	while (str[i] && (((str[i] == '\t') || (str[i] == '\n') || (str[i] == '\v')
				|| (str[i] == '\f') || (str[i] == '\r') || (str[i] == ' '))))
		i++;
	return (i);
}

void	ft_get_median(t_stack *s)
{
	int	*tmp;
	int	i;

	tmp = malloc(sizeof(int) * s->size_a);
	i = 0;
	while (i < s->size_a)
	{
		tmp[i] = s->a[i];
		i++;
	}
	i = 1;
	while (i < s->size_a)
	{
		if (tmp[i - 1] > tmp[i])
		{
			ft_swap(&tmp[i - 1], &tmp[i]);
			i = 1;
		}
		else
			i++;
	}
	s->med = tmp[(i / 2) - 1];
	free(tmp);
}
