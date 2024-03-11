/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 07:27:00 by alamizan          #+#    #+#             */
/*   Updated: 2022/11/28 07:36:28 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	max(int *tab, unsigned int len)
{
	int				tmp;
	unsigned int	i;

	i = 1;
	if (!tab)
		return (0);
	tmp = tab[0];
	while (i < len)
	{
		if (tab[i] > tmp)
			tmp = tab[i];
		i++;
	}
	return (tmp);
}
