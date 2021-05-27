/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_on_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivarosic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 09:52:31 by ivarosic          #+#    #+#             */
/*   Updated: 2021/05/27 11:09:48 by ivanrosic    ###    #+. /#+    ###.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_low(t_stack *s)
{
	int i;
	int low;

	i = 0;
	low = ft_find_lower(s);
	//ft_affiche_stack(s);
	while(i < 4 && s->size_a > 3)
	{
		if(s->a[i] == low)
			ft_pb(s);
		ft_ra(s);
	}
}

void	ft_first_split(t_stack *s)
{
	int i;
	int size;


	size = s->size_a;
	i = 0;
	if(size == 4)
		ft_low(s);
	else
	{
		while (i < size)
		{
			if (s->size_a == 3)
				break;
			else if(s->a[0] <= s->med)
				ft_pb(s);
			else
			{
				if(s->a[0] > s->a[1]) 
					ft_ra(s);
				else
					ft_rr(s);
			}
			i++;
		}
	}
}
