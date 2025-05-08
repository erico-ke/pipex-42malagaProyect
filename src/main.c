/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:13:38 by erico-ke          #+#    #+#             */
/*   Updated: 2025/05/08 13:42:00 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	ft_init(char **argv, t_pip	*lst)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (ft_strncmp(argv[i], "", 1) == 0)
			return (EXIT_FAILURE);
		if (ft_strncmp(ft_strtrim(argv[i], " "), "", 1) == 0)
			return (EXIT_FAILURE);
	}
	lst->filename1 = argv[1];
	lst->cmd1 = argv[2];
	lst->cmd2 = argv[3];
	lst->filename2 = argv[4];
	return (EXIT_SUCCESS);
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
		return (prnt_err("' are not accepted in the input"));
	lst = malloc(sizeof(t_pip));
	if (!lst)
		return (prnt_err("malloc failed"));
	if (ft_init(argv, lst) == EXIT_FAILURE)
		return (free(lst), prnt_err("non-existent arguments"));
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
