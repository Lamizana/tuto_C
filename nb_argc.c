/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_argc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:10:14 by alamizan          #+#    #+#             */
/*   Updated: 2022/11/24 12:15:57 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void ft_putnbr(int n)
{
	if (n >= 10)
	{
		ft_putnbr(n/10);
		ft_putnbr(n%10);
	}
	else if (n < 10)
	{
		n = n + '0';
		write(1, &n, 1);
	}

}
int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		ft_putnbr(argc -1);
	}
	write(1, "\n", 1);
}

