/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivarosic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 10:35:16 by ivarosic          #+#    #+#             */
/*   Updated: 2021/05/27 11:15:19 by ivanrosic    ###    #+. /#+    ###.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int c;

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

void	ft_up_a(t_stack *s)
{
	int i;

	i = s->size_a;
	if (s->size_a >= 1)
	{
		while(i != 0)
		{
			s->a[i] = s->a[i - 1];
			i--;
		}
	}
}

void	ft_down_b(t_stack *s)
{
	int i;

	i = 1;
	while(i <= s->size_b)
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

void	ft_down_a(t_stack *s)
{
	int i;

	i = 1;
	while(i <= s->size_a)
	{
		s->a[i - 1] = s->a[i];
		i++;
	}
}

void	ft_up_b(t_stack *s)
{
	int i;

	i = s->size_b;
	if (s->size_b >= 1)
	{
		while(i != 0)
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

void	ft_ra(t_stack *s)
{
	int tmp;

	tmp = s->a[0];
	ft_down_a(s);
	s->a[s->size_a - 1] = tmp;
	printf("ra\n");
}

void	ft_rb(t_stack *s)
{
	int tmp;

	tmp = s->b[0];
	ft_down_b(s);
	s->b[s->size_b - 1] = tmp;
	printf("rb\n");
}

void	ft_rr(t_stack *s)
{
	int tmp;

	tmp = s->a[0];
	ft_down_a(s);
	s->a[s->size_a - 1] = tmp;
	tmp = s->b[0];
	ft_down_b(s);
	s->b[s->size_b - 1] = tmp;
	printf("rr\n");
}

void	ft_rra(t_stack *s)
{
	int tmp;

	tmp = s->a[s->size_a - 1];
	ft_up_a(s);
	s->a[0] = tmp;
	printf("rra\n");
}

void	ft_rrb(t_stack *s)
{
	int tmp;

	tmp = s->b[s->size_b - 1];
	ft_up_b(s);
	s->b[0] = tmp;
	printf("rrb\n");
}

void	ft_rrr(t_stack *s)
{
	int tmp;

	tmp = s->a[s->size_a - 1];
	ft_up_a(s);
	s->a[0] = tmp;
	tmp = s->b[s->size_b - 1];
	ft_up_b(s);
	s->b[0] = tmp;
	printf("rrr\n");
}
