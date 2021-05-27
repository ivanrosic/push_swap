#include "push_swap.h"

int ft_verif_sort(t_stack *s)
{
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
	if(s->size_b == 0)
	return(1);
	return(0);
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
