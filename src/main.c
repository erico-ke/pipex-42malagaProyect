/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:13:38 by erico-ke          #+#    #+#             */
/*   Updated: 2025/04/16 15:29:29 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_init(char **argv, t_pip	*lst)
{
	lst->filename1 = argv[1];
	lst->cmd1 = argv[2];
	lst->filename2 = argv[4];
	lst->cmd2 = argv[3];
}

int	main(int argc, char **argv)
{
	if (argc == 5)
	{
		t_pip	*lst;
		lst = ft_calloc(1, sizeof(t_pip));
		if (!lst)
			return (print_error("Memory alloc failed"));
		ft_init(argv, lst);
	}
	else
		return(print_error("Incorrect number of arguments"));
	return (EXIT_SUCCESS);
}
