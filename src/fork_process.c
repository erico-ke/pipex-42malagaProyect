/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:06:39 by erico-ke          #+#    #+#             */
/*   Updated: 2025/05/08 16:53:03 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_process(t_pip *lst, int *fd, char **env)
{
	int		infile;
	char	**cmdarg;

	infile = open(lst->filename1, O_RDONLY);
	if (infile < 0)
		return (perror("input file"));
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	cmdarg = ft_split(lst->cmd1, ' ');
	if (!cmdarg)
		return (free(lst), exit(prnt_err("split cmd1")));
	execve(lst->cmd1_path, cmdarg, env);
	perror("execve failed");
	exit(EXIT_FAILURE);
}

void	parent_process(t_pip *lst, int *fd, pid_t pid, char **env)
{
	int		outfile;
	char	**cmdarg;

	waitpid(pid, NULL, WNOHANG);
	outfile = open(lst->filename2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
		return (perror("output file"));
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	cmdarg = ft_split(lst->cmd2, ' ');
	if (!cmdarg)
		exit(prnt_err("split cmd2"));
	execve(lst->cmd2_path, cmdarg, env);
	perror("execve failed");
	exit(EXIT_FAILURE);
}
