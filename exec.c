/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:38:04 by pracksaw          #+#    #+#             */
/*   Updated: 2024/04/29 12:27:42 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_arr(char **array)
{
	size_t	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
static char	*get_env_values(const char *env_var_search, char **env)
{
	size_t	i;
	size_t	len;
	char	*env_var;

	i = 0;
	while (env[i])
	{
		len = 0;
		while (env[i][len] != '=' && env[i][len])
			len++;
		env_var = ft_substr(env[i], 0, len);
		if (!env_var)
			error_msg("malloc", NULL);
		if (ft_strcmp(env_var, env_var_search) == 0)
		{
			free(env_var);
			return (env[i] + len + 1);
		}
		free(env_var);
		i++;
	}
	return (NULL);
}
static char	*construct_cmd_path(const char *directory, const char *cmd_name)
{
	char	*temp;
	char	*cmd_path;

	temp = ft_strjoin(directory, "/");
	if (!temp)
		error_msg("malloc", NULL);
	cmd_path = ft_strjoin(temp, cmd_name);
	free(temp);
	if (!cmd_path)
		error_msg("malloc", NULL);
	return (cmd_path);
}
static char	*get_cmd_path(char *cmd_name, char **env)
{
	size_t	i;
	char	**directories;
	char	*cmd_path;

	i = 0;
	directories = ft_split(get_env_values("PATH", env), ':');
	if (!directories)
		error_msg("malloc", NULL);
	while (directories[i])
	{
		cmd_path = construct_cmd_path(directories[i], cmd_name);
		if (access(cmd_path, F_OK | X_OK) == 0)
		{
			free_arr(directories);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	free_arr(directories);
	return (NULL);
}
void	call_cmd(char *cmd, char *env[])
{
	char	**cmd_args;
	char	*cmd_path;

	cmd_args = ft_split(cmd, ' ');
	if (!cmd_args)
		error_msg("malloc", NULL);
	cmd_path = get_cmd_path(cmd_args[0], env);
	if (!cmd_path)
	{
		ft_putstr_fd("pipex: command not found: ", STDERR_FILENO);
		ft_putstr_fd(cmd_args[0], STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		free_arr(cmd_args);
		exit(EXIT_FAILURE);
	}
	if (execve(cmd_path, cmd_args, env) == -1)
	{
		free(cmd_path);
		free_arr(cmd_args);
		error_msg("execve", NULL);
	}
}

