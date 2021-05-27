/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivarosic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 17:03:39 by ivarosic          #+#    #+#             */
/*   Updated: 2021/05/27 17:34:41 by ivarosic         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (((str1[i] != '\0') || (str2[i] != '\0')) && i < n)
	{
		if (str1[i] == str2[i])
			i++;
		else
			return (str1[i] - str2[i]);
	}
	return (0);
}

int	ft_mv(char *str)
{
	if (ft_strncmp(str, "sa", 3) && ft_strncmp(str, "sb", 3)
		&& ft_strncmp(str, "pa", 3) && ft_strncmp(str, "pb", 3)
		&& ft_strncmp(str, "ra", 3) && ft_strncmp(str, "rb", 3)
		&& ft_strncmp(str, "rrb", 4) && ft_strncmp(str, "rra", 4)
		&& ft_strncmp(str, "ss", 3) && ft_strncmp(str, "rr", 3)
		&& ft_strncmp(str, "rrr", 4))
		return (0);
	return (1);
}

void	ft_do_mv(t_stack *s, char *mv)
{
	if (!ft_strncmp(mv, "sa", 3))
		ft_sa(s);
	if (!ft_strncmp(mv, "sb", 3))
		ft_sb(s);
	if (!ft_strncmp(mv, "ss", 3))
		ft_ss(s);
	if (!ft_strncmp(mv, "pa", 3))
		ft_pa(s);
	if (!ft_strncmp(mv, "pb", 3))
		ft_pb(s);
	if (!ft_strncmp(mv, "ra", 3))
		ft_ra(s);
	if (!ft_strncmp(mv, "rr", 3))
		ft_rr(s);
	if (!ft_strncmp(mv, "rb", 3))
		ft_rb(s);
	if (!ft_strncmp(mv, "rra", 4))
		ft_rra(s);
	if (!ft_strncmp(mv, "rrb", 4))
		ft_rrb(s);
	if (!ft_strncmp(mv, "rrr", 4))
		ft_rrr(s);
}

int	ft_read(t_stack *s)
{
	char	*buf;

	while (get_next_line(0, &buf))
	{
		ft_do_mv(s, buf);
		if (!ft_mv(buf))
		{
			free(buf);
			return (0);
		}
		if (ft_verif_sort(s) == 1)
			break ;
		free(buf);
	}
	free(buf);
	return (1);
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
		free(s);
		return (0);
	}
	if (ft_read(s) == 0)
	{
		printf("error\n");
		free(s);
		return (0);
	}
	if (ft_verif_sort(s) == 1)
		printf("OK\n");
	else
		printf("KO\n");
	free(s);
	return(0);
}
