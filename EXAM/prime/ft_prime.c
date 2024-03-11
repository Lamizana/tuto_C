/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prime.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 06:44:33 by alamizan          #+#    #+#             */
/*   Updated: 2022/11/14 09:55:34 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
// gerer les nombre premiers.

// Affiche un nombre:
void	ft_putnbr(int n)
{
	char	nb;

	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	if (n < 10)
	{
		nb = n + '0';
		write (1, &nb, 1);
	}
}

// multiplie les nombres premiers:
void	ft_prime(int n)
{
	int	prime;

	prime = 2;
	while (prime <= n)
	{
		if (n % prime == 0)
		{
			ft_putnbr(prime);
			n = n / prime;
			if (n != 1)
				write(1, " * ", 3);
			prime--;
		}
		prime++;
	}
}

// change un char en int;
int	ft_atoi(char *nb)
{
	int		n;
	int		i;

	i = 0;
	n = 0;
	if (nb[i] == '-')
		i++;
	while (nb[i] != '\0')
	{
		n = (n * 10) + (nb[i] - '0');
		i++;
	}
	return (n);
}

// Recupere un nombre passe en argument et trouve
// ses nombres premiers:
int	main(int argc, char *argv[])
{
	int		n;
	int		prime;

	n = 0;
	prime = 0;
	if (argc == 2)
	{
		n = ft_atoi(argv[1]);
		if (n == 0)
			write(1, "0", 1);
		else
			ft_prime(n);
	}
	write(1, "\n", 1);
	return (0);
}
