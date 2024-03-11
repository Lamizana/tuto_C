/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 07:43:27 by alamizan          #+#    #+#             */
/*   Updated: 2022/11/28 08:50:37 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	int		i = 0;
	int		j = 0;
	int		len = 0;
	int		flag = 0;
	char	*str;

	if (argc > 1)
	{
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		flag = i;
		while (argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i] != '\0')
		{
			i++;
			len++;
		}	
		str = malloc(sizeof(char) * len + 1);
		i = flag;
		while (j < len)
			str[j++] = argv[1][i++];
		str[j] = '\0';
		while ((argv[1][i] == ' ' || argv[1][i] == '\t') && (argv[1][i] != '\0'))
			i++;
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i] != '\0')
				write(1, &argv[1][i], 1);
			else if ((argv[1][i] == ' ' || argv[1][i] == '\t') 
					&& (argv[1][i + 1] != ' ' && argv[1][i + 1] != '\t' && argv[1][i] != '\0'))
				write(1, " ", 1);
			i++;
			flag = 1;
		}
		if (argv[1][i] == '\0' && flag == 1)
			write(1, " ", 1);
		ft_putstr(str);
	}
	else
		write(1, "\n", 1);
	return (0);
}
