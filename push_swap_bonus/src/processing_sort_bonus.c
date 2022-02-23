/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_sort_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olugash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 01:44:42 by olugash           #+#    #+#             */
/*   Updated: 2022/02/22 01:45:46 by olugash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

static int	ft_check_sort(t_list *list)
{
	t_list	*elem;

	elem = list;
	while (elem->next)
	{
		if (*(int *)elem->content > *(int *)elem->next->content)
			return (0);
		elem = elem->next;
	}
	return (1);
}

int	ft_select_double_move(t_list **a, t_list **b, t_list *el)
{
	if (!ft_strncmp("ss\n", (char *)el->content, 3))
	{
		if (swap(a))
			return (swap(b));
	}
	else if (!ft_strncmp("rr\n", (char *)el->content, 3))
	{
		if (rotate(a))
			return (rotate(b));
	}
	else if (!ft_strncmp("rrr\n", (char *)el->content, 4))
	{
		if (reverse_rotate(a))
			return (reverse_rotate(b));
	}
	return (0);
}

int	ft_select_move(t_list **a, t_list **b, t_list *el)
{
	if (!ft_strncmp("sa\n", (char *)el->content, 3))
		return (swap(a));
	else if (!ft_strncmp("sb\n", (char *)el->content, 3))
		return (swap(b));
	else if (!ft_strncmp("ra\n", (char *)el->content, 3))
		return (rotate(a));
	else if (!ft_strncmp("rb\n", (char *)el->content, 3))
		return (rotate(b));
	else if (!ft_strncmp("rra\n", (char *)el->content, 4))
		return (reverse_rotate(a));
	else if (!ft_strncmp("rrb\n", (char *)el->content, 4))
		return (reverse_rotate(b));
	else if (!ft_strncmp("pb\n", (char *)el->content, 3))
		return (push(a, b));
	else if (!ft_strncmp("pa\n", (char *)el->content, 3))
		return (push(b, a));
	else
		return (ft_select_double_move(a, b, el));
}

int	ft_is_sorting(t_list **a, t_list **b, t_list **list)
{
	t_list	*el;

	el = *list;
	while (el->content)
	{
		if (!ft_select_move(a, b, el))
			return (-1);
		el = el->next;
	}
	if (ft_check_sort(*a) && !*b)
		return (1);
	return (0);
}
