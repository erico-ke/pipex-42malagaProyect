/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:37:43 by erico-ke          #+#    #+#             */
/*   Updated: 2025/04/16 15:06:01 by erico-ke         ###   ########.fr       */
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

int	print_error(char *str);

#endif