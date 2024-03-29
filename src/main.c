/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivarosic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 09:33:41 by ivarosic          #+#    #+#             */
/*   Updated: 2021/05/27 18:06:16 by ivarosic         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lauch(t_stack *s)
{
	if (s->size_a <= 6)
	{
		if (s->size_a >= 3)
		{
			ft_get_median(s);
			ft_first_split(s);
		}
		ft_sort(s);
		while (s->size_b > 0)
			ft_pa(s);
	}
	else
		ft_algo(s);
}

void ft_free_all(t_stack *s)
{
	free(s->a);
	free(s->b);
	free(s);
}

int	main(int ac, char **av)
{
	t_stack	*s;
	int		r;

	if (ac == 1)
		return (1);
	s = malloc(sizeof(t_stack));
	if (ac == 2)
		r = ft_arg_to_av(av, s);
	else
		r = ft_init_struct(ac, av, s);
	if (r == 1)
	{
		printf("error\n");
		ft_free_all(s);
		return (0);
	}
	if (ft_verif_sort(s) == 1)
	{
		ft_free_all(s);
		return (0);
	}
	ft_lauch(s);
	ft_free_all(s);
	return (0);
}
