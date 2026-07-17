/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 13:08:34 by jleray            #+#    #+#             */
/*   Updated: 2026/07/12 13:08:34 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	parse_color_path(char **textures)
{
	int	i;
	int	fd;

	i = 0;
	while (i < 2)
	{
		fd = open(textures[i], O_RDONLY);
		if (fd < 0)
			return (print_error("A texture is inaccessible"));
		i++;
		close(fd);
	}
	return (0);
}

int	parse_color_bonus(char **color)
{
	char	*color_texture[2];
	int		index_color;
	int		i;

	index_color = NB_TEXTURES;
	i = -1;
	while (index_color < NB_ALL_TEXTURES)
	{
		color_texture[++i] = color[index_color];
		if (parse_extention(color_texture[i], EXT_TEXT))
		{
			ft_putendl_fd("BONUS only accept F and C as textures", 2);
			return (1);
		}
		index_color++;
	}
	if (index_color != 6)
	{
		ft_putendl_fd("Eather F's or C's texture is missing", 2);
		return (1);
	}
	if (parse_color_path(color_texture))
		return (1);
	return (0);
}
