/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:21:55 by ldepenne          #+#    #+#             */
/*   Updated: 2026/01/17 16:38:22 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strndup(char *s, size_t n)
{
	size_t	i;
	char	*result;

	if (n > ft_strlen(s))
		return (NULL);
	result = malloc(sizeof(char) * (n + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s && i < n)
	{
		result[i] = s[i];
		i++;
	}
	while (i <= n)
	{
		result[i] = '\0';
		i++;
	}
	return (result);
}
