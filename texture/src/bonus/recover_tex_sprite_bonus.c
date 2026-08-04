/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recover_tex_sprite_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 18:27:20 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/29 15:35:57 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	parse_sprite_path(char *path_sprite)
{
	int	fd;

	fd = open(path_sprite, O_RDONLY);
	if (fd < 0)
		return (print_error("A sprite texture is inaccessible"));
	close(fd);
	return (0);
}

/** @brief check if tab have the good nb of textures
return 1 if false*/
int	check_nb_frame(char **tab, int target)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	if (i != target)
		return (1);
	return (0);
}

int	sprite_recover(char *line, t_ctx *ctx)
{
	char	**split;
	int		output;

	output = 0;
	split = ft_split(line, ' ');
	if (!split)
		return (print_error("Malloc failed"));
	if (split[0][0] == 'L')
		output = lutin_sprite(split, ctx);
	else if (split[0][0] == 'M')
		output = moine_sprite(split, ctx);
	else if (split[0][0] == 'P')
		output = pirate_sprite(split, ctx);
	free_matrix(split);
	return (output);
}
