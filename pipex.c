/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/12 13:17:13 by yitoh         #+#    #+#                 */
/*   Updated: 2023/05/30 13:02:24 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
1. create 2 children so that parent(main) process still keeps going 
	even when one child process was unsuccessful
2. use waitpid() to wait both children - get exit status from children function
3. use access() in while loop to test whether command exists in te path and executable
4. once we find the paths, pass it to execve(cmd + path, 2d array cmd, envp)

*/

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*all;

	all = pipex_init(argc, argv, envp);
	if (!all)
		exit(EXIT_FAILURE);
	if (pipe(all->pip) < 0)
		exit(EXIT_FAILURE);
	all->pid1 = fork();
	if (all->pid1 < 0)
		error_exit("fork");
	if (all->pid1 == 0)
	{
		child_process1(all->in_f, all->cmd1, all, envp);
		protect_close(all->pip[0], all->pip[1]);
	}
	else
	{
		if (waitpid(all->pid1, NULL, 0) < 0)
			error_exit("waitpid");
		//sth is wrong
		if (pipe(all->pip2) < 0)
			exit(EXIT_FAILURE);
		all->pid2 = fork();
		if (all->pid2 < 0)
			error_exit("fork");
		if (all->pid2 == 0)
		{
			child_process2(all->out_f, all->cmd2, all, envp);
			protect_close(all->pip2[0], all->pip2[1]);
			exit (EXIT_FAILURE);
		}
		parent_process(all);
	}
	exit(EXIT_SUCCESS);
}

//counter for the case where command includes str eg. grep "abc"
t_pipex	*pipex_init(int argc, char **argv, char **envp)
{
	t_pipex	*all;

	if (argc != 5)
		exit (EXIT_FAILURE);
	all = malloc(sizeof(t_pipex));
	if (!all)
		return (NULL);
	all->in_f = argv[1];
	all->out_f = argv[4];

//check if it's one cmd or with flag
	all->cmd1 = ft_split(argv[2], ' ');
	if (!all->cmd1)
		perror("Error");
	all->cmd2 = ft_split(argv[3], ' ');
	if (!all->cmd2)
		perror("Error");
	all->path = split_path(envp);
	if (!all->path)
		perror("Error");
	// all->fd_in = open(all->in_f, O_RDONLY);
	// if (all->fd_in < 0)
	// 	perror("Error");
	// all->fd_out = open(all->in_f, O_WRONLY);
	// if (all->fd_out < 0)
	// 	perror("Error");
	return (all);
}

void	error_exit(char *code)
{
	perror(code);
	exit(EXIT_FAILURE);
}

void	protect_close(int a, int b)
{
	if (close(a) < 0)
		error_exit("file can't close");
	if (close(b) < 0)
		error_exit("pipe can't close");
}

/*

pipe connects two processes childs/parent
pipe[1] = write -> pipe[0] = read


use ft_split to find right folder for the command devided by :
*/
