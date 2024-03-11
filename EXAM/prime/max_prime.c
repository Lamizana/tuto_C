/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_prime.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:47:53 by alamizan          #+#    #+#             */
/*   Updated: 2022/11/24 10:25:12 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

// Programe qui prend en argument un nombre positif
// et qui affiche son plus grand nombre premier.
// return une ligne vide si plus de 1 argument.

int	ft_atoi(char *str)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (str[i] >= '0' && str[i] <= '9')
			num = num * 10 + str[i] - '0';
		i++;
	}
	return (num);
}

void	ft_putnbr(int num)
{
	if (num >= 10)
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
	else if (num < 10)
	{
		num = num + '0';
		write(1, &num, 1);
	}
}

int	main(int argc, char *argv[])
{
	int nb;
	int	prime;

	if (argc == 2)
	{
		nb = ft_atoi(argv[1]);
		if (nb == 0)
		{
			write(1, "0\n", 2);
			return (0);
		}
		if (nb == 1)
		{
			write(1, "1\n", 2);
			return (0);
		}
		prime = nb - 1;
		while (prime >= 1)
		{
			if (nb % prime == 0)
			{
				ft_putnbr(prime);
				write(1, "\n", 1);
				return (0);
			}
			prime--;
		}
	}
	write (1, "\n", 1);
	return (0);
}
