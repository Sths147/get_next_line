/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:59:33 by sithomas          #+#    #+#             */
/*   Updated: 2024/12/10 17:50:23 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/*
To produce this fuction, here is what I will do:
1. Go through my fd while and fill my chained list of buffer 
size while there is no
	/n
2. Once my chained list is filled, I will :
	* Calculate the length of my list
	* Allocate a str (Result) that has the length of my list * BUFFER SIZE
	* paste the results in the str
3. Clear the list so :
	* append what is after the \n to the end of my list
	* clear everything until the last node
	* last-> node  = head.
*/
char	*get_next_line(int fd)
{
	t_list		*stash;
	char		*result;
	static char	leftover[BUFFER_SIZE + 1];

	result = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (leftover[0] == '\0')
		stash = NULL;
	else
	{
		stash = malloc(sizeof(t_list));
		if (!stash)
			return (NULL);
		ft_assign(leftover, &stash);
	}
	ft_fill_my_stash(&stash, fd, leftover);
	if (!stash)
		return (NULL);
	result = ft_fill_this_str(&stash);
	ft_leftover(&stash, leftover);
	ft_free_all(&stash);
	return (result);
}

/*
 fills the list while there is no \n
*/

void	ft_assign(char str[BUFFER_SIZE + 1], t_list **lst)
{
	int	i;

	i = 0;
	if (!*lst)
		return ;
	(*lst)->content = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!(*lst)->content)
		return (ft_free_all(lst));
	while (i < BUFFER_SIZE && str[i] != '\0')
	{
		(*lst)->content[i] = str[i];
		i++;
	}
	(*lst)->content[i] = '\0';
	(*lst)->next = NULL;
}

void	ft_fill_my_stash(t_list **stash, int fd, char leftover[BUFFER_SIZE + 1])
{
	char	*temp;
	int		bytes_read;

	bytes_read = 1;
	while ((ft_inspect_content(*stash) == 0) && (bytes_read != 0))
	{
		temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!temp)
			return (ft_free_all(stash));
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read < 0 || (bytes_read == 0 && !(*stash)))
		{
			free(temp);
			ft_free_all(stash);
			leftover[0] = '\0';
			return ;
		}
		temp[bytes_read] = '\0';
		ft_lstadd_back(stash, temp, bytes_read);
		if (!*stash)
			return ;
		free(temp);
	}
}

char	*ft_fill_this_str(t_list **stash)
{
	int		i;
	int		j;
	char	*line;
	t_list	*l;

	l = *stash;
	line = (char *)malloc(((ft_size_lst(l) * BUFFER_SIZE) + 1) * sizeof(char));
	if (!line || !l)
		return (NULL);
	i = 0;
	while (l)
	{
		j = 0;
		while (l->content[j])
		{
			line[i++] = l->content[j++];
			if (l->content[j - 1] == '\n')
				break ;
		}
		if (!(l->next))
			break ;
		l = l->next;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_leftover(t_list **lst, char leftover[BUFFER_SIZE + 1])
{
	t_list	*last;
	int		i;
	int		j;

	i = 0;
	while (i < BUFFER_SIZE)
		leftover[i++] = '\0';
	i = 0;
	j = 0;
	if (!(*lst))
		return (NULL);
	last = ft_lstlast(*lst);
	if (!last->content || !ft_inspect_content(last))
		return (NULL);
	while (last->content[i])
		if (last->content[i++] == '\n')
			break ;
	if (last->content[i] != '\0')
		while (last->content[i] != '\0')
			leftover[j++] = last->content[i++];
	while (j < BUFFER_SIZE)
		leftover[j++] = '\0';
	return (leftover);
}
