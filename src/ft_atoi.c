/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivarosic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:40:12 by ivarosic          #+#    #+#             */
/*   Updated: 2021/05/27 16:41:59 by ivarosic         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_lld_atoi(const char *str)
{
	int			i;
	int			np;
	long long	nb;

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

int	ft_atoi(const char *str)
{
	int	i;
	int	np;
	int	nb;

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
