/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: yitoh <yitoh@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/30 12:24:37 by yitoh         #+#    #+#                 */
/*   Updated: 2023/06/01 18:32:49 by yitoh         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	dupx2_close(int input, int output, int pip_non)
{
	if (dup2(input, 0) < 0)
		perror("dup2");
	if (dup2(output, 1) < 0)
		perror("dup2");
	if (close(pip_non) < 0)
		error_exit("unused pipe can't close");
}
