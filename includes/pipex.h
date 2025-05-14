/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:37:43 by erico-ke          #+#    #+#             */
/*   Updated: 2025/05/14 18:54:50 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libs/libft/src/libft.h"
# include <sys/wait.h>

typedef struct pipex
{
	char	*filename1;
	char	*filename2;
	char	*cmd1;
	char	*cmd2;
	char	*cmd1_path;
	char	*cmd2_path;
}	t_pip;

/* Error control and memory leaks management */
int		prnt_err(char *str);
void	free_splt(char **split);

/* Fork process and path management*/
char	*get_cmd_path(char *cmd, char **env);
void	child_process(t_pip *lst, int *fd, char **env);
void	parent_process(t_pip *lst, int *fd, char **env);
void	ft_access(t_pip *lst, char **env, char **test);

#endif