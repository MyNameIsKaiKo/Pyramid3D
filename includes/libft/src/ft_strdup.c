/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:21:55 by ldepenne          #+#    #+#             */
/*   Updated: 2026/06/26 23:45:55 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*result;

	len = ft_strlen(s);
	result = malloc(sizeof(char) * len + 1);
	if (!result)
	{
		ft_putendl_fd("Malloc failed", 2);
		return (NULL);
	}
	result = ft_memcpy(result, s, len + 1);
	return (result);
}
