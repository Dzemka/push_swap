/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olugash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 01:46:48 by olugash           #+#    #+#             */
/*   Updated: 2022/02/22 01:47:01 by olugash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H

# define CHECKER_BONUS_H

# include "../libft/libft.h"

int	swap(t_list **list);
int	push(t_list **src, t_list **dst);
int	rotate(t_list **list);
int	reverse_rotate(t_list **list);
int	ft_fill_stack(int argc, char **argv, t_list **a);
int	ft_is_sorting(t_list **a, t_list **b, t_list **list);

#endif
