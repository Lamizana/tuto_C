/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:22:20 by alamizan          #+#    #+#             */
/*   Updated: 2022/12/01 10:11:15 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	ft_push_swap(int*a, int*b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	*ft_rrange(int start, int end)
{
	int	*tab;
	int	i;
	int	tmp;
	int	flag;

	flag = 0;
	i = 0;
	if (start == 0 && end == 0)
	{
		tab = malloc(sizeof(int));
		tab[0] = 0;
		return (tab);
	}
	if (start > end)
	{
		ft_push_swap(&start, &end);
		flag = 1;
	}
	tmp = start;
	while (tmp <= end)
	{
		tmp++;
		i++;
	}
	tab = malloc(sizeof(int) * i);
	if (flag == 1)
		ft_push_swap(&start, &end);
	i = 0;
	while (start >= end)
	{
		tab[i] = end;
		end++;
		i++;
	}
	while (start <= end)
	{
		tab[i] = end;
		end--;
		i++;
	}
	return (tab);
}
/*
int main(void)
{
	int *tab;

	tab = ft_rrange(10, 8);
	printf("%d\n", tab[0]);
	printf("%d\n", tab[1]);
	printf("%d\n", tab[2]);
	printf("%d\n", tab[3]);
	return (0);
}
*/
