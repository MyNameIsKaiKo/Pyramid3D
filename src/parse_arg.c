/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 18:55:26 by ldepenne          #+#    #+#             */
/*   Updated: 2026/06/25 18:56:45 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pyramid.h"

int	parse_name(char *s)
{
	char	*ext;
	int		size_ext;

	ext = ft_strrchr(s, '.');
	size_ext = ft_strlen(ext);
	if (ft_strncmp(ext, ".cub", size_ext + 1) != 0)
	{
		print_error("Enter a <file_name>.cub");
		return (1);
	}
	return (0);
}
