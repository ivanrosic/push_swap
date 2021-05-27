/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivarosic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:08:25 by ivarosic          #+#    #+#             */
/*   Updated: 2021/05/27 15:08:58 by ivarosic         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *s)
{
	int	tmp;

	tmp = s->a[0];
	ft_down_a(s);
	s->a[s->size_a - 1] = tmp;
	printf("ra\n");
}

void	ft_rb(t_stack *s)
{
	int	tmp;

	tmp = s->b[0];
	ft_down_b(s);
	s->b[s->size_b - 1] = tmp;
	printf("rb\n");
}

void	ft_rr(t_stack *s)
{
	int	tmp;

	tmp = s->a[0];
	ft_down_a(s);
	s->a[s->size_a - 1] = tmp;
	tmp = s->b[0];
	ft_down_b(s);
	s->b[s->size_b - 1] = tmp;
	printf("rr\n");
}
