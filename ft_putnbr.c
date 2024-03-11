/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:32:45 by alamizan          #+#    #+#             */
/*   Updated: 2022/10/31 08:56:23 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>

void ft_putnbr(int n)
{
	if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-n);
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}	
	if (n < 10)
	{
		n = '0' + n;
		write(1, &n, 1);
	}
}

int	main(int argc, char **argv)
{
	int	i = 0;

	if (argc == 1)
		return (0);
	while (i < argc)
		i++;
	ft_putnbr(i-1);
	return (0);
}
