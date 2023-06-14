/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_utils2.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/13 10:38:29 by yitoh         #+#    #+#                 */
/*   Updated: 2023/06/14 14:11:03 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
		ft_error("close pip0", errno, 0);
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
		ft_error("close pip1", errno, 0);
	cmd2 = ft_split(argv, ' ');
	if (!cmd2)
		ft_error("Error", errno, 0);
	p_cmd = find_path(cmd2, all);
	if (execve(p_cmd, cmd2, envp) < 0)
		exit(EXIT_FAILURE);
}

char	*find_path(char **cmd1, t_pipex *all)
{
	char	*p_cmd;
	int		i;

	if (ft_strchr(cmd1[0], '/'))
	{
		p_cmd = ft_strdup(cmd1[0]);
		if (!p_cmd)
			ft_error("Error", errno, 0);
		if (access(p_cmd, X_OK))
			ft_error(cmd1[0], 126, 0);
		return (free_2darray(cmd1), p_cmd);
	}
	i = 0;
	while (all->path[i] && cmd1[0])
	{
		p_cmd = ft_strjoin(all->path[i], cmd1[0]);
		if (!p_cmd)
			ft_error("Error", errno, 0);
		if (!access(p_cmd, X_OK))
			return (p_cmd);
		free(p_cmd);
		++i;
	}
	ft_error(cmd1[0], 127, 0);
	return (NULL);
}

void	free_2darray(char **s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		free (s[i]);
		i++;
	}
	free (s);
}
