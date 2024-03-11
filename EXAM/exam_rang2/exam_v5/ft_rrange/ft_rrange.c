/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 07:59:30 by alamizan          #+#    #+#             */
/*   Updated: 2022/11/29 08:36:44 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	ft_push_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	*stock_value(int start, int end, int *tab)
{
	int	i;

	i = 0;
	if (start <= end)
	{
		while (start <= end)
		{
			tab[i] = end;
			end--;
			i++;
		}
	}
	else
	{
		while (start >= end)
		{
			tab[i] = end;
			end++;
			i++;
		}
	}
	return (tab);
}

int	*ft_rrange(int start, int end)
{
	int	*tab;
	int	tmp;
	int	flag;
	int	i;

	flag = 0;
	tmp = 0;
	i = 0;
	if (start == 0 && end == 0)
	{
		tab = malloc(sizeof(int));
		tab[0] = 0;
		return (tab);
	}
	if (end > start)
	{
		ft_push_swap(&start, &end);
		flag = 1;
	}
	tmp = end;
	while (tmp <= start)
	{
		tmp++;
		i++;
	}
	tab = malloc(sizeof(int) * i);
	if (flag == 1)
		ft_push_swap(&start, &end);
	tab = stock_value(start, end, tab);
	return (tab);
}

/*
int	main(void)
{
	int	*tab = ft_rrange(0, -50);

	printf("%d\n", tab[0]);
	printf("%d\n", tab[1]);
	printf("%d\n", tab[2]);
	printf("%d\n", tab[3]);
	return(0);
}
*/
