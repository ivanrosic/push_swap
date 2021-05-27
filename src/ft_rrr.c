/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivarosic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:07:30 by ivarosic          #+#    #+#             */
/*   Updated: 2021/05/27 15:08:10 by ivarosic         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack *s)
{
	int	tmp;

	tmp = s->a[s->size_a - 1];
	ft_up_a(s);
	s->a[0] = tmp;
	printf("rra\n");
}

void	ft_rrb(t_stack *s)
{
	int	tmp;

	tmp = s->b[s->size_b - 1];
	ft_up_b(s);
	s->b[0] = tmp;
	printf("rrb\n");
}

void	ft_rrr(t_stack *s)
{
	int	tmp;

	tmp = s->a[s->size_a - 1];
	ft_up_a(s);
	s->a[0] = tmp;
	tmp = s->b[s->size_b - 1];
	ft_up_b(s);
	s->b[0] = tmp;
	printf("rrr\n");
}
