/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/12 13:18:23 by yitoh         #+#    #+#                 */
/*   Updated: 2023/05/22 20:15:42 by yitoh         ########   odam.nl         */
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
	char	*in_f;
	char	*out_f;
	char	**cmd1;
	char	**cmd2;
	char	**path;
	int		pip[2];
}				t_pipex;

t_pipex	*pipex_init(char **argv,  char **envp);

void	child_process(int fd1, char *cmd1, t_pipex *all, char **envp);
void    parent_process(int fd2, char *cmd2, t_pipex *all, char **envp;

char **split_path(char **envp);
void	print_path(char **path);


#endif
