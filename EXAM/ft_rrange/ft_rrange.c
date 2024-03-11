/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 08:12:38 by alamizan          #+#    #+#             */
/*   Updated: 2022/11/19 08:52:35 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	*ft_rrange(int start, int end)
{
	int	*tab;
	int	len;
	int	tmp;
	int	flag;
	int	tmp_start;

	len = 0;
	tmp = 0;
	flag = 0;
	if (start > end)
	{
		ft_swap(&start, &end);
		flag = 1;
	}
	tmp_start = start;
	while (tmp_start <= end)
	{
		len++;
		tmp_start++;
	}
	tab = malloc(sizeof(int) * len);
	if (!tab)
		return (0);
	if (flag == 1)
		ft_swap(&start, &end);
	len = 0;
	if (start > end)
	{
		while (end <= start)
		{
			tab[len] = end;
			end++;
			len++;
		}
	}
	else
	{
		while (end >= start)
		{
			tab[len] = end;
			end--;
			len++;
		}
	}
	return (tab);
}
