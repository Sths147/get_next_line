/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:59:18 by sithomas          #+#    #+#             */
/*   Updated: 2024/12/11 13:50:59 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

int					ft_size_lst(t_list *lst);
int					ft_inspect_content(t_list *lst);
char				*get_next_line(int fd);
void				ft_free_all(t_list **lst);
void				ft_lstadd_back(t_list **lst, char *str, int len);
t_list				*ft_lstlast(t_list *lst);

#endif