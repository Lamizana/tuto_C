/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:13:10 by alamizan          #+#    #+#             */
/*   Updated: 2022/10/26 11:45:42 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strchr(const char *str, char c)
{
	while (*str != c && *str != '\0')
		str++;
	if (*str == c)
		return ((char *)str);
	return (0);
}


int nb_bloc(const char *str, char c)
{
	int i;
	int bloc;

	i = 0;
	bloc = 0;

	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
			bloc++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (bloc);
}

int	ft_strlen(char const *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int ft_calloc(int nb, int size)
{
	void *p_taille;
	int i;
	i = 0;
	p_taille = malloc(nb * size);

}

char **ft_split(char const *str, char c)
{
	char **dest;
	int i;
	int  len;

	dest = ft_calloc(sizeof(char), nb_bloc(str, c) + 1);
	if (!dest)
		return (0);
	i = 0;
	while (*str != '\0')
	{
		while (*str == c && *str != '\0')
			str++;
		if (*str != 0)
		{
			if (!ft_strchr(str,c))
				len = ft_strlen(str);
			else
				len = ft_strchr(str, c) - str;
		}

	}

	return (0);
}
