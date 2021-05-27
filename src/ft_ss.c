/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivarosic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:04:47 by ivarosic          #+#    #+#             */
/*   Updated: 2021/05/27 15:06:46 by ivarosic         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_sa(t_stack *s)
{
	if (s->size_a >= 2)
		ft_swap(&s->a[0], &s->a[1]);
	printf("sa\n");
}

void	ft_sb(t_stack *s)
{
	if (s->size_b >= 2)
		ft_swap(&s->b[0], &s->b[1]);
	printf("sb\n");
}

void	ft_ss(t_stack *s)
{
	if (s->size_a >= 2)
		ft_swap(&s->a[0], &s->a[1]);
	if (s->size_b >= 2)
		ft_swap(&s->b[0], &s->b[1]);
	printf("ss\n");
}
