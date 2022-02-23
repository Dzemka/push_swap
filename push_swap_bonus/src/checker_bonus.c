/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olugash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 01:26:23 by olugash           #+#    #+#             */
/*   Updated: 2022/02/22 01:27:35 by olugash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

static int	ft_fill_command(t_list **list)
{
	t_list	*el;

	el = *list;
	el = ft_lstnew(get_next_line(0));
	if (!el)
		return (0);
	ft_lstadd_back(list, el);
	while (el->content)
	{
		el = ft_lstnew(get_next_line(0));
		if (!el)
			return (0);
		ft_lstadd_back(list, el);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*list;
	t_list	*a;
	t_list	*b;
	int		is_error;

	is_error = 2;
	list = NULL;
	a = NULL;
	b = NULL;
	if (ft_fill_command(&list) && ft_fill_stack(argc, argv, &a))
	{
		if (ft_lstsize(a) > 1)
			is_error = ft_is_sorting(&a, &b, &list);
		if (!is_error)
			ft_putstr_fd("KO\n", 1);
		else if (is_error == 1)
			ft_putstr_fd("OK\n", 1);
	}
	else
		is_error = -1;
	if (is_error == -1)
		ft_putstr_fd("Error\n", 1);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	ft_lstclear(&list, free);
}
