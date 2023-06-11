/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/12 13:18:23 by yitoh         #+#    #+#                 */
/*   Updated: 2023/06/11 14:31:27 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <sys/errno.h>
# include "./Libft/libft.h"

typedef struct s_pipex
{
	int		fd_in;
	int		fd_out;
	int		pid1;
	int		pid2;
	int		ext_code;
	char	*in_f;
	char	*out_f;
	char	**cmd1;
	char	**cmd2;
	char	*p_cmd1;
	char	*p_cmd2;
	char	**path;
	int		pip[2];
}				t_pipex;

//pipex.c
t_pipex	*pipex_init(char **argv, char **envp);
void	child_process1(char **cmd1, t_pipex *all, char **envp);
void	child_process2(char **cmd2, t_pipex *all, char **envp);
void	parent_process(t_pipex *all);

//pipex_utils.c
char	**split_path(char **envp);
void	dupx2_close(int input, int output, int pip_non);
void	ft_error(char *str, int error);
void	cmd_init(char *arg, char ***cmd, char **p_cmd, int num);
void	take_cmd_out(char *arg, char ***cmd);
void	free_2darray(char **s);

#endif