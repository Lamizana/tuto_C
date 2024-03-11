/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:17:47 by alamizan          #+#    #+#             */
/*   Updated: 2022/11/30 11:43:40 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i] != 0)
		{
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			{
				if (argv[1][i] >= 'A' && argv[1][i] <= 'M')
					argv[1][i] += 13;
				else if (argv[1][i] > 'M' && argv[1][i] <= 'Z')
					argv[1][i] -= 13;
			}
			else if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
			{
				if (argv[1][i] >= 'a' && argv[1][i] <= 'm')
					argv[1][i] += 13;
				else if (argv[1][i] > 'm' && argv[1][i] <= 'z')
					argv[1][i] -= 13;
			}
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
