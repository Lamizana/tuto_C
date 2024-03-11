/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 11:25:21 by alamizan          #+#    #+#             */
/*   Updated: 2022/11/26 12:18:52 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int	nb;
	int	prime;

	prime = 2;
	if (argc == 2)
	{
		nb = atoi(argv[1]);
		if (nb == 1)
		{
			printf("1\n");
			return (0);
		}
		while (prime <= nb)
		{
			if (nb % prime == 0)
			{
				printf("%d", prime);
				nb = nb / prime;
				if (nb != 1)
					printf("*");
				prime--;
			}
			prime++;
		}
	}
	printf("\n");
}
