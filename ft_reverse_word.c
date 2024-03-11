/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_word.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:20:53 by alamizan          #+#    #+#             */
/*   Updated: 2022/11/14 08:36:33 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

// Programme qui prend em argument une chaine de caratere
// et qui reverse chaque mot.

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	main(int argc, char *argv[])
{
	size_t	len;
	int		i;
	char	*str;

	if (argc == 2)
	{
		str = argv[1];
		len = ft_strlen(str);
		while (len != 0)
		{
			if (str[len] == ' ')
			{
				i = 1;
				while (str[len + i] != '\0' && str[len + i] != ' ')
				{
					write(1, &str[len + i], 1);
					i++;
				}
				if (str[len] == ' ')
				{
					write(1, " ", 1);
				}
			}
			len--;
		}
		i = 0;
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
			write(1, &str[i++], 1);
	}
	if (argc < 2 || argc > 2)
		write(1, "\n", 1);
	return (0);
}
