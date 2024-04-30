/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:37:17 by pracksaw          #+#    #+#             */
/*   Updated: 2024/04/30 12:26:23 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	t_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c = c + 32;
	return (c);
}

void	str_tolower(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		str[i] = t_tolower(str[i]);
		i++;
	}
}

void	pipeline_left(char **argv, char **env, int *pipe_ends)
{
	int		infile_fd;

	infile_fd = open(argv[1], O_RDONLY);
	if (close(pipe_ends[0]) == -1)
		error_msg("close", pipe_ends);
	if (infile_fd == -1)
	{
		print_err("pipex: ", argv[1], pipe_ends);
		if (close(pipe_ends[1]) == -1)
			error_msg("close", pipe_ends);
		exit(EXIT_FAILURE);
	}
	if (dup2(pipe_ends[1], STDOUT_FILENO) == -1)
		error_msg("dup2", pipe_ends);
	if (close(pipe_ends[1]) == -1)
		error_msg("close", pipe_ends);
	if (dup2(infile_fd, STDIN_FILENO) == -1)
		error_msg("dup2", pipe_ends);
	if (close(infile_fd) == -1)
		error_msg("close", pipe_ends);
	call_cmd(argv[2], env);
}

void	pipeline_right(char **argv, char **env, int *pipe_ends)
{
	int		outfile_fd;

	outfile_fd = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (close(pipe_ends[1]) == -1)
		error_msg("close", pipe_ends);
	if (outfile_fd == -1)
	{
		print_err("pipex: ", argv[4], pipe_ends);
		if (close(pipe_ends[0]) == -1)
			error_msg("close", pipe_ends);
		exit(EXIT_FAILURE);
	}
	if (dup2(pipe_ends[0], STDIN_FILENO) == -1)
		error_msg("dup2", pipe_ends);
	if (close(pipe_ends[0]) == -1)
		error_msg("close", pipe_ends);
	if (dup2(outfile_fd, STDOUT_FILENO) == -1)
		error_msg("dup2", pipe_ends);
	if (close(outfile_fd) == -1)
		error_msg("close", pipe_ends);
	call_cmd(argv[3], env);
}

void	parent(int pid1, int pid2, int *pipe_ends)
{
	int	child_status;

	if (close(pipe_ends[0]) == -1)
		error_msg("close", pipe_ends);
	if (close(pipe_ends[1]) == -1)
		error_msg("close", pipe_ends);
	waitpid(pid1, NULL, WUNTRACED);
	waitpid(pid2, &child_status, WUNTRACED);
	if (WIFEXITED(child_status) && WEXITSTATUS(child_status) != EXIT_SUCCESS)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}
