/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_v2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:32:09 by alamizan          #+#    #+#             */
/*   Updated: 2022/11/14 09:52:06 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
// affiche le nombre passe en argument en conction de la base donne.

int	ft_atoi(char *str)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	return (n);
}

void	ft_puthexa_base(int n, int base)
{
	char	*str;

	str = "0123456789abcdef";
	if (n >= base)
	{
		ft_puthexa_base(n / base, base);
		ft_puthexa_base(n % base, base);
	}
	if (n < base)
		write(1, &str[n], 1);
	return ;
}

int	main(int argc, char *argv[])
{
	int	n;
	int	base;

	n = 0;
	if (argc == 3)
	{
		n = ft_atoi(argv[1]);
		base = ft_atoi(argv[2]);
		ft_puthexa_base(n, base);
	}
	else
		write(1, "\n", 1);
	return (0);
}
