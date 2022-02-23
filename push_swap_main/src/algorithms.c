/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olugash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:25:42 by olugash           #+#    #+#             */
/*   Updated: 2022/02/21 23:38:40 by olugash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_3(t_list **list)
{
	int	a;
	int	b;
	int	c;

	a = *(int *)(*list)->content;
	b = *(int *)(*list)->next->content;
	c = *(int *)(*list)->next->next->content;
	if ((a > b && b > c) || (b > c && c > a))
	{
		sa(list);
		ft_sort_3(list);
	}
	if (c > a && a > b)
		sa(list);
	if (a > c && c > b)
		ra(list);
	if (b > a && a > c)
		rra(list);
}

static void	ft_push_3_b(t_list **a, t_list **b)
{
	int		count;
	int		size;
	t_list	*elem;

	size = ft_lstsize(*a);
	while (size > 3)
	{
		elem = *a;
		count = 0;
		while (elem)
		{
			if (*(int *)(*a)->content < *(int *)elem->content)
				count++;
			elem = elem->next;
		}
		if (count >= 3)
		{
			pb(b, a);
			size--;
		}
		else
			ra(a);
	}
}

void	ft_sort_less_6(t_list **a, t_list **b)
{
	ft_push_3_b(a, b);
	ft_sort_3(a);
	if ((*b)->next)
		if (*(int *)(*b)->content < *(int *)(*b)->next->content)
			sb(b);
	while (*b)
		pa(a, b);
}

void	ft_final_sort(t_list **a, int min)
{
	t_list	*elem;
	int		size_a;
	int		count_rotate;

	elem = *a;
	count_rotate = 0;
	size_a = ft_lstsize(*a);
	while (*(int *)elem->content != min)
	{
		count_rotate++;
		elem = elem->next;
	}
	if (size_a / 2 > count_rotate)
	{
		while (count_rotate--)
			ra(a);
	}
	else
	{
		count_rotate = size_a - count_rotate;
		while (count_rotate--)
			rra(a);
	}
}

int	ft_sorting(t_list **a, t_list **b)
{
	t_moves	*moves;
	int		min;

	moves = (t_moves *)malloc(sizeof(t_moves));
	if (!moves)
		return (0);
	ft_push_b(a, b, &min);
	ft_sort_3(a);
	ft_push_a(a, b, moves);
	ft_final_sort(a, min);
	free(moves);
	return (1);
}
