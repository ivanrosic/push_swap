/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_av.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivarosic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:36:24 by ivarosic          #+#    #+#             */
/*   Updated: 2021/05/27 16:39:58 by ivarosic         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_nb(char *str)
{
	int	i;
	int	cpt;

	i = 0;
	cpt = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			while (str[i] && (str[i] >= '0' && str[i] <= '9'))
				i++;
			cpt++;
		}
		if (str[i])
			i++;
	}
	return (cpt);
}

int	ft_comp(t_stack *s)
{
	int	i;
	int	a;
	int	j;

	a = s->a[0];
	i = 0;
	while (a)
	{
		i++;
		j = i;
		while (s->a[j])
		{
			if (s->a[j] == a)
				return (1);
			j++;
		}
		a = s->a[i];
	}
	return (0);
}

int	ft_fill_av_bis(t_stack *s)
{	
	if (ft_comp(s) == 1)
		return (1);
	return (0);
}

int	ft_fill_av(char *str, t_stack *s)
{
	int			i;
	int			j;
	long long	tmp;

	j = 0;
	i = 0;
	while (str[i])
	{
		i = ft_space(str, i);
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
		{
			tmp = ft_lld_atoi(&str[i]);
			if (tmp > 2147483647 || tmp < -2147483648)
				return (1);
			s->a[j] = ft_atoi(&str[i]);
			j++;
			while ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
				i++;
		}
		else
			return (1);
		if (str[i])
			i++;
	}
	return (ft_fill_av_bis(s));
}

int	ft_arg_to_av(char **av, t_stack *s)
{
	s->size_a = ft_count_nb(av[1]);
	s->size_b = 0;
	s->a = malloc(sizeof(int) * (s->size_a));
	s->b = malloc(sizeof(int) * (s->size_a));
	return (ft_fill_av(av[1], s));
}
