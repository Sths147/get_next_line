/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:59:18 by sithomas          #+#    #+#             */
/*   Updated: 2024/12/10 17:52:18 by sithomas         ###   ########.fr       */
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

int					ft_inspect_content(t_list *lst);
char				*get_next_line(int fd);
void				ft_fill_my_stash(t_list **stash, int fd, char *leftover);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, char *str, int len);
int					ft_size_lst(t_list *lst);
char				*ft_fill_this_str(t_list **stash);
t_list				*ft_clean_list(t_list **lst);
char				*ft_leftover(t_list **lst, char *leftover);
void				ft_free_all(t_list **lst);
void				ft_assign(char *str, t_list **lst);

#endif