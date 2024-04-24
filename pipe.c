/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:37:17 by pracksaw          #+#    #+#             */
/*   Updated: 2024/04/23 15:22:17 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipe	pipex;

	if (ac != 5)
		{
    ft_printf("Error\nInvalid arguments\n");
    exit(EXIT_FAILURE);
    }
	else if (pipe(pipex.fd) < 0)
    ft_printf("Error\nPipe error\n");
  pipex.pid = fork();
  if (pipex.pid < 0)
      error_msg("Error\nFork ():");
  if (pipex.pid ==1)
  {
    //REDIRECTING_KIDDO//
    //EXECUTE//
  }
  wait(NULL);
  //REDIRECTING_DAD&MOM
  //EXECUTE
  return(0);
}
