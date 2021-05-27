/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivarosic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:11:32 by ivarosic          #+#    #+#             */
/*   Updated: 2021/05/27 16:23:46 by ivarosic         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_down_a(t_stack *s)
{
	int	i;

	i = 1;
	while (i <= s->size_a)
	{
		s->a[i - 1] = s->a[i];
		i++;
	}
}

void	ft_up_b(t_stack *s)
{
	int	i;

	i = s->size_b;
	if (s->size_b >= 1)
	{
		while (i != 0)
		{
			s->b[i] = s->b[i - 1];
			i--;
		}
	}
}

void	ft_pb(t_stack *s)
{
	if (s->size_a >= 1)
	{
		ft_up_b(s);
		s->b[0] = s->a[0];
		ft_down_a(s);
		s->size_b++;
		s->size_a--;
	}
	printf("pb\n");
}
