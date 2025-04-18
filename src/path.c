/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 21:05:27 by erico-ke          #+#    #+#             */
/*   Updated: 2025/04/18 21:06:16 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

extern char	**environ;

char	*get_cmd_path(char *cmd)
{
	int		i = 0;
	char	**paths;
	char	*path_env;
	char	*full_cmd;
	char	*tmp;

	while (environ[i] && ft_strncmp(environ[i], "PATH=", 5) != 0)
		i++;
	if (!environ[i])
		return (NULL);
	path_env = environ[i] + 5;
	paths = ft_split(path_env, ':');
	i = 0;
	while (paths && paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		full_cmd = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(full_cmd, X_OK) == 0)
			return (ft_free_split(paths), full_cmd);
		free(full_cmd);
		i++;
	}
	ft_free_split(paths);
	return (NULL);
}
