/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fork_process.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 16:09:09 by yitoh         #+#    #+#                 */
/*   Updated: 2023/05/30 12:57:11 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//read from infile, write to pipe
void	child_process1(char *infile, char **cmd1, t_pipex *all, char **envp)
{
	char	*p_cmd;
	int		i;

	p_cmd = all->p_cmd1;
	all->fd_in = open(infile, O_RDONLY);
	if (all->fd_in < 0)
		perror("Error");
	open_dup(all->fd_in, all->pip[1], all->pip[0]);
	if (close(all->fd_in) < 0)
		error_exit("file can't close");
	i = 0;
	while (all->path[i])
	{
		p_cmd = ft_strjoin(all->path[i], cmd1[0]);
		if (!p_cmd)
			exit(EXIT_FAILURE);
		if (!access(p_cmd, X_OK))
			break ;
		free(p_cmd);
		++i;
	}
	execve(p_cmd, cmd1, envp);
	if (close(all->pip[1]) < 0)
		error_exit("pipe can't close");
}

//read from pipe, wait 
void	child_process2(char *outfile, char **cmd2, t_pipex *all, char **envp)
{
	char	*p_cmd;
	int		i;

	p_cmd = all->p_cmd2;
	all->fd_out = open(outfile, O_WRONLY);
	if (all->fd_out < 0)
		perror("Error");
	open_dup(all->pip2[0], all->fd_out, all->pip2[1]);
	if (close(all->fd_out) < 0)
		error_exit("file can't close");
	i = 0;
	while (all->path[i])
	{
		p_cmd = ft_strjoin(all->path[i], cmd2[0]);
		if (!p_cmd)
			exit(EXIT_FAILURE);
		if (!access(p_cmd, X_OK))
			break ;
		free(p_cmd);
		++i;
	}
	execve(p_cmd, cmd2, envp);
	if (close(all->pip2[0]) < 0)
		error_exit("pipe can't close");
}

//read from pipe, wait 
void	parent_process(t_pipex *all)
{
	int	status;

	// if (waitpid(all->pid1, NULL, 0) < 0)
	// 	error_exit("waitpid");
	if (waitpid(all->pid2, &status, 0) < 0)
		error_exit("waitpid");
	if (WIFEXITED(status))
		all->ext_code = WEXITSTATUS(status);
	ft_free(all->cmd1);
	ft_free(all->cmd2);
	ft_free(all->path);
}

//split PATH by colon and add slash at the end
char	**split_path(char **envp)
{
	int		i;
	char	**path;

	i = 0;
	while (envp[i][0] != 'P' && envp[i][1] != 'A'
		&& envp[i][2] != 'T' && envp[i][3] != 'H')
		i++;
	path = ft_split(envp[i] + 5, ':');
	if (!path)
		perror ("Error");
	i = 0;
	while (path[i])
	{
		path[i] = gnl_strjoin(path[i], "/");
		if (!path[i])
			perror ("Error");
		i++;
	}
	return (path);
}


void	ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		++i;
	}
	free(s);
}

void	print_path(char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		printf("%s ", path[i]);
		i++;
	}
	printf("\n");
}
