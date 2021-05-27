/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_a_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivarosic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:11:09 by ivarosic          #+#    #+#             */
/*   Updated: 2021/05/27 16:16:23 by ivarosic         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_a_two(t_stack *s, int b)
{
	if (b == 1 || b == 2 || b == 4)
	{
		ft_ss(s);
		if (b == 1)
			ft_rb(s);
		else if (b == 4)
			ft_rrb(s);
	}
	else
	{
		ft_sa(s);
		ft_sort_b(s, b);
	}
}

void	ft_a_three(t_stack *s, int b)
{
	if (b == 3)
		ft_rrr(s);
	else
	{
		ft_sort_b(s, b);
		ft_rra(s);
	}
}

void	ft_a_four(t_stack *s, int b)
{
	if (b == 5)
	{
		ft_rr(s);
		ft_sa(s);
	}
	else
	{
		ft_sort_b(s, b);
		ft_ra(s);
		ft_sa(s);
	}
}

void	ft_a_five(t_stack *s, int b)
{
	if (b == 5)
		ft_rr(s);
	else
	{
		ft_sort_b(s, b);
		ft_ra(s);
	}
}
