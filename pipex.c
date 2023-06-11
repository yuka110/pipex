/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/12 13:17:13 by yitoh         #+#    #+#                 */
/*   Updated: 2023/06/11 14:29:36 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*all;

	if (argc != 5)
	{
		write(2, "Error: Arguments are not equal to 5\n", 37);
		exit (EXIT_FAILURE);
	}
	all = pipex_init(argv, envp);
	if (pipe(all->pip) < 0)
		ft_error("pipe", errno);
	all->pid1 = fork();
	if (all->pid1 < 0)
		ft_error("fork", errno);
	if (all->pid1 == 0)
		child_process1(all->cmd1, all, envp);
	all->pid2 = fork();
	if (all->pid2 < 0)
		ft_error("fork", errno);
	if (all->pid2 == 0)
		child_process2(all->cmd2, all, envp);
	parent_process(all);
	exit(all->ext_code);
}

t_pipex	*pipex_init(char **argv, char **envp)
{
	t_pipex	*all;

	all = malloc(sizeof(t_pipex));
	if (!all)
		ft_error("Error", errno);
	all->in_f = argv[1];
	all->out_f = argv[4];
	all->fd_in = open(all->in_f, O_RDONLY);
	if (all->fd_in < 0)
		ft_error("infile", errno);
	all->fd_out = open(all->out_f, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (all->fd_out < 0)
		ft_error("outfile", errno);
	cmd_init(argv[2], &all->cmd1, &all->p_cmd1, 1);
	cmd_init(argv[3], &all->cmd2, &all->p_cmd2, 2);
	all->path = split_path(envp);
	return (all);
}

//read from infile, execute 1st command, write to pipe
void	child_process1(char **cmd1, t_pipex *all, char **envp)
{
	char	*p_cmd;
	int		i;

	dupx2_close(all->fd_in, all->pip[1], all->pip[0]);
	if (all->cmd1 && all->p_cmd1)
		execve(all->p_cmd1, all->cmd1, envp);
	i = 0;
	while (all->path[i] && cmd1[0])
	{
		p_cmd = ft_strjoin(all->path[i], cmd1[0]);
		if (!p_cmd)
			ft_error("Error", errno);
		if (!access(p_cmd, X_OK))
			break ;
		free(p_cmd);
		++i;
	}
	if (!all->path[i] || !cmd1[0])
		ft_error("cmd1: command not found\n", 127);
	execve(p_cmd, cmd1, envp);
}

//read from pipe, execute 2nd command, write to outfile
void	child_process2(char **cmd2, t_pipex *all, char **envp)
{
	char	*p_cmd;
	int		i;

	dupx2_close(all->pip[0], all->fd_out, all->pip[1]);
	if (all->cmd2 && all->p_cmd2)
		execve(all->p_cmd2, all->cmd2, envp);
	i = 0;
	while (all->path[i] && cmd2[0])
	{
		p_cmd = ft_strjoin(all->path[i], cmd2[0]);
		if (!p_cmd)
			ft_error("Error", errno);
		if (!access(p_cmd, X_OK))
			break ;
		free(p_cmd);
		++i;
	}
	if (!all->path[i] || !cmd2[0])
		ft_error("cmd2: command not found\n", 127);
	execve(p_cmd, cmd2, envp);
}

void	parent_process(t_pipex *all)
{
	int	status;

	if (close(all->pip[0]) < 0 | close(all->pip[1]) < 0
		| close(all->fd_in) < 0 | close(all->fd_out) < 0)
		ft_error("close", errno);
	if (waitpid(all->pid1, NULL, 0) < 0)
		ft_error("waitpid", errno);
	if (waitpid(all->pid2, &status, 0) < 0)
		ft_error("waitpid", errno);
	if (WIFEXITED(status))
		all->ext_code = WEXITSTATUS(status);
}
