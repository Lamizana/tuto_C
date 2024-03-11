/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 09:26:42 by alamizan          #+#    #+#             */
/*   Updated: 2022/11/27 10:22:22 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

// Fonction qui calcule la longeur initial de s
// qui se compose d octet non rejetee:
// parcour s1 et s arrette des qu il trouve reject.

int	cmp(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	len;
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (cmp(s[i], reject) == 1)
			return (i);
		i++;
	}
	return (i);
}
