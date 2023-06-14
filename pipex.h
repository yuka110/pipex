/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/12 13:18:23 by yitoh         #+#    #+#                 */
/*   Updated: 2023/06/14 18:30:22 by yitoh         ########   odam.nl         */
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
	char	**path;
	int		pip[2];
}				t_pipex;

//pipex.c
t_pipex	*pipex_init(char **envp);
void	parent_process(t_pipex *all);
void	child_process1(char *infile, char *argv, t_pipex *all, char **envp);
void	child_process2(char *outfile, char *argv, t_pipex *all, char **envp);

//pipex_utils.c
char	**split_path(char **envp);
void	ft_error(char *str, int error, int unset);
char	*find_path(char **cmd, t_pipex *all);
void	free_2darray(char **s);

#endif