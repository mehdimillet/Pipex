/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 08:35:54 by memillet          #+#    #+#             */
/*   Updated: 2025/11/28 20:53:16 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split(char **s)
{
	int	j;

	j = 0;
	if (!s)
		return ;
	while (s[j])
		free(s[j++]);
	free(s);
}

char	*get_cmd_path(char *cmd, char **path)
{
	char	**split_cmd;
	char	*fullpath;
	char	*tmp;
	int		i;

	i = 0;
	split_cmd = ft_split(cmd, ' ');
	if (!split_cmd || cmd[0] == '\0')
		return (NULL);
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		if (!tmp)
			return (free_split(split_cmd), NULL);
		fullpath = ft_strjoin(tmp, split_cmd[0]);
		if (!fullpath)
			return (free(tmp), free_split(split_cmd), NULL);
		if (access(fullpath, X_OK) == 0)
			return (free(tmp), free_split(split_cmd), fullpath);
		free(tmp);
		free(fullpath);
		i++;
	}
	perror("Error ");
	return (free_split(split_cmd), NULL);
}

char	**split_cmd(char *cmd)
{
	char	**tab;

	if (!cmd)
		return (NULL);
	tab = ft_split(cmd, ' ');
	if (!tab)
		return (NULL);
	return (tab);
}

char	**get_all_path(char **envp)
{
	char	*tmp;
	char	**path;
	int		i;

	i = 0;
	tmp = NULL;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			tmp = envp[i] + 5;
			break ;
		}
		i++;
	}
	if (!tmp)
		return (NULL);
	path = ft_split(tmp, ':');
	if (!path)
	{
		perror("Error ");
		return (NULL);
	}
	return (path);
}

void	ft_close_all_fd(int *file, int *pipefd)
{
	close(file[0]);
	close(file[1]);
	close(pipefd[0]);
	close(pipefd[1]);
}
