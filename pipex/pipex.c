/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memillet <memillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 06:26:39 by memillet          #+#    #+#             */
/*   Updated: 2025/11/28 20:47:08 by memillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1(int *file, int *pipefd, char **av, char **envp)
{
	char	*cmd1;
	char	**cmd1_args;
	char	**path;

	path = get_all_path(envp);
	cmd1_args = split_cmd(av[2]);
	if (!cmd1_args)
		return (free_split(path), ft_close_all_fd(file, pipefd), exit(1));
	cmd1 = get_cmd_path(av[2], path);
	free_split(path);
	if (!cmd1)
	{
		write(2, "Error : invalid command 1\n", 26);
		return (free_split(cmd1_args), ft_close_all_fd(file, pipefd), exit(1));
	}
	close(file[1]);
	dup2(file[0], STDIN_FILENO);
	close(file[0]);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	execve(cmd1, cmd1_args, envp);
	if (execve(cmd1, cmd1_args, envp) == -1)
		return (free(cmd1), free_split(cmd1_args),
			ft_close_all_fd(file, pipefd), exit(1));
}

void	child2(int *file, int *pipefd, char **av, char **envp)
{
	char	*cmd2;
	char	**cmd2_args;
	char	**path;

	path = get_all_path(envp);
	cmd2_args = split_cmd(av[3]);
	if (!cmd2_args)
		return (free_split(path), ft_close_all_fd(file, pipefd), exit(1));
	cmd2 = get_cmd_path(av[3], path);
	free_split(path);
	if (!cmd2)
	{
		write(2, "Error : invalid command 2\n", 26);
		return (free_split(cmd2_args), ft_close_all_fd(file, pipefd), exit(1));
	}
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	dup2(file[1], STDOUT_FILENO);
	close(file[0]);
	close(file[1]);
	execve(cmd2, cmd2_args, envp);
	if (execve(cmd2, cmd2_args, envp) == -1)
		return (free(cmd2), free_split(cmd2_args),
			ft_close_all_fd(file, pipefd), exit(1));
}

void	parent(int *file, int *pipefd)
{
	wait(NULL);
	close(pipefd[1]);
	wait(NULL);
	close(pipefd[0]);
	close(file[0]);
	close(file[1]);
}

void	ft_pipex(int *file, char **av, char **envp)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;

	pipe(pipefd);
	pid1 = fork();
	if (pid1 == 0)
		child1(file, pipefd, av, envp);
	else
	{
		pid2 = fork();
		if (pid2 == 0)
			child2(file, pipefd, av, envp);
		else
			parent(file, pipefd);
	}
	close (pipefd[0]);
	close (pipefd[1]);
}

int	main(int ac, char **av, char **envp)
{
	int		file[2];

	if (ac == 5)
	{
		file[0] = open(av[1], O_RDONLY);
		if (file[0] < 0)
			perror("Error ");
		file[1] = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (file[1] < 0)
		{
			close(file[0]);
			perror("Error ");
		}
		ft_pipex(file, av, envp);
		close(file[0]);
		close(file[1]);
	}
	else
	{
		write(2, "Error : invalid number of arguments\n", 36);
		return (1);
	}
	return (0);
}
