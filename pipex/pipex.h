/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 05:57:52 by memillet          #+#    #+#             */
/*   Updated: 2025/11/17 03:22:17 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "./libft/libft.h"
# include <errno.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

//fonction dans utils.c

void	free_split(char **s);
char	*get_cmd_path(char *cmd, char **path);
char	**split_cmd(char *cmd);
char	**get_all_path(char **envp);
void	ft_close_all_fd(int *file, int *pipefd);

//fonction dans pipex.c
#endif
