/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivarosic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 09:33:41 by ivarosic          #+#    #+#             */
/*   Updated: 2021/05/26 20:18:56 by ivarosic         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_lld_atoi(const char *str)
{
	int i;
	int np;
	long long nb;

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

int ft_fill_struct(char **av, t_stack *s)
{
	int i;
	long long tmp;
	int j;

	i = 1;
	while(i < s->size_a + 1)
	{
		j = 0;
		while(av[i][j])
		{
			while ((av[i][j] == '\t') || (av[i][j] == '\n') || (av[i][j] == '\v')
					|| (av[i][j] == '\f') || (av[i][j] == '\r') || (av[i][j] == ' '))
				j++;
			if((av[i][j] < '0' || av[i][j] > '9'))
				if(av[i][j] != '-' && av[i][j] != '+')
					return(1);
			j++;
		}
		tmp = ft_lld_atoi(av[i]);
		if (tmp > 2147483647 || tmp < -2147483648)
			return(1);
		s->a[i - 1] = ft_atoi(av[i]);
		j = 0;
		while(j < i - 1)
		{
			if(s->a[i - 1] == s->a[j])
				return(1);
			j++;
		}
		i++;
	}
	i = 1;
	j = s->a[0];
	while(i < s->size_a)
	{
		if(j > s->a[i])
			return(0);
		i++;
	}
	return(2);
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

int ft_init_struct(int ac, char **av, t_stack *s)
{
	s->a = malloc(sizeof(int) * (ac - 1));
	s->b = malloc(sizeof(int) * (ac - 1));
	s->size_a = ac - 1;
	s->size_b = 0;
	return(ft_fill_struct(av, s));
}

int ft_verif_a(t_stack *s)
{
	if(s->a[0] < s->a[1] && s->a[1] < s->a[2])
		return(0);
	if(s->a[0] < s->a[1] && s->a[0] < s->a[2])
		return(1);
	if(s->a[0] > s->a[1] && s->a[0] > s->a[2] && s->a[1] > s->a[2])
		return(4);
	if(s->a[0] > s->a[1] && s->a[0] > s->a[2])
		return(5);
	if(s->a[1] > s->a[2])
		return(3);
	return(2);
}

int ft_verif_b(t_stack *s)
{
	if(s->b[0] > s->b[1] && s->b[1] > s->b[2])
		return(0);
	if(s->b[0] > s->b[1] && s->b[0] > s->b[2])
		return(1);
	if(s->b[0] < s->b[1] && s->b[0] < s->b[2] && s->b[1] < s->b[2])
		return(4);
	if(s->b[0] < s->b[1] && s->b[0] < s->b[2])
		return(5);
	if(s->b[1] < s->b[2])
		return(3);
	return(2);
	return(-1);
}
void	ft_sort_b(t_stack *s, int b)
{
	if(b == 0)
		;
	else if(b == 1)
	{
		ft_sb(s);
		ft_rb(s);
	}
	else if(b == 2)
		ft_sb(s);
	else if(b == 3)
		ft_rrb(s);
	else if(b == 4)
	{
		ft_sb(s);
		ft_rrb(s);
	}
	else if(b == 5)
		ft_rb(s);

}
void	ft_sort(t_stack *s)
{
	int b;
	int a;

	ft_affiche_stack(s);
	b = ft_verif_b(s);
	a = ft_verif_a(s);
	printf("a=%d\tb=%d\n",a,b);
	if(a == 0)
		ft_sort(s, b);
	else if(a == 1)
	{
		if(b == 1)
		{
			ft_s(s);
			ft_rr(s);
			b = 0;
		}
		else
		{
			if(b == 2 || b == 4)
			{
				ft_ss(s);
				if(b == 4)
					ft_rrb(s);
				b = 0;
			}
			else if (b == 5)
			{
				ft_sa(s);
				ft_rr(s);	
			}
			else{
				ft_sa(s);
			ft_ra(s);
			}
		}
	}
	else if(a == 2)
	{
		if(b == 1 || b == 2 || b == 4)
		{
			ft_ss(s);
		}
		ft_sa(s);
	}
	else if(a == 3)
		ft_rra(s);
	else if(a == 4)
	{
		ft_ra(s);
		ft_sa(s);
	}
	else if(a == 5)
		ft_ra(s);

}

int		ft_count_nb(char *str)
{
	int i;
	int cpt;

	i = 0;
	cpt = 0;
	while(str[i])
	{
		if(str[i] >= '0' && str[i] <= '9')
		{
			while(str[i] >= '0' && str[i] <= '9')
				i++;
			cpt++;
		}
		i++;
	}
	return(cpt);
}

int	ft_arg_to_av(char **av, t_stack *s)
{

	s->size_a = ft_count_nb(av[1]);
	s->size_b = 0;
	s->a = malloc(sizeof(int) * (s->size_a));
	s->b = malloc(sizeof(int) * (s->size_a));

	return(0);
}

int ft_checker(int ac, char **av, t_stack *s)
{
	(void)ac;
	if(ft_arg_to_av(av, s) == 1)
		return(1);
	return(0);
}

int		ft_find_lower(t_stack *s)
{
	int i;
	int low;

	i = 0;
	low = s->a[0];
	while(i < s->size_a)
	{
		if (s->a[i] < low)
			low = s->a[i];
		i++;
	}
	return(low);
}

void	ft_last(t_stack *s)
{
	if(s->a[0] < s->a[1] && s->a[0] < s->a[2] && s->a[1] > s->a[2])
		ft_sa(s);
	if(s->a[0] > s->a[1] && s->a[0] > s->a[2])
		ft_ra(s);
	if(s->a[2] < s->a[1] && s->a[2] < s->a[0])
		ft_rra(s);
	if(s->a[0] > s->a[1])
		ft_sa(s);
	if(s->a[2] > s->a[1] && s->a[2] > s->a[0] && s->a[1] < s->a[0])
		ft_sa(s);
}

void	ft_algo(t_stack *s)
{
	int low;
	//	ft_affiche_stack(s);
	while(s->size_a > 3)
	{
		low = ft_find_lower(s);
		if(s->a[1] == low)
			ft_sa(s);
		else
			while(low != s->a[0])
			{
				ft_ra(s);
				//	ft_affiche_stack(s);
			}
		ft_pb(s);

		//	printf("low:%d\n", low);
		//	ft_affiche_stack(s);
	}
	ft_last(s);
	while(s->size_b > 0)
		ft_pa(s);
}

int main(int ac, char **av)
{
	t_stack *s;
	int v;
	int r;

	if(ac == 1)
		return(1);
	s = malloc(sizeof(t_stack));
	r = ft_init_struct(ac, av, s);
	//	ft_affiche_stack(s);
	if(r == 1)
	{
		printf("error\n");
		return(0);
	}
	//	else if (r == 2)
	//		return(0);

	if (s->size_a <= 6)
	{
		if(s->size_a >= 3)
		{
			ft_get_median(s);
			ft_first_split(s);
		}
		ft_sort(s);
		while(s->size_b > 0)
			ft_pa(s);
	}
	else
		ft_algo(s);
	ft_affiche_stack(s);
	int z;
	int mx;

	z = 0;
	mx = s->a[0];
	while(z < s->size_a)
	{
		if(s->a[z] < mx)
			return(0);
		mx = s->a[z];
		z++;
	}
	printf("OK\n");


	//	ft_affiche_stack(s);
	return(0);
}
