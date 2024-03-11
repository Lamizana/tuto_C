/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:16:34 by alamizan          #+#    #+#             */
/*   Updated: 2022/12/01 10:27:44 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int	nb;
	int	prime;

	if (argc == 2)
	{
		prime = 2;
		nb = atoi(argv[1]);
		while (prime <= nb)
		{
			if (nb % prime == 0)
			{
				printf("%d", prime);
				nb = nb / prime;
				prime--;
				if (nb != 1)
					printf("*");
			}
			prime++;
		}
	}
	printf("\n");
	return (0);
}
