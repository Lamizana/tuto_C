/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 09:47:08 by alamizan          #+#    #+#             */
/*   Updated: 2022/11/26 11:23:12 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_atoi(char *str)
{
	int	nb;
	int	signe;
	int	i;

	nb = 0;
	signe = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
			signe++;
		if (str[i] >= '0' && str[i] <= '9')
			nb = nb * 10 + str[i] - '0';
		i++;
	}
	if (signe > 0)
		return (nb * -1);
	return (nb);
}

void	ft_putnbr(int n)
{
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else if (n < 10)
	{
		n = n + '0';
		write(1, &n, 1);
	}
}

int	verif_prime(int nb)
{
	int	prime;
	int	i;

	prime = 2;
	i = 1;
	while (prime <= 50000)
	{
		if (nb % prime == 0)
			i++;
		prime++;
	}
	if (i == 2)
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	int	nb;
	int	sum;
	int	prime;

	nb = 0;
	prime = 2;
	sum = 0;
	if (argc == 2)
	{
		nb = ft_atoi(argv[1]);
		if (nb < 0)
		{
			write(1, "0\n", 2);
			return (0);
		}
		while (prime <= nb)
		{
			if (verif_prime(prime) == 1)
				sum = sum + prime;
			prime++;
		}
		ft_putnbr(sum);
		write(1, "\n", 1);
	}
	else
		write(1, "0\n", 2);
	return (0);
}
