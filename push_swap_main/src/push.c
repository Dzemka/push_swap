/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olugash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 01:10:22 by olugash           #+#    #+#             */
/*   Updated: 2022/02/22 01:10:34 by olugash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_list **src, t_list **dst)
{
	t_list	*elem;

	elem = (*src)->next;
	(*src)->next = (*dst);
	*dst = *src;
	*src = elem;
}

void	pa(t_list **a, t_list **b)
{
	push(b, a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_list **b, t_list **a)
{
	push(a, b);
	ft_putstr_fd("pb\n", 1);
}
