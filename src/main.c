/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:13:38 by erico-ke          #+#    #+#             */
/*   Updated: 2025/04/21 14:45:48 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_init(char **argv, t_pip	*lst)
{
	lst->filename1 = argv[1];
	lst->cmd1 = argv[2];
	lst->cmd2 = argv[3];
	lst->filename2 = argv[4];
}

int	main(int argc, char **argv, char **env)
{
	t_pip	*lst;
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
		return (prnt_err("usage: ./pipex file1 cmd1 cmd2 file2"));
	lst = malloc(sizeof(t_pip));
	if (!lst)
		return (prnt_err("malloc failed"));
	ft_init(argv, lst);
	if (pipe(fd) == -1)
		return (prnt_err("pipe failed"));
	pid = fork();
	if (pid < 0)
		return (prnt_err("fork failed"));
	else if (pid == 0)
		child_process(lst, fd, env);
	else
		parent_process(lst, fd, pid, env);
	free(lst);
	return (EXIT_SUCCESS);
}

// En los casos de error de que falla la pipe o el fork hay que
//liberar memoria

/* 
Hay que usar env para sacar el path a las fuinciones de shell,
checkear que existan los cmd(1&2) y checkear que la file1 exista.

Para el checkeo con el path hay que leer entero lo que devuelve
env, guardarlo en una variable, buscar la parte que empieza con "PATH"
y splitear en los ':' para obtener todas las rutas.

Despues de eso recorremos el array doble del split con paths[i]
pasandoselo a (access??) con el objetivo de checkear si el cmd existe
en caso de que no exista sacamos mensaje de error, si no entramos a
un hijo (fork()) para que realize el execve() y guarde el resultado
en una variable a la cual despues le aplicaremos el otro cmd a travez
de una pipe().

La estructura sera algo asi:

int pid = fork();

if (pid == 0)
{
	//lo que hace el hijo (pipe, execve, etc).
}
else
{
	lo que hace el padre (recive el resultado del pipe)
}
*/