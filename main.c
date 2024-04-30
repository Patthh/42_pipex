/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:37:45 by pracksaw          #+#    #+#             */
/*   Updated: 2024/04/30 12:35:54 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	check_args(int argc)
{
	if (argc != 5)
	{
		ft_putstr_fd("Usage: ./pipex file1 cmd1 cmd2 file2\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av, char **envp)
{
	int		pipe_ends[2];
	pid_t	p_left_id;
	pid_t	p_right_id;

	check_args(ac);
	if (pipe(pipe_ends) == -1)
		error_msg("pipe", NULL);
	p_left_id = fork();
	if (p_left_id == -1)
		error_msg("fork", pipe_ends);
	else if (p_left_id == 0)
		pipeline_left(av, envp, pipe_ends);
	else
	{
		p_right_id = fork();
		if (p_right_id == -1)
			error_msg("fork", pipe_ends);
		else if (p_right_id == 0)
			pipeline_right(av, envp, pipe_ends);
		else
			parent(p_left_id, p_right_id, pipe_ends);
	}
}
