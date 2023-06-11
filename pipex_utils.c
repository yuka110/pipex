/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/30 12:24:37 by yitoh         #+#    #+#                 */
/*   Updated: 2023/06/11 14:31:19 by yitoh         ########   odam.nl         */
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
		ft_error ("Error", errno);
	i = 0;
	while (path[i])
	{
		path[i] = gnl_strjoin(path[i], "/");
		if (!path[i])
			ft_error ("Error", errno);
		i++;
	}
	return (path);
}

void	dupx2_close(int input, int output, int pip_non)
{
	if (dup2(input, 0) < 0 | close(input) < 0)
		ft_error("dup2", errno);
	if (dup2(output, 1) < 0 | close(output) < 0)
		ft_error("dup2", errno);
	if (close(pip_non) < 0)
		ft_error("close", errno);
}

void	ft_error(char *str, int error)
{
	if (error == 127)
	{
		ft_putstr_fd(str, 2);
		exit(127);
	}
	perror(str);
	exit(errno);
}

void	cmd_init(char *arg, char ***cmd, char **p_cmd, int num)
{
	char	**tmp;

	*p_cmd = NULL;
	if (!ft_strchr(arg, '/'))
	{
		*cmd = ft_split(arg, ' ');
		if (!cmd)
			ft_error("Error", errno);
		return ;
	}
	tmp = ft_split(arg, ' ');
	if (!tmp)
		ft_error("Error", errno);
	if (access(tmp[0], X_OK) && num == 2)
		ft_error("cmd: No such file or directory\n", 127);
	else if (!access(tmp[0], X_OK))
		*p_cmd = ft_strdup(tmp[0]);
	free_2darray(tmp);
	take_cmd_out(arg, cmd);
}

void	take_cmd_out(char *arg, char ***cmd)
{
	size_t	i;
	size_t	len;
	char	*tmp;

	len = ft_strlen(arg) - 1;
	i = len;
	while (i >= 0)
	{
		if (arg[i] == '/')
			break ;
		--i;
	}
	tmp = ft_substr(arg, i + 1, len - i);
	if (!tmp)
		ft_error("Error", errno);
	*cmd = ft_split(tmp, ' ');
	if (!(*cmd))
		ft_error("Error", errno);
	free (tmp);
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
