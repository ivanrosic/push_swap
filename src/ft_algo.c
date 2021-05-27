#include "push_swap.h"

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
int		ft_find_l(t_stack *s, int low)
{
	int i;
	int l;

	i = 0;
	l = s->a[i];
	if(s->a[i] == low)
		l = s->a[i+1];
		i++;
	while(i < s->size_a)
	{
		if (s->a[i] < l && s->a[i] != low)
			l = s->a[i];
		i++;
	}
	return(l);
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

int ft_fast(t_stack *s, int low)
{
	int i;
	int cpt;

	i = 0;
	while(i < s->size_a)
	{
		if(low == s->a[i])
			cpt = i;
		i++;
	}
	i = i / 2;
	if(i > cpt)
		return(1);
	return(0);
}

void		ft_algo_bis(t_stack *s, int low, int l)
{
	(void)l;
	int z = 0;
	if(s->a[1] == low)
		ft_sa(s);
	else
		while(low != s->a[0])
		{
			if(s->a[0] == l && z == 0)
			{
				z = 1;
				ft_pb(s);
			}
			if(ft_fast(s, low))
				ft_ra(s);
			else
				ft_rra(s);
		}
	ft_pb(s);
	if(z == 1)
	{
		ft_ss(s);
		z = 0;
		}
}

void	ft_algo(t_stack *s)
{
	int low;
	int l;

	while(s->size_a > 3)
	{
		low = ft_find_lower(s);
		l = ft_find_l(s, low);
		ft_algo_bis(s, low, l);
	}
	ft_last(s);
	while(s->size_b > 0)
		ft_pa(s);
}
