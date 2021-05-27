/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multi_av.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivarosic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:25:45 by ivarosic          #+#    #+#             */
/*   Updated: 2021/05/27 18:04:23 by ivarosic         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_tmp(char **av, int i, t_stack *s)
{
	long long	tmp;

	tmp = ft_lld_atoi(av[i]);
	if (tmp > 2147483647 || tmp < -2147483648)
		return (1);
	s->a[i - 1] = ft_atoi(av[i]);
	return (0);
}

int	ft_fill(t_stack *s)
{
	int	i;
	int	j;

	i = 1;
	j = s->a[0];
	while (i < s->size_a)
	{
		if (j > s->a[i])
			return (0);
		i++;
	}
	return (2);
}

int	ft_verif_char(char **av, int i, int j)
{
	while (av[i][j])
	{
		j = ft_skip_space(av, i, j);
		if ((av[i][j] < '0' || av[i][j] > '9'))
			if (av[i][j] != '-' && av[i][j] != '+')
				return (-1);
		j++;
	}
	return (j);
}

int	ft_fill_struct(char **av, t_stack *s)
{
	int	i;
	int	j;

	i = 1;
	while (i < s->size_a + 1)
	{
		j = 0;
		j = ft_verif_char(av, i, j);
		if (j == -1)
			return (1);
		if (ft_tmp(av, i, s) == 1)
			return (1);
		j = 0;
		while (j < i - 1)
		{
			if (s->a[i - 1] == s->a[j])
				return (1);
			j++;
		}
		i++;
	}
	return (ft_fill(s));
}

int	ft_init_struct(int ac, char **av, t_stack *s)
{
	s->a = malloc(sizeof(int) * (ac - 1));
	s->b = malloc(sizeof(int) * (ac - 1));
	s->size_a = ac - 1;
	s->size_b = 0;
	return (ft_fill_struct(av, s));
}
