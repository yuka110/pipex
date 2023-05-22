/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/12 13:17:13 by yitoh         #+#    #+#                 */
/*   Updated: 2023/05/22 20:17:27 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*all;
	int		pid;

	if (argc != 5)
		exit (EXIT_FAILURE);
	all = pipex_init(argc, argv);
	if (!all)
		exit(EXIT_FAILURE);
	pipe(all->pip);
	pid = fork();
	if (pid < 0)
		perror("fork");
	if (pid == 0)
		child_process(all->in_f, all->cmd1, all, envp);
	else
		parent_process(all->out_f, all->cmd2, all, envp);
	
	return (0);
}

//counter for the case where command as 2 words eg. ls -la
t_pipex	*pipex_init(char **argv, char **envp)
{
	t_pipex	*all;

	all = malloc(sizeof(t_pipex *));
	if (!all)
		return (NULL);
	all->in_f = argv[1];
	all->out_f = argv[4];
	all->cmd1 = ft_split(argv[3], ' ');
	if (!all->cmd1)
		perror("Error");
	all->cmd2 = ft_split(argv[2], ' ');
	if (!all->cmd2)
		perror("Error");
	all->path = split_path(envp);
	if (!all->path)
		perror("Error");
	all->fd_in = open(all->in_f, O_RDONLY);
	if (all->fd_in < 0)
		perror("Error");
	all->fd_out = open(all->in_f, O_WRONLY);
	if (all->fd_out < 0)
		perror("Error");
	return (all);
}

// void	error_exit(char *code)
// {
// 	perror(code);
// 	exit(EXIT_FAILURE);
// }

/*

pipe connects two processes childs/parent
pipe[1] = write -> pipe[0] = read


use ft_split to find right folder for the command devided by :
*/
