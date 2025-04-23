/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:13:38 by erico-ke          #+#    #+#             */
/*   Updated: 2025/04/23 18:09:51 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	ft_init(char **argv, t_pip	*lst)
{
	lst->filename1 = argv[1];
	lst->cmd1 = argv[2];
	lst->cmd2 = argv[3];
	lst->filename2 = argv[4];
}

static int	valid_input_check(char *check)
{
	int	i;

	i = 0;
	while (check[i])
	{
		if (check[i] == 39)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv, char **env)
{
	t_pip	*lst;
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
		return (prnt_err("usage: ./pipex file1 cmd1 cmd2 file2"));
	if (valid_input_check(argv[2]) == EXIT_FAILURE
		|| valid_input_check(argv[3]) == EXIT_FAILURE)
		return (prnt_err("' is not accepted in the input"));
	lst = malloc(sizeof(t_pip));
	if (!lst)
		return (prnt_err("malloc failed"));
	ft_init(argv, lst);
	if (pipe(fd) == -1)
		return (free(lst), prnt_err("pipe failed"));
	pid = fork();
	if (pid < 0)
		return (free(lst), prnt_err("fork failed"));
	else if (pid == 0)
		child_process(lst, fd, env);
	else
		parent_process(lst, fd, pid, env);
	free(lst);
	return (EXIT_SUCCESS);
}
