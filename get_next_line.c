/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:56:04 by sithomas          #+#    #+#             */
/*   Updated: 2024/12/04 15:48:39 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

void    ft_fill_this_list(t_list **lst, int fd);
size_t  ft_inspect_this_str(t_list *lst);
void    ft_lst_add_after(t_list *lst, char *str);

char    *get_next_line(int fd)
{
/*
Steps to do : 
    1 initialise a chained list named my_list, then add buff ad content until I find a \n.
    2 duplicate in char * the whole list until the \n
    3 clear everything you need to start again from your end if call again GNL.
*/
    t_list  *my_list;
    char    *result;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    my_list = NULL;
    result = NULL;
    ft_fill_this_list(&my_list, fd); //Step 1
    //result = ft_print_this_line(&my_list, result); //Step 2
    
    return(result);
}




void    ft_fill_this_list(t_list **lst, int fd)
{
    char    *buffer;
    int     bytes_read;
    
    bytes_read = 1;
    while (ft_inspect_this_str(*lst) == 0 && bytes_read != 0)
    {
        buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
        if (!buffer)
        {
            //free all list lst;
            return ;
        }
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read < 0)
        {
            free(buffer);
            //free all list(lst);
            return ;
        }
        buffer[bytes_read] = '\0';   
        ft_lst_add_after(*lst, buffer);
        if (!(*lst)->next)
        {
            //free all list lst
            return ;
        }
        *lst = (*lst)->next;
        free(buffer);
    }
}

size_t  ft_inspect_this_str(t_list *lst)
{
    size_t  i;
    
    if (!lst || !(lst->content))
        return (0);
    while(lst->content[i])
    {
        if (lst->content[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

void    ft_lst_add_after(t_list *lst, char *str)
{
    t_list  *new;
    
    new = (t_list *)malloc(sizeof(t_list));
    if (!new)
        return ;
    new->content = str;
    new->next = NULL;
    if (!lst)
        lst = new;
        return ;
    lst->next = new;
}