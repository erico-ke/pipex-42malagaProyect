/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:06:39 by erico-ke          #+#    #+#             */
/*   Updated: 2025/04/21 14:47:13 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_process(t_pip *lst, int *fd, char **env)
{
	int		infile;
	char	**cmdarg;
	char	*cmd_path;

	infile = open(lst->filename1, O_RDONLY);
	if (infile < 0)
	{
		free(lst);
		exit(prnt_err("input file"));
	}
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	cmdarg = ft_split(lst->cmd1, ' ');
	if (!cmdarg)
		return (free(lst), exit(prnt_err("split cmd1")));
	cmd_path = get_cmd_path(cmdarg[0], env);
	if (!cmd_path)
		return (free(lst), free_splt(cmdarg), exit(prnt_err("cmd1 not found")));
	execve(cmd_path, cmdarg, env);
	perror("execve failed");
	exit(EXIT_FAILURE);
}

void	parent_process(t_pip *lst, int *fd, pid_t pid, char **env)
{
	int		outfile;
	char	**cmdarg;
	char	*cmd_path;

	waitpid(pid, NULL, 0);
	outfile = open(lst->filename2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
		exit(prnt_err("output file"));
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	cmdarg = ft_split(lst->cmd2, ' ');
	if (!cmdarg)
		exit(prnt_err("split cmd2"));
	cmd_path = get_cmd_path(cmdarg[0], env);
	if (!cmd_path)
		return (free_splt(cmdarg), exit(prnt_err("cmd2 not found")));
	execve(cmd_path, cmdarg, env);
	perror("execve failed");
	exit(EXIT_FAILURE);
}

/* Hacer una funcion para liberar memoria en caso de que
los if con un exit se cumplan */