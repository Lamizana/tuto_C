/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 07:46:43 by alamizan          #+#    #+#             */
/*   Updated: 2022/11/29 07:56:47 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_calcul(int n1, int n2, char operateur)
{
	int	resultat;

	resultat = 0;
	if (operateur == '+')
		resultat = n1 + n2;
	else if (operateur == '-')
		resultat = n1 - n2;
	else if (operateur == '*')
		resultat = n1 * n2;
	else if (operateur == '/')
		resultat = n1 / n2;
	else if (operateur == '%')
		resultat = n1 % n2;
	return (resultat);
}

int	main(int argc, char *argv[])
{
	int	n1;
	int	n2;
	int	resultat;

	if (argc == 4)
	{
		n1 = atoi(argv[1]);
		n2 = atoi(argv[3]);
		resultat = ft_calcul(n1, n2, argv[2][0]);
		printf("%d\n", resultat);
	}
	else
		write(1, "\n", 1);
}
