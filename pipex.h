/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pracksaw <pracksaw@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:38:15 by pracksaw          #+#    #+#             */
/*   Updated: 2024/04/29 16:27:26 by pracksaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

//main
int		main(int ac, char **av, char **envp);
//exec
void	call_cmd(char *cmd, char **env);
void	error_msg(char *msg, int *pipe_ends);
void	pipeline_left(char **argv, char **env, int *pipe_ends);
void	pipeline_right(char **argv, char **env, int *pipe_ends);
void	parent(int pid1, int pid2, int *pipe_ends);
//error
void	error_msg(char *msg, int *pipe_ends);
void	print_err(char *pre, char *file, int *pipe_ends);
//utils
void	ft_putstr_fd(char *s, int fd);
char	*ft_strdup(const char *src);
void	str_tolower(char *str);
int		ft_tolower(int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
char	**ft_split(const char *s, char c);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

#endif
