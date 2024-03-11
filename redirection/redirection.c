/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 09:51:50 by alamizan          #+#    #+#             */
/*   Updated: 2023/03/17 15:23:18 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// LIB open:
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
// LIB readline:
#include <readline/readline.h>
#include <readline/history.h>

// Check open et close:
void	check_fd(int fd, int flag)
{
	if (fd == -1)
	{
		if (flag == 0)
			printf("open() failed\n");
		else if (flag == 1)
			printf("close() failed\n");
		exit (1);
	}
}

// Verifie si c est une redirection simple ou double:
int		check_redirection(char *read)
{
	int		i;

	i = 0;
	if (!*read)
		return (0);
	while (read[i] != '\0')
	{
		if (read[i] == '>' && read[i + 1] != '>')
			return (1);
		if (read[i] == '>' && read[i + 1] == '>')
			return (2);
		if (read[i] == '<' && read[i + 1] != '<')
			return (3);
		i++;
	}
	return (0);
}

// Reupere les 1er commandes.
char	*ft_strdup(char *read, int i)
{
	int		len;
	char	*str;

	len = 0;
	str = malloc(sizeof(char) * (i + 1));
	while (len < i)
	{
		str[len] = read[len];
		len++;
	}
	str[i] = '\0';
	return (str);
}

// renvoie i --> apres ">".
int	get_str(char *read, char **str, int fd)
{
	int		i;
	int		j;

	i = 0;
	if (!*read)
		return (0);
	while (read[i] != '\0')
	{
		if (read[i] == '>')
		{
			*str = ft_strdup(read, i);
			i++;
			if (read[i] == '>')
				i++;
			while (read[i] == ' ')
				i++;
			break ;
		}
		i++;
	}
	return (i);
}

// recupere le nom du fichier.
char	*get_filename(char *read, int flag)
{
	int		len;
	int		i;
	char	*filename;

	i = flag;
	len = 0;
	while (read[flag])
		flag++;
	filename = malloc(sizeof(char) * (flag - i + 1));
	while (i < flag)
	{
		filename[len] = read[i];
		i++;
		len++;
	}
	filename[len] = '\0';
	return (filename);
}

// cree si le fichier n existe pas et ecris dedans.
void	redirection_simple(int fd, char *filename, char *str)
{
	fd = open(filename, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	check_fd(fd, 0);
	write(fd, str, strlen(str));
	close(fd);
	check_fd(fd, 0);
}

// cree si le fichier n existe pas et ecris a la fin.
void	redirection_double(int fd, char *filename, char *str)
{
	fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	check_fd(fd, 0);
	write(fd, str, strlen(str));
	close(fd);
	check_fd(fd, 0);
}

// free tous les elements.
void	ft_free(char *read, char *str, char *filename)
{
	if (str)
		free(str);
	if (read)
		free(read);
	if (filename)
		free(filename);
}

int	main(int argc, char *argv[])
{
	int		fd;
	int		flag;
	char	*filename;
	char	*read;
	char	*str;

	str = NULL;
	read = readline(">");

	flag = get_str(read, &str, fd);
	filename = get_filename(read, flag);
	printf("str= %s\n", str);
	printf("filename= %s\n", filename);

	// redirection: '>' ou '>>'.
	if (check_redirection(read) == 1)
		redirection_simple(fd, filename, str);
	else if (check_redirection(read) == 2)
		redirection_double(fd, filename, str);

	// redirection: '<' ou '<<'.

	ft_free(read, str, filename);
	return (0);
}
