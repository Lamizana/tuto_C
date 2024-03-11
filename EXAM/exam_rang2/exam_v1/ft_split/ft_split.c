/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 09:33:32 by alamizan          #+#    #+#             */
/*   Updated: 2022/11/25 11:17:32 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	nb_bloc(char *str)
{
	int	bloc;
	int	i;

	bloc = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i] != '\0')
			bloc++;
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\0')
			i++;
	}
	return (bloc);
}

char	**ft_split(char *str)
{
	char	**tab;
	int		bloc;
	int 	len;
	int		i;
	int		j;
	int		k;
	int		flag;

	bloc = 0;
	len = 0;
	i = 0;
	j = 0;
	k = 0;
	bloc = nb_bloc(str);
	tab = malloc(sizeof(char *) * bloc + 1);
	while (str[i] != '\0')
	{
		while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		flag = i;
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\0')
		{
			i++;
			len++;
		}
		tab[j] = malloc(sizeof(char) * len + 1);
		while(k != len)
		{
			tab[j][k] = str[flag];
			k++;
			flag++;
		}
		tab[j][len] = '\0';
		j++;
		len = 0;
		k = 0;
	}
	tab[bloc] = 0;
	return (tab);
}
