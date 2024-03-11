/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 09:01:57 by alamizan          #+#    #+#             */
/*   Updated: 2022/11/25 09:31:44 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	*ft_range(int start, int end)
{
	int	*tab;
	int	i;
	int	tmp;
	int flag;

	flag = 0;
	i = 0;
	if(start == end)
	{
		tab = malloc(sizeof(int) * 2);
		tab[0] = start;
		tab[1] = end;
		return (tab);
	}
	if (start > end)
	{
		ft_swap(&start, &end);
		flag = 1;
	}
	tmp = start;
	while (tmp++ <= end)
		i++;
	tab = malloc(sizeof(int) * i);
	i = 0;
	if (flag == 1)
		ft_swap(&start, &end);
	while (start >= end)
	{
		tab[i] = start;
		i++;
		start--;
		flag = 2;
	}
	if (flag == 2)
		return (tab);
	while (start <= end)
	{
		tab[i] = start;
		i++;
		start++;
	}
	return (tab);
}
