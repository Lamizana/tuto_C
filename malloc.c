/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:50:45 by alamizan          #+#    #+#             */
/*   Updated: 2022/06/23 08:23:02 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

// On definit la memoire aloue
#define LEN	50

void	put_str(char *str)
{
	while (*str != '\0')
		write(1, str++, 1);
}

// ALLOCATION DYNAMIQUE DE MEMOIRE MALLOC
int	main (void)
{
	char	*str;
	int	index;

	index = 0;

	// On alloue a str la memoire demamde:
	// On utilise sizeof pour definir le nombre d octet en fct du type de notre variable:
	// On fait un cast pour typer notre char *:
	str = (char*)malloc(sizeof(*str) * (LEN + 1));  // pour '\0'
	
	// On parcour notre chaine et on la remplie:
	while (index < LEN)
	{
		str[index] = 'X';
		index++;
	}
	
	// On rajoute le '\0' a la fin de la chaine:
	str[index] = '\0';

	// On affiche la chaine:
	put_str(str);
	free(str);
	return (0);
}
