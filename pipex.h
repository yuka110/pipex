/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/12 13:18:23 by yitoh         #+#    #+#                 */
/*   Updated: 2023/06/01 18:36:43 by yitoh         ########   odam.nl         */
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
t_pipex	*pipex_init(int argc, char **argv, char **envp);
void	error_exit(char *code);
void	protect_close(int a, int b);


//fork_process.c
void	child_process1(char **cmd1, t_pipex *all, char **envp);
void	child_process2(char **cmd2, t_pipex *all, char **envp);
void	parent_process(t_pipex *all);
char	**split_path(char **envp);
void	ft_free(char **s);


void	dupx2_close(int input, int output, int pip_non);


#endif
