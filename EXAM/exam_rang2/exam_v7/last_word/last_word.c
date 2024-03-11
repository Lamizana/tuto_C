/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:03:08 by alamizan          #+#    #+#             */
/*   Updated: 2022/12/01 09:19:41 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	main(int argc, char *argv[])
{
	int	len;

	if (argc == 2)
	{
		len = ft_strlen(argv[1]);
		len--;
		while ((argv[1][len] == ' ' || argv[1][len] == '\t') && len != 0)
			len--;
		while ((argv[1][len] != ' ' && argv[1][len] != '\t') && len != 0)
			len--;
		if (argv[1][len] == ' ' || argv[1][len] == '\t')
			len++;
		while ((argv[1][len] != ' ' && argv[1][len] != '\t') && argv[1][len] != '\0')
		{
			write(1, &argv[1][len], 1);
			len++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
