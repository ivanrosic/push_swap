/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_on_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivarosic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 09:52:31 by ivarosic          #+#    #+#             */
/*   Updated: 2021/03/30 14:09:08 by ivarosic         ###   ########lyon.fr   */
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
		if(s->a[0] < s->med)
			ft_pb(s);
		else
			ft_ra(s);
		i++;
	}
}
