/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/30 12:24:37 by yitoh         #+#    #+#                 */
/*   Updated: 2023/05/31 16:34:36 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_dup(int input, int output, int pip_non)
{
	if (dup2(input, 0) < 0)
		perror("dup2");
	if (dup2(output, 1) < 0)
		perror("dup2");
	if (close(pip_non) < 0)
		error_exit("unused pipe can't close");
}
