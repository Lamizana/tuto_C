/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:24:27 by alamizan          #+#    #+#             */
/*   Updated: 2022/11/30 13:42:32 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	nb_arg;
	int	i;

	if (argc > 1)
	{
		nb_arg = 1;
		while (nb_arg < argc)
		{
			i = 0;
			while (argv[nb_arg][i] == ' ' || argv[nb_arg][i] == '\t')
				write(1, &argv[nb_arg][i++], 1);
			if ((argv[nb_arg][i] >= 'a' && argv[nb_arg][i] <= 'z') 
						&& (argv[nb_arg][i+1] == ' ' || argv[nb_arg][i+1] == '\t'))
			{
				argv[nb_arg][i] -= 32;
				write(1, &argv[nb_arg][i], 1);
				i++;
			}	
			while (argv[nb_arg][i] != '\0')
			{
				if (argv[nb_arg][i] >= 'A' && argv[nb_arg][i] <= 'Z') 
					argv[nb_arg][i] += 32;

				if ((argv[nb_arg][i] >= 'a' && argv[nb_arg][i] <= 'z') 
						&& (argv[nb_arg][i + 1] == ' ' 
							|| argv[nb_arg][i + 1] == '\t' 
							|| argv[nb_arg][i + 1] == '\0') 
						&& (argv[nb_arg][i - 1] == ' ' || argv[nb_arg][i - 1] == '\t'))
					argv[nb_arg][i] -= 32;

				if ((argv[nb_arg][i] >= 'a' && argv[nb_arg][i] <= 'z') 
						&& (argv[nb_arg][i + 1] == ' ' 
							|| argv[nb_arg][i + 1] == '\t' 
							|| argv[nb_arg][i + 1] == '\0') 
						&& (argv[nb_arg][i-1] >= 'a' && argv[nb_arg][i-1] <= 'z'))
					argv[nb_arg][i] -= 32;

				write(1, &argv[nb_arg][i], 1);
				i++;
			}
			nb_arg++;
			write(1, "\n", 1);
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}

