/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivarosic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 09:54:25 by ivarosic          #+#    #+#             */
/*   Updated: 2021/05/27 17:15:55 by ivarosic         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <ctype.h>
# define BUFFER_SIZE 32

typedef struct s_stack
{
	int	*a;
	int	size_a;
	int	*b;
	int	size_b;
	int	med;
}				t_stack;

int			get_next_line(int fd, char **line);
int			ft_searchline(const char *s, int c);
char		*ft_strjoin(char *s1, char const *s2);
void		ft_next_line_cut(size_t i, char **line, char *str);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *str);
void		ft_rrr(t_stack *s);
void		ft_rrb(t_stack *s);
void		ft_rra(t_stack *s);
void		ft_rr(t_stack *s);
void		ft_rb(t_stack *s);
void		ft_ra(t_stack *s);
void		ft_pb(t_stack *s);
void		ft_pa(t_stack *s);
void		ft_up_a(t_stack *s);
void		ft_ss(t_stack *s);
void		ft_sb(t_stack *s);
void		ft_sa(t_stack *s);
void		ft_up_a(t_stack *s);
void		ft_up_b(t_stack *s);
void		ft_down_b(t_stack *s);
void		ft_down_a(t_stack *s);
void		ft_swap(int *a, int *b);
void		ft_affiche_stack(t_stack *s);
void		ft_get_median(t_stack *s);
void		ft_first_split(t_stack *s);
int			ft_atoi(const char *str);
long long	ft_lld_atoi(const char *str);
void		ft_algo(t_stack *s);
void		ft_last(t_stack *s);
int			ft_find_lower(t_stack *s);
int			ft_find_upper(t_stack *s);
int			ft_find_l(t_stack *s, int low);
int			ft_verif_sort(t_stack *s);
void		ft_affiche_stack(t_stack *s);
int			ft_init_struct(int ac, char **av, t_stack *s);
void		ft_sort(t_stack *s);
int			ft_a_one(t_stack *s, int b);
void		ft_a_two(t_stack *s, int b);
void		ft_a_three(t_stack *s, int b);
void		ft_a_four(t_stack *s, int b);
void		ft_a_five(t_stack *s, int b);
void		ft_sort_b(t_stack *s, int b);
int			ft_fill(t_stack *s);
int			ft_arg_to_av(char **av, t_stack *s);
int			ft_verif_b(t_stack *s);
int			ft_verif_a(t_stack *s);
int			ft_skip_space(char **av, int i, int j);
int			ft_space(char *str, int i);

#endif
