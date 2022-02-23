/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olugash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 01:39:01 by olugash           #+#    #+#             */
/*   Updated: 2022/02/22 01:41:24 by olugash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

int	swap(t_list **list)
{
	t_list	*elem;

	if (ft_lstsize(*list) < 2)
		return (0);
	elem = *list;
	elem = elem->next;
	(*list)->next = (*list)->next->next;
	elem->next = (*list);
	(*list) = elem;
	return (1);
}

int	push(t_list **src, t_list **dst)
{
	t_list	*elem;

	if (!*src)
		return (0);
	elem = (*src)->next;
	(*src)->next = (*dst);
	*dst = *src;
	*src = elem;
	return (1);
}

int	rotate(t_list **list)
{
	t_list	*elem;

	if (ft_lstsize(*list) < 2)
		return (0);
	elem = *list;
	ft_lstadd_back(list, elem);
	*list = (*list)->next;
	elem->next = NULL;
	return (1);
}

int	reverse_rotate(t_list **list)
{
	t_list	*elem;
	t_list	*temp;

	if (ft_lstsize(*list) < 2)
		return (0);
	elem = ft_lstlast(*list);
	temp = *list;
	while (temp->next != elem)
		temp = temp->next;
	temp->next = NULL;
	ft_lstadd_front(list, elem);
	return (1);
}
