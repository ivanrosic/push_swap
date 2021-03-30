/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivarosic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 09:33:41 by ivarosic          #+#    #+#             */
/*   Updated: 2021/03/30 18:21:05 by ivarosic         ###   ########lyon.fr   */
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
	int mx;

	i = 0;
	mx = s->size_a;
	if (s->size_b > mx)
		mx = s->size_b;
	printf("a\tb\n\n");
	while(i < mx)
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
	s->a = malloc(sizeof(int) * (ac - 1));
	s->b = malloc(sizeof(int) * (ac - 1));
	s->size_a = ac - 1;
	s->size_b = 0;
	ft_fill_struct(av, s);
}

int ft_verif_a(t_stack *s)
{
	if(s->size_a == 2)
	{
		if(s->a[0] > s->a[1])
			return(1);
	}
	else if (s->size_a == 3)
	{
		if(s->a[0] > s->a[2])
		{
			if(s->a[0] > s->a[1])
				return(1);
			else
				return(2);
		}
		else
		{
			if (s->a[2] > s->a[1]  && s->a[1] > s->a[0])
				return(0);
			else
				return(3);
		}
	}
	return(0);
}

int ft_verif_b(t_stack *s)
{
	if(s->size_b == 2)
	{
		if(s->b[0] < s->b[1])
			return(4);
	}
	else if (s->size_b == 3)
	{
		if(s->b[0] < s->b[2])
		{
			if(s->b[0] > s->b[1])
				return(1);
			else
				return(2);
		}
		else
		{
			if (s->b[2] < s->b[1]  && s->b[1] < s->b[0])
				return(0);
			else
				return(3);
		}
	}
	return(0);
}

void	ft_sort(t_stack *s)
{
	int b;
	int a;

	while(ft_verif_a(s) != 0 || ft_verif_b(s) != 0)
	{
		b = ft_verif_b(s);
		a = ft_verif_a(s);
		if(b == 0)
		;
		if(ft_verif_a(s) == 0)
		;
		else if(ft_verif_a(s) == 1)
		{
			if(b == 2 || b == 4)
			{
				ft_rr(s);
				b = 0;
			}
			else
				ft_ra(s);
		}
		else if(ft_verif_a(s) == 2)
		{	
			if(b == 1 || b == 4)
			{
				ft_rrr(s);
				b = 0;
			}
			else
				ft_rra(s);
		}
		else if(ft_verif_a(s) == 3)
		{
			if(b == 3 || b == 4)
			{
				ft_ss(s);
				b = 0;
			}
			else
				ft_sa(s);
		}
		if(b == 1)
		{
			ft_rrb(s);
		}
		else if(b == 2)
		{	
			ft_rb(s);
		}
		else if(b == 3)
		{
			ft_sb(s);
		}
	}
}

int main(int ac, char **av)
{
	t_stack *s;
	int v;

	if(!(s = malloc(sizeof(t_stack))))
		return(0);
	ft_init_struct(ac, av, s);
//		ft_affiche_stack(s);
	if (s->size_a <= 6)
	{
		if(s->size_a > 3)
		{
			ft_get_median(s);
			ft_first_split(s);
		}
		ft_sort(s);
		while(s->size_b > 0)
			ft_pa(s);
	}
//		ft_affiche_stack(s);
}
