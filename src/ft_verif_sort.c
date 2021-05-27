/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivarosic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:09:18 by ivarosic          #+#    #+#             */
/*   Updated: 2021/05/27 16:21:56 by ivarosic         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_verif_a(t_stack *s)
{
	if (s->a[0] < s->a[1] && s->a[1] < s->a[2])
		return (0);
	if (s->a[0] < s->a[1] && s->a[0] < s->a[2])
		return (1);
	if (s->a[0] > s->a[1] && s->a[0] > s->a[2] && s->a[1] > s->a[2])
		return (4);
	if (s->a[0] > s->a[1] && s->a[0] > s->a[2])
		return (5);
	if (s->a[1] > s->a[2])
		return (3);
	return (2);
}

int	ft_verif_b(t_stack *s)
{
	if (s->b[0] > s->b[1] && s->b[1] > s->b[2])
		return (0);
	if (s->b[0] > s->b[1] && s->b[0] > s->b[2])
		return (1);
	if (s->b[0] < s->b[1] && s->b[0] < s->b[2] && s->b[1] < s->b[2])
		return (4);
	if (s->b[0] < s->b[1] && s->b[0] < s->b[2])
		return (5);
	if (s->b[1] < s->b[2])
		return (3);
	return (2);
}

int	ft_verif_sort(t_stack *s)
{
	int	z;
	int	mx;

	z = 0;
	mx = s->a[0];
	while (z < s->size_a)
	{
		if (s->a[z] < mx)
			return (0);
		mx = s->a[z];
		z++;
	}
	if (s->size_b == 0)
		return (1);
	return (0);
}

void	ft_affiche_stack(t_stack *s)
{
	int	i;
	int	mx;

	i = 0;
	mx = s->size_a;
	if (s->size_b > mx)
		mx = s->size_b;
	printf("a\tb\n\n");
	while (i < mx)
	{
		if (i < s->size_a)
			printf("%d\t", s->a[i]);
		else
			printf("-\t");
		if (i < s->size_b)
			printf("%d\n", s->b[i]);
		else
			printf("-\n");
		i++;
	}
	printf("\n");
}
