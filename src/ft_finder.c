/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finder.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivarosic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:47:53 by ivarosic          #+#    #+#             */
/*   Updated: 2021/05/27 16:48:33 by ivarosic         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_lower(t_stack *s)
{
	int	i;
	int	low;

	i = 0;
	low = s->a[0];
	while (i < s->size_a)
	{
		if (s->a[i] < low)
			low = s->a[i];
		i++;
	}
	return (low);
}

int	ft_find_upper(t_stack *s)
{
	int	i;
	int	up;

	i = 0;
	up = s->b[0];
	while (i < s->size_b)
	{
		if (s->b[i] > up)
			up = s->b[i];
		i++;
	}
	return (up);
}

int	ft_find_l(t_stack *s, int low)
{
	int	i;
	int	l;

	i = 0;
	l = s->a[i];
	if (s->a[i] == low)
		l = s->a[i + 1];
	i++;
	while (i < s->size_a)
	{
		if (s->a[i] < l && s->a[i] != low)
			l = s->a[i];
		i++;
	}
	return (l);
}
