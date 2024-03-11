/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:23:53 by alamizan          #+#    #+#             */
/*   Updated: 2022/11/27 11:11:13 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	nb;
	int	signe;

	i = 0;
	nb = 0;
	signe = 0;
	if (str[i] == '-')
	{
		signe++;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] >= '0' || str[i] <= '9')
			nb = nb * 10 + str[i] - '0';
		i++;
	}
	if (signe == 1)
		nb = nb * -1;
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
		n = '0' + n;
		write(1, &n, 1);
	}
}

int	calcul(int a, int b)
{
	int	resultat;

	resultat = a * b;
	return (resultat);
}

int	main(int argc, char *argv[])
{
	int	num;
	int	i;

	i = 1;
	if (argc == 2)
	{
		num = ft_atoi(argv[1]);
		if (num < 0)
			num = 0;
		while (i <= 9)
		{
			ft_putnbr(i);
			write(1, " x ", 3);
			ft_putnbr(num);
			write(1, " = ", 3);
			ft_putnbr(calcul(i, num));
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
