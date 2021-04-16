/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivarosic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 08:49:38 by ivarosic          #+#    #+#             */
/*   Updated: 2021/04/16 08:09:57 by ivarosic         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_median(t_stack *s)
{
	int tmp[s->size_a];
	int i;

	i = 0;
	while(i < s->size_a)
	{
		tmp[i] = s->a[i];
		i++;
	}
	i = 1;
	while(i < s->size_a)
	{
		if(tmp[i - 1] > tmp[i])
		{
			ft_swap(&tmp[i - 1], &tmp[i]);
			i = 1;
		}
		else
			i++;
	}
	if(i % 2 == 1)
	s->med = tmp[i / 2];
	else
	s->med = tmp[(i / 2) - 1];
}
