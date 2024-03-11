/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 10:00:48 by alamizan          #+#    #+#             */
/*   Updated: 2023/04/10 10:25:52 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

// EXECUTER PIPE ET REDIRECTION SUR UNE MEME LIGNE DE COMMANDES.

int		nb_cmds(char *argv[]);
char	*ft_strjoin(char const *s1, char const *s2);

// dup2 en fonction du type de fd:
int	choose_process(int in, int out, char *cmds[], char **envp)
{
	pid_t	pid;
	char *str;

	pid = fork();
	if (pid  == 0)
	{
		if (in != 0)
		{
			dup2(in, 0);
			close(in);
		}
		if (out != 1)
		{
			dup2(out, 1);
			close(out);
		}
		str = ft_strjoin("/bin/", cmds[0]);
		execve(str, cmds, envp);
	}
	return (pid);
}

// Execute les process:
void fork_pipes(char *cmds[], const char *redirection)
{
	int i, nb;
	int in, out;
	int fd[2];

	in = 0;
	// compte le nombre de commandes:
	nb = nb_cmds(cmds);
}

int	main(int argc, char *argv[], char **envp)
{
	int	i;
	
	i = nb_cmds(argv);
	printf("%d\n", i);

	
	return (0);
}

int		nb_cmds(char *argv[])
{
	int 	i;
	
	i = 0;
	while (argv[i] != NULL)
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1 || !s2)
		return (0);
	i = strlen(s1);
	j = strlen(s2);
	str = malloc(sizeof(char) * (i + j + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}


