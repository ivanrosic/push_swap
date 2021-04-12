/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_on_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivarosic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 09:52:31 by ivarosic          #+#    #+#             */
/*   Updated: 2021/04/12 11:11:16 by ivarosic         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_first_split(t_stack *s)
{
	int i;
	int size;

	size = s->size_a;
	i = 0;
	while (i < size)
	{
		if (s->size_a == 3)
			break;
		if(s->a[0] <= s->med)
			ft_pb(s);
		else
		{
			if(s->b[0] > s->b[1]) 
			ft_ra(s);
			else
			ft_rr(s);
		}
		i++;
	}
}
