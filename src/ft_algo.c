/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivarosic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:42:39 by ivarosic          #+#    #+#             */
/*   Updated: 2021/05/27 16:53:21 by ivarosic         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_last(t_stack *s)
{
	if (s->a[0] < s->a[1] && s->a[0] < s->a[2] && s->a[1] > s->a[2])
		ft_sa(s);
	if (s->a[0] > s->a[1] && s->a[0] > s->a[2])
		ft_ra(s);
	if (s->a[2] < s->a[1] && s->a[2] < s->a[0])
		ft_rra(s);
	if (s->a[0] > s->a[1])
		ft_sa(s);
	if (s->a[2] > s->a[1] && s->a[2] > s->a[0] && s->a[1] < s->a[0])
		ft_sa(s);
}

int	ft_fast(t_stack *s, int low)
{
	int	i;
	int	cpt;

	i = 0;
	while (i < s->size_a)
	{
		if (low == s->a[i])
			cpt = i;
		i++;
	}
	i = i / 2;
	if (i > cpt)
		return (1);
	return (0);
}

int	ft_fast_up(t_stack *s, int up)
{
	int	i;
	int	cpt;

	i = 0;
	while (i < s->size_b)
	{
		if (up == s->b[i])
			cpt = i;
		i++;
	}
	i = i / 2;
	if (i > cpt)
		return (1);
	return (0);
}

int	ft_algo_bis(t_stack *s, int low, int l)
{
	int	z;
	int	ll;

	z = 0;
	if (s->a[1] == low)
		ft_sa(s);
	else
	{
		ll = low + (s->size_a / 5);
		while (ll < s->a[0])
		{
			if ((s->a[0] == l) && (z == 0))
			{
				z = 1;
				ft_pb(s);
			}
			if (ft_fast(s, low))
				ft_ra(s);
			else
				ft_rra(s);
		}
	}
	ft_pb(s);
	return (z);
}

void	ft_algo(t_stack *s)
{
	int	low;
	int	l;
	int	up;

	while (s->size_a > 3)
	{
		low = ft_find_lower(s);
		l = ft_find_l(s, low);
		if (ft_algo_bis(s, low, l) == 1)
			ft_ss(s);
	}
	ft_last(s);
	while (s->size_b > 0)
	{
		up = ft_find_upper(s);
		if (s->b[0] == up)
			ft_pa(s);
		else if (ft_fast_up(s, up))
			ft_rb(s);
		else
			ft_rrb(s);
	}
}
