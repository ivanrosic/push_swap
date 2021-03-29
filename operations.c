/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivarosic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 10:35:16 by ivarosic          #+#    #+#             */
/*   Updated: 2021/03/29 16:23:49 by ivarosic         ###   ########lyon.fr   */
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
}

void	ft_sb(t_stack *s)
{
	if (s->size_b >= 2)
		ft_swap(&s->b[0], &s->b[1]);
}

void	ft_ss(t_stack *s)
{
	ft_sa(s);
	ft_sb(s);
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
}

void	ft_ra(t_stack *s)
{
	int tmp;

	tmp = s->a[0];
	ft_down_a(s);
	s->a[s->size_a - 1] = tmp;
}

void	ft_rb(t_stack *s)
{
	int tmp;

	tmp = s->b[0];
	ft_down_b(s);
	s->b[s->size_b - 1] = tmp;
}

void	ft_rr(t_stack *s)
{
	ft_ra(s);
	ft_rb(s);
}

void	ft_rra(t_stack *s)
{
	int tmp;

	tmp = s->a[s->size_a - 1];
	ft_up_a(s);
	s->a[0] = tmp;
}

void	ft_rrb(t_stack *s)
{
	int tmp;

	tmp = s->b[s->size_b - 1];
	ft_up_b(s);
	s->b[0] = tmp;
}

void	ft_rrr(t_stack *s)
{
	ft_rra(s);
	ft_rrb(s);
}
