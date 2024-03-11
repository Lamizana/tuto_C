/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 07:11:17 by alamizan          #+#    #+#             */
/*   Updated: 2023/10/17 07:34:51 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

// ------------------------------------------------------------ //
// GESTION ERRORS:
int	error(char *str, char *argv)
{
	int	i;

	i = 0;
	while (str[i])
		write(2, &str[i], 1);
	i = 0;
	if (argv)
	{
		while (argv[i])
			write(2, &argv[i], 1);
	}
	write(2, "\n", 1);
	return (1);
}

// ------------------------------------------------------------ //
// GESTION EXECUTION:
int	execution(char **argv, int i, int tmp, char **envp)
{
	argv[i] = NULL;
	dup2(tmp, 0);
	close(tmp);
	execve(argv[0], argv, envp);
	return (error("error: cannot execute ", argv[0]));
}

// ------------------------------------------------------------ //
int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	tmp;
	int	fd[2];

	i = 0;
	(void)argc;
	tmp = dup(0);
	while (argv[i] && argv[i + 1])
	{
		argv = &argv[i + 1];
		i = 0;
		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;
		// ------------ CD -------------------//
		if (strcmp(argv[0], "cd") == 0)
		{
			if (i != 2)
				error("error: cd: bad arguments", NULL);
			else if (chdir(argv[1]) != 0)
				error("error: cd: cannot change directory to ", argv[1]);
		}
		// ------------- EXECUTION ------------ //
		else if (i != 0 && (argv[i] == NULL || strcmp(argv[i], ";") == 0))
		{
			if (fork() == 0)
			{
				if (execution(argv, i, tmp, envp))
					return (1);
			}
			else
			{
				close(tmp);
				tmp = dup(0);
				while (waitpid(-1, NULL, WUNTRACED) != -1)
					;
			}
		}
		// --------------- PIPE -------------- //
		else if (i != 0 && strcmp(argv[i], "|") == 0)
		{
			pipe(fd);
			if (fork() == 0)
			{
				dup2(fd[1], 1);
				close(fd[1]);
				close(tmp);
				if (execution(argv, i, tmp, envp))
					return (1);
			}
			else
			{
				close(fd[1]);
				close(tmp);
				tmp = dup(fd[0]);
			}
		}
	}
	close(tmp);
	return (0);
}
