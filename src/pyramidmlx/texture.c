/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 01:13:49 by jleray            #+#    #+#             */
/*   Updated: 2026/07/05 01:13:49 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pyramid_mlx.h"

void	calc_wallx(t_map *map)
{
	t_player	*player;
	t_ray		*ray;

	player = &map->player;
	ray = &player->ray;
	if (ray->side == 0)
		map->tex.wallx = player->pos.y + ray->wall_dist * ray->dir_y;
	if (ray->side == 1)
		map->tex.wallx = player->pos.x + ray->wall_dist * ray->dir_x;
	map->tex.wallx = map->tex.wallx - (int)map->tex.wallx;
}

void	calc_tex_x(t_map *map)
{
	t_player	*player;
	t_ray		*ray;
	t_texture	*tex;

	player = &map->player;
	ray = &player->ray;
	tex = &map->tex;
	tex->x = (int)(tex->wallx * tex->witdh);
	if (ray->side == 0 && ray->dir_x > 0)
		tex->x = tex->witdh - tex->x - 1;
	if (ray->side == 1 && ray->dir_y < 0)
		tex->x = tex->witdh - tex->x - 1;
}

void	calc_tex_step(t_map *map)
{
	t_ray		*ray;
	t_texture	*tex;

	ray = &map->player.ray;
	tex = &map->tex;
	tex->step = (1.0 * tex->height) / ray->line_height;
}

void	calc_tex_start(t_map *map)
{
	t_ray		*ray;
	t_texture	*tex;

	ray = &map->player.ray;
	tex = &map->tex;
	tex->start = (ray->draw_start - (HEIGHT / 2) + (ray->line_height / 2))
		* tex->step;
}

int	get_texture_pixel(t_img *tex_img, int x, int y)
{
	char	*dst;

	dst = tex_img->addr + (y * tex_img->line_lenght + x
			* (tex_img->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}
