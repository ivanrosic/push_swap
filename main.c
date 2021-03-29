/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivarosic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 09:33:41 by ivarosic          #+#    #+#             */
/*   Updated: 2021/03/29 18:10:22 by ivarosic         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_atoi(const char *str)
{
	int i;
	int np;
	int nb;

	nb = 0;
	i = 0;
	np = 0;
	while ((str[i] == '\t') || (str[i] == '\n') || (str[i] == '\v')
			|| (str[i] == '\f') || (str[i] == '\r') || (str[i] == ' '))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			np++;
		i++;
	}
	while (!((str[i] < '0') || (str[i] > '9')))
	{
		nb = nb * 10;
		nb = nb + str[i] - '0';
		i++;
	}
	if (np % 2 == 1)
		return (-nb);
	return (nb);
}

void ft_fill_struct(char **av, t_stack *s)
{
	int i;

	i = 0;
	while(i < s->size_a)
	{
		s->a[i] = ft_atoi(av[i + 1]);
		i++;
	}
}

void	ft_affiche_stack(t_stack *s)
{
	int i;

	i = 0;
	printf("a\tb\n\n");
	while(i < 8)
	{
		if (i < s->size_a)
			printf("%d\t",s->a[i]);
		else
			printf("-\t");
		if (i < s->size_b)
			printf("%d\n",s->b[i]);
		else
			printf("-\n");
		i++;
	}
			printf("\n");
}

void ft_init_struct(int ac, char **av, t_stack *s)
{
	s->a = malloc(sizeof(int) * 8);
	s->b = malloc(sizeof(int) * 8);
	s->size_a = ac - 1;
	s->size_b = 0;
	ft_fill_struct(av, s);
}

int main(int ac, char **av)
{
	t_stack *s;

	if(!(s = malloc(sizeof(t_stack))))
		return(0);
	ft_init_struct(ac, av, s);
	ft_affiche_stack(s);
	ft_sa(s);
	ft_affiche_stack(s);
	ft_pb(s);
	ft_pb(s);
	ft_pb(s);
	ft_affiche_stack(s);
	ft_ra(s);
	ft_rb(s);
	ft_affiche_stack(s);
	ft_rra(s);
	ft_rrb(s);
	ft_affiche_stack(s);
	ft_sa(s);
	ft_affiche_stack(s);
	ft_pa(s);
	ft_pa(s);
	ft_pa(s);
	ft_affiche_stack(s);
}
