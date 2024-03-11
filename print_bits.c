/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:20:53 by alamizan          #+#    #+#             */
/*   Updated: 2022/11/23 10:29:44 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
		i++;
	return (i);
}

// Convertit un nombre en bit.
void	print_bits(unsigned char octet)
{
	int	i;

	i = 128;
	while (i > 0)
	{
		if (i & octet)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i >>= 1;
	}
}

int	send_bits(unsigned char octet)
{
	int	i;
	int	bits;

	i = 128;
	bits = 0;
	while (i > 0)
	{
		if (i & octet)
			bits = bits * 10 + 1;
		else
			bits = bits * 10;
		i >>= 1;
	}
	return (bits);
}

// Convertie un char c en bits;
char	*send_char_to_bit(unsigned char octet)
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

// Convertie un chaine de caracteres en bits:
char *str_bits(char *str)
{
	char *chaine;

	chaine = malloc((sizeof(char) * ft_strlen(str)) * 9);
	while (*str != '\0')
	{
		chaine = send_bit_to_char(*str);
		str++;
	}
	return (chaine);

}

int	main(void)
{
	printf("- send_bit -> %d\n", send_bits('y'));
	printf("- send_bit_to_char -> %s\n", send_bit_to_char('y'));
	write(1, "- vrai valeur -> ", 17);
	print_bits('y');
	return (0);
}
