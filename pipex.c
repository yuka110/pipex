/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/12 13:17:13 by yitoh         #+#    #+#                 */
/*   Updated: 2023/06/14 17:20:14 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void leaks(void)
{
	pid_t pid = getpid();
	char *s;
	asprintf(&s, "leaks -q %d > %d", pid, pid);
	system(s);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*all;

	atexit(leaks);
	if (argc != 5)
	{
		write(2, "Error: Arguments are not equal to 5\n", 37);
		exit (EXIT_FAILURE);
	}
	all = pipex_init(envp);
	if (pipe(all->pip) < 0)
		ft_error("pipe", errno, 0);
	all->pid1 = fork();
	if (all->pid1 < 0)
		ft_error("fork", errno, 0);
	if (all->pid1 == 0)
		child_process1(argv[1], argv[2], all, envp);
	all->pid2 = fork();
	if (all->pid2 < 0)
		ft_error("fork", errno, 0);
	if (all->pid2 == 0)
		child_process2(argv[4], argv[3], all, envp);
	parent_process(all);
	exit(all->ext_code);
}

t_pipex	*pipex_init(char **envp)
{
	t_pipex	*all;

	all = malloc(sizeof(t_pipex));
	if (!all)
		ft_error("Error", errno, 0);
	all->path = split_path(envp);
	return (all);
}

void	child_process1(char *infile, char *argv, t_pipex *all, char **envp)
{
	char	*p_cmd;
	char	**cmd1;

	all->fd_in = open(infile, O_RDONLY);
	if (all->fd_in < 0)
		ft_error(infile, errno, 0);
	if (dup2(all->fd_in, 0) < 0 | close(all->fd_in) < 0)
		ft_error("dup2", errno, 0);
	if (dup2(all->pip[1], 1) < 0 | close(all ->pip[1]) < 0)
		ft_error("dup2", errno, 0);
	if (close(all->pip[0]) < 0)
		ft_error("close", errno, 0);
	if (!argv[0] | !ft_strncmp(" ", argv, 1))
		ft_error(argv, 127, 0);
	cmd1 = ft_split(argv, ' ');
	if (!cmd1)
		ft_error("Error", errno, 0);
	p_cmd = find_path(cmd1, all);
	if (execve(p_cmd, cmd1, envp) < 0)
		exit(EXIT_FAILURE);
}

void	child_process2(char *outfile, char *argv, t_pipex *all, char **envp)
{
	char	*p_cmd;
	char	**cmd2;

	all->fd_out = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (all->fd_out < 0)
		ft_error(outfile, errno, 0);
	if (dup2(all->pip[0], 0) < 0 | close(all->pip[0]) < 0)
		ft_error("dup2", errno, 0);
	if (dup2(all->fd_out, 1) < 0 | close(all->fd_out) < 0)
		ft_error("dup2", errno, 0);
	if (close(all->pip[1]) < 0)
		ft_error("close", errno, 0);
	if (!argv[0] | !ft_strncmp(" ", argv, 1))
		ft_error(argv, 127, 0);
	cmd2 = ft_split(argv, ' ');
	if (!cmd2)
		ft_error("Error", errno, 0);
	p_cmd = find_path(cmd2, all);
	if (execve(p_cmd, cmd2, envp) < 0)
		exit(EXIT_FAILURE);
}

void	parent_process(t_pipex *all)
{
	int	status;

	if (close(all->pip[0]) < 0 | close(all->pip[1]) < 0)
		ft_error("close pipe", errno, 0);
	if (waitpid(all->pid2, &status, 0) < 0)
		ft_error("waitpid", errno, 0);
	if (wait(NULL) < 0)
		ft_error("wait", errno, 0);
	if (WIFEXITED(status))
		all->ext_code = WEXITSTATUS(status);
}
