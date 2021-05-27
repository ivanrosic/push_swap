/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivarosic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:19:36 by ivarosic          #+#    #+#             */
/*   Updated: 2021/05/27 16:23:23 by ivarosic         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_b(t_stack *s, int b)
{
	if (b == 0)
		;
	else if (b == 1)
	{
		ft_sb(s);
		ft_rb(s);
	}
	else if (b == 2)
		ft_sb(s);
	else if (b == 3)
		ft_rrb(s);
	else if (b == 4)
	{
		ft_sb(s);
		ft_rrb(s);
	}
	else if (b == 5)
		ft_rb(s);
}

int	ft_init_sortb(t_stack *s)
{
	int	b;

	if (s->size_b == 3)
		b = ft_verif_b(s);
	else if (s->size_b == 2 && s->b[0] < s->b[1])
		b = 2;
	else
		b = 0;
	return (b);
}

int	ft_init_sorta(t_stack *s)
{
	int	a;

	if (s->size_a == 3)
		a = ft_verif_a(s);
	else
		a = 2;
	return (a);
}

void	ft_sort(t_stack *s)
{
	int	b;
	int	a;

	b = ft_init_sortb(s);
	a = ft_init_sorta(s);
	if (a == 0)
		ft_sort_b(s, b);
	else if (a == 1)
		b = ft_a_one(s, b);
	else if (a == 2)
		ft_a_two(s, b);
	else if (a == 3)
		ft_a_three(s, b);
	else if (a == 4)
		ft_a_four(s, b);
	else if (a == 5)
		ft_a_five(s, b);
}
