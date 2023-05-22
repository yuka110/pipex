/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fork_process.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 16:09:09 by yitoh         #+#    #+#                 */
/*   Updated: 2023/05/22 20:25:15 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(int fd1, char *cmd1, t_pipex *all, char **envp)
{
	char	*p_cmd;
	int		i;

	if (dup2(fd1, 0) < 0)
		perror("dup2");
	if (dup2(all->pip[1], 1) < 0)
		perror("dup2");
	close (all->pip[0]);
	close (fd1);
	i = 0;
	while (all->path[i])
	{
		p_cmd = ft_strjoin(all->path, cmd1);
		if (!p_cmd)
			exit(EXIT_FAILURE);
		execve(p_cmd, p_cmd, envp);
		perror("execve");
		free(p_cmd);
		++i;
	}
}

void	parent_process(int fd2, char *cmd2, t_pipex *all, char **envp)
{
	if (dup2(all->pip[0], 0) < 0)
		perror("dup2");
	if (dup2(fd2, 1) < 0)
		perror("dup2");
	close (all->pip[1]);
	close (fd2);
}


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
