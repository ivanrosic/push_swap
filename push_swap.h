/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivarosic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 09:54:25 by ivarosic          #+#    #+#             */
/*   Updated: 2021/04/12 08:29:55 by ivarosic         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack
{
	int *a;
	int size_a;
	int *b;
	int size_b;
	int med;
}				t_stack;

	void	ft_rrr(t_stack *s);
	void	ft_rrb(t_stack *s);
	void	ft_rra(t_stack *s);
	void	ft_rr(t_stack *s);
	void	ft_rb(t_stack *s);
	void	ft_ra(t_stack *s);
	void	ft_pb(t_stack *s);
	void	ft_pa(t_stack *s);
	void	ft_up_a(t_stack *s);
	void	ft_ss(t_stack *s);
	void	ft_sb(t_stack *s);
	void	ft_sa(t_stack *s);
	void	ft_swap(int *a, int *b);
	void	ft_affiche_stack(t_stack *s);
	void	ft_get_median(t_stack *s);
	void	ft_first_split(t_stack *s);


#endif
