/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:38:04 by pracksaw          #+#    #+#             */
/*   Updated: 2024/04/23 15:25:55 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void exec_cmd()
{
	int		id1 = fork();
	int		id2 = fork();

	while (wait(NULL) != -1 || errno != ECHILD)
	{
		printf("point 0 ");
	}
	if (id1 == 0)
	{
		if (id2 == 0)
		{
			printf("grandchild\n");
		}
		else
		{
			printf("1st child of parent\n");
		}
	}
	else
	{
		if (id2 == 0)
		{
			printf("2nd child of parent\n");
		}
		else
		{
			printf("parent\n");
		}
	}
	return (0);
}

