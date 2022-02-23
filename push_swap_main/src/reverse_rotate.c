/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olugash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 01:11:02 by olugash           #+#    #+#             */
/*   Updated: 2022/02/22 01:12:12 by olugash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_list **list)
{
	t_list	*elem;
	t_list	*temp;

	elem = ft_lstlast(*list);
	temp = *list;
	while (temp->next != elem)
		temp = temp->next;
	temp->next = NULL;
	ft_lstadd_front(list, elem);
}

void	rra(t_list **a)
{
	reverse_rotate(a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_list **b)
{
	reverse_rotate(b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putstr_fd("rrr\n", 1);
}
