/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 08:53:05 by alamizan          #+#    #+#             */
/*   Updated: 2022/11/14 09:28:54 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
// Afficher le nombre passe en argument en hexadecimal -> base 16.

int	ft_atoi(char *str)
{
	int		n;
	int		i;
	int		signe;

	n = 0;
	i = 0;
	signe = 0;
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	return (n);
}

void	ft_putnbr_base(int n)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
	{
		ft_putnbr_base(n / 16);
		ft_putnbr_base(n % 16);
	}
	if (n < 16)
		write(1, &base[n], 1);
	return ;
}

int	main(int argc, char *argv[])
{
	int		n;

	n = 0;
	if (argc == 2)
	{
		n = ft_atoi(argv[1]);
		ft_putnbr_base(n);
	}
	else
		write(1, "\n", 1);
	return (0);
}
