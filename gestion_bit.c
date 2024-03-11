/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_bit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:29:19 by alamizan          #+#    #+#             */
/*   Updated: 2022/11/23 16:23:01 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

// Convertie un caractere en binaire:
char	*char_to_bit(unsigned char octet)
{
	int		i;
	int		bits;
	char	*str_bits;

	i = 0;
	bits = 128;
	str_bits = malloc(9);
	while (bits > 0)
	{
		if (bits & octet)
			str_bits[i] = 1 + '0';
		else
			str_bits[i] = 0 + '0';
		bits >>= 1;
		i++;
	}
	str_bits[9] = '\0';
	return (str_bits);
}

// Convertie binaire en caractere:
char	bit_to_char(char *bit)
{
	int	tab[8];
	char	nb;
	int	i;
	int	j;

	i = 0;
	j = 128;
	nb = 0;
	while (i < 8)
	{
		tab[i] = j;
		printf("tab[%d] -> %d\n", i, tab[i]);
		j /= 2;
		i++;
	}
	while (i > 0)
	{
		if (bit[i] == '1')
			nb = nb + (tab[i]);
		i--;
	}
	return (nb);
}

int	main(void)
{
	char	c;
	char	*bits;

	c = 'X';
	bits = char_to_bit(c);
	printf("- Caractere: %c\t - Binaire: %s\n", c, char_to_bit(c));
	printf("- Binaire: %s\t - Caractere: %c\n", bits, bit_to_char(bits));
	return (0);
}
