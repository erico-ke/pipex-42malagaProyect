/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:05:27 by erico-ke          #+#    #+#             */
/*   Updated: 2025/05/08 16:55:41 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*get_cmd_path(char *cmd, char **env)
{
	int		i;
	char	**paths;
	char	*path_env;
	char	*full_cmd;
	char	*tmp;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	if (!env[i])
		return (NULL);
	path_env = env[i] + 5;
	paths = ft_split(path_env, ':');
	i = 0;
	while (paths && paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		full_cmd = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(full_cmd, X_OK) == 0)
			return (free_splt(paths), full_cmd);
		free(full_cmd);
		i++;
	}
	return (free_splt(paths), NULL);
}

void	ft_access(t_pip *lst, char **env, char **test)
{
	test = ft_split(lst->cmd1, ' ');
	lst->cmd1_path = get_cmd_path(test[0], env);
	if (!lst->cmd1_path)
	{
		if (access(lst->cmd1, X_OK) == 0)
		{
			lst->cmd1_path = test[0];
			lst->cmd1 = ft_strrchr(lst->cmd1, '/');
			lst->cmd1++;
		}
	}
	free_splt(test);
	test = ft_split(lst->cmd2, ' ');
	lst->cmd2_path = get_cmd_path(test[0], env);
	if (!lst->cmd2_path)
	{
		if (access(lst->cmd2, X_OK) == 0)
		{
			lst->cmd2_path = test[0];
			lst->cmd2 = ft_strrchr(lst->cmd2, '/');
			lst->cmd2++;
		}
	}
	free_splt(test);
}
