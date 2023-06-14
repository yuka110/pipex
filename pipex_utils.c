/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/30 12:24:37 by yitoh         #+#    #+#                 */
/*   Updated: 2023/06/14 19:05:49 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//split PATH by colon and add slash at the end
char	**split_path(char **envp)
{
	int		i;
	char	**path;

	i = 0;
	while (envp[i] && ft_strncmp("PATH=", envp[i], 5) != 0)
		i++;
	if (!envp[i])
		return (NULL);
	path = ft_split(envp[i] + 5, ':');
	if (!path)
		ft_error ("Error", errno, 0);
	i = 0;
	while (path[i])
	{
		path[i] = gnl_strjoin(path[i], "/");
		if (!path[i])
			ft_error ("Error", errno, 0);
		i++;
	}
	return (path);
}

//error 127/126 don't work
char	*find_path(char **cmd, t_pipex *all)
{
	char	*p_cmd;
	int		i;

	if (ft_strchr(cmd[0], '/'))
	{
		p_cmd = ft_strdup(cmd[0]);
		if (!p_cmd)
			ft_error("Error", errno, 0);
		if (access(p_cmd, X_OK))
			ft_error(cmd[0], 126, 0);
		return (free_2darray(cmd), p_cmd);
	}
	i = 0;
	while (all->path[i] && cmd[0])
	{
		p_cmd = ft_strjoin(all->path[i], cmd[0]);
		if (!p_cmd)
			ft_error("Error", errno, 0);
		if (!access(p_cmd, X_OK))
			return (p_cmd);
		free(p_cmd);
		++i;
	}
	// if (!all->path)
	// {
	// 	p_cmd = ft_strjoin("./", cmd[0]);
	// 	if (!p_cmd)
	// 		ft_error("Error", errno, 0);
	// 	if (access(p_cmd, X_OK))
	// 		ft_error(cmd[0], 126, 0);
	// }
	return (ft_error(cmd[0], 127, 1), NULL);
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

void	ft_error(char *str, int error, int unset)
{
	ft_putstr_fd("pipex: ", 2);
	if (error == 127)
	{
		if (str)
			ft_putstr_fd(str, 2);
		if (unset == 1)
			ft_putstr_fd(": No such file or directory\n", 2);
		else
			ft_putstr_fd(": command not found\n", 2);
		exit(127);
	}
	if (error == 126)
	{
		if (str)
			ft_putstr_fd(str, 2);
		ft_putstr_fd(": Permission denied\n", 2);
		exit(126);
	}
	perror(str);
	exit(errno);
}
