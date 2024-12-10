/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:04:06 by sithomas          #+#    #+#             */
/*   Updated: 2024/12/10 16:04:07 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd;
	char *result;

	fd = open("explain.txt", O_RDONLY);
	while (1)
	{
		result = get_next_line(fd);
		if (!result)
			break ;
		printf("Résultat : %s", result);
		free(result);
	}
	close(fd);
	return (0);
}