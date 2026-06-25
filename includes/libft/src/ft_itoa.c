/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:10:04 by ldepenne          #+#    #+#             */
/*   Updated: 2026/01/21 15:32:00 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	count_unit(long n)
{
	int	nb_unit;

	nb_unit = 0;
	if (n < 0)
	{
		n *= -1;
		nb_unit++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		nb_unit++;
	}
	return (nb_unit);
}

static void	convert_number(long n, char **str)
{
	int	sign;
	int	nb;
	int	i;

	sign = 0;
	i = count_unit(n);
	if (n < 0)
	{
		n *= -1;
		sign = 1;
	}
	(*str)[i] = '\0';
	while (--i >= 0)
	{
		nb = n % 10;
		(*str)[i] = nb + '0';
		n = n / 10;
	}
	if (sign > 0)
		(*str)[0] = '-';
}

char	*ft_itoa(int n)
{
	char	*str;

	str = malloc(sizeof(char) * (count_unit(n) + 1));
	if (!str)
		return (NULL);
	convert_number(n, &str);
	return (str);
}
