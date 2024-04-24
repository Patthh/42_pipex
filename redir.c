/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:37:54 by pracksaw          #+#    #+#             */
/*   Updated: 2024/04/23 16:57:15 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void parentfd_redir(char **av, t_pipe pipex)
{
    int	out_fd;

	out_fd = open(av[4], O_CREAT | O_WRONLY , 0644);
	if (out_fd < 0)
		error_msg("Error\nBad Parent opt_fd");
	close(pipex.fd[1]);
	if 
	{
		
	}
}