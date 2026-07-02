/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 15:21:10 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/02 14:16:25 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *tab, size_t current_size, size_t new_size)
{
	void	*new_tab;

	if (new_size < current_size || !tab)
	{
		free(tab);
		return (NULL);
	}
	new_tab = malloc(new_size);
	if (!new_tab)
	{
		free(tab);
		return (NULL);
	}
	ft_memcpy(new_tab, tab, current_size);
	free(tab);
	return (new_tab);
}
