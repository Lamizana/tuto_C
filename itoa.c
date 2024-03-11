#include <stdio.h>
#include <stdlib.h>

static int	len_nb(int nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static void nb_to_nbstr(char *nb_str, int nb, int len)
{
	int	signe;
	int	i;

	i = 0;
	signe = 0;
	if (nb < 0)
	{
		signe++;
		nb *= -1;
	}
	while (i < len)
	{
		nb_str[len - i] = nb % 10 + 48;
		nb /= 10;
		i++;
	}
	if (signe == 1)
		nb_str[len - i] = '-';
	nb_str[i] = '\0';
}

char	*ft_itoa(int nb)
{
	char	*nb_str;
	int		signe;
	int		len;
	int		i;

	signe = 0;
	i = 0;
	len = len_nb(nb);
	printf("%d\n", len);
	nb_str = malloc(sizeof(char) * (len + 1));
	if (!nb_str)
		return (NULL);
	if (nb == 0)
	{
		nb_str[0] = '0';
		nb_str[1] = '\0';
		return (nb_str);
	}
	//nb_to_nbstr(nb_str, nb, len);
	if (nb < 0)
	{
		signe++;
		nb *= -1;
	}
	while (i < len)
	{
		nb_str[len - i - 1] = (nb % 10) + 48;
		nb /= 10;
		i++;
	}
	if (signe == 1)
		nb_str[len - i] = '-';
	nb_str[i] = '\0';
	printf("%s\n", nb_str);
	return (nb_str);
}

int main()
{
	int nb = 45;
	char *str;

	str = ft_itoa(nb);
	printf("%s\n", str);
	return (0);
}
