/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:47:14 by erico-ke          #+#    #+#             */
/*   Updated: 2025/04/18 21:04:01 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	print_error(char *str)
{
	ft_printf("Error, %s.\n", 2, str);
	return (EXIT_FAILURE);
}

void	ft_free_split(char **split)
{
	int	i = 0;

	if (!split)
		return ;
	while (split[i])
		free(split[i++]);
	free(split);
}
