/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olugash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 01:50:38 by olugash           #+#    #+#             */
/*   Updated: 2022/02/22 01:52:47 by olugash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <stdlib.h>

# include <unistd.h>

# include "libft.h"

typedef struct s_gnl
{
	char	*new_line;
	char	*end_line;
}	t_gnl;

typedef struct s_list_gnl
{
	int					fd;
	char				*remaining_str;
	struct s_list_gnl	*next;
}	t_list_gnl;

char		*get_next_line(int fd);
char		*ft_strchr(const char *str, int c);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strdup(const char *s1);
char		*ft_build_line(char *str1, char *str2, char *end_line);
t_list_gnl	*ft_lst_new(int fd);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif
