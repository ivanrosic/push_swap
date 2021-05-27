/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivarosic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:12:21 by ivarosic          #+#    #+#             */
/*   Updated: 2021/05/27 16:23:57 by ivarosic         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_up_a(t_stack *s)
{
	int	i;

	i = s->size_a;
	if (s->size_a >= 1)
	{
		while (i != 0)
		{
			s->a[i] = s->a[i - 1];
			i--;
		}
	}
}

void	ft_down_b(t_stack *s)
{
	int	i;

	i = 1;
	while (i <= s->size_b)
	{
		s->b[i - 1] = s->b[i];
		i++;
	}
}

void	ft_pa(t_stack *s)
{
	if (s->size_b >= 1)
	{
		ft_up_a(s);
		s->a[0] = s->b[0];
		ft_down_b(s);
		s->size_a++;
		s->size_b--;
	}
	printf("pa\n");
}
