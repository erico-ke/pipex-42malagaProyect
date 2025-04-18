/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:37:43 by erico-ke          #+#    #+#             */
/*   Updated: 2025/04/18 21:09:17 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libs/libft/src/libft.h"

typedef struct pipex
{
	char	*filename1;
	char	*filename2;
	char	*cmd1;
	char	*cmd2;
}	t_pip;

/* Error control and memory leaks management */
int		print_error(char *str);
void	ft_free_split(char **split);

/* Fork process and path management*/
char	*get_cmd_path(char *cmd);
void	child_process(t_pip *lst, int *fd);
void	parent_process(t_pip *lst, int *fd, pid_t pid);

#endif