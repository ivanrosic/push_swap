/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_a_five_bis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivarosic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:15:58 by ivarosic          #+#    #+#             */
/*   Updated: 2021/05/27 16:17:46 by ivarosic         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_a_one_bis(t_stack *s, int b)
{
	if (b == 2 || b == 4)
	{
		ft_ss(s);
		if (b == 4)
			ft_rrb(s);
		b = 0;
	}
	else if (b == 5)
	{
		ft_sa(s);
		ft_rr(s);
	}
	else
	{
		ft_sa(s);
		ft_ra(s);
	}
	return (b);
}

int	ft_a_one(t_stack *s, int b)
{
	if (b == 1)
	{
		ft_sb(s);
		ft_rr(s);
		b = 0;
	}
	else
	{
		b = ft_a_one_bis(s, b);
	}
	return (b);
}
