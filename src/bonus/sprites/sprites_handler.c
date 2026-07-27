/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 13:02:50 by jleray            #+#    #+#             */
/*   Updated: 2026/07/25 16:27:20 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	load_sp_frame(t_ctx *ctx, char *path, t_img *tex)
{
	int	w;
	int	h;

	tex->img = mlx_xpm_file_to_image(ctx->mlx, path, &w, &h);
	if (!tex->img)
		printf("\n\nerror with the texture \"%s\"\n\n", path);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bits_per_pixel,
			&tex->line_lenght, &tex->endian);
	if (!tex->addr)
		printf("\n\nerror with the texture \"%s\"\n\n", path);
}

void	load_sprite(t_ctx *ctx)
{
	t_sprites	*sprites;
	int			i;

	sprites = &ctx->sprites;
	i = -1;
	while (++i < MAXLFRAME)
		load_sp_frame(ctx, ctx->sprites.lutin_p[i], &sprites->lutin_t[i]);
	i = -1;
	while (++i < MAXMFRAME)
		load_sp_frame(ctx, ctx->sprites.moine_p[i], &sprites->moine_t[i]);
	i = -1;
	while (++i < MAXPFRAME)
		load_sp_frame(ctx, ctx->sprites.pirate_p[i], &sprites->pirate_t[i]);
}

static void	draw_sprite(t_ctx *ctx, t_sprite_calc *calc, t_img *img)
{
	int	y;
	int	color;
	int	orig_start_x;
	int	orig_start_y;

	orig_start_x = calc->screen_x - (calc->sprite_w / 2);
	orig_start_y = (HEIGHT / 2) - (calc->sprite_h / 2);
	while (calc->stripe < calc->draw_end_x)
	{
		if (calc->t_y > 0 && calc->t_y < ctx->sprites.buffer[calc->stripe])
		{
			calc->tex_x = ((calc->stripe - orig_start_x) * SWIDTH)
				/ calc->sprite_w;
			y = calc->draw_start_y;
			while (y < calc->draw_end_y)
			{
				calc->tex_y = ((y - orig_start_y) * SWIDTH) / calc->sprite_h;
				color = get_texture_pixel(img, calc->tex_x, calc->tex_y);
				if (color != 0x0000FF)
					my_mlx_pixel_put(ctx, calc->stripe, y, color);
				y++;
			}
		}
		calc->stripe++;
	}
}

static t_img	get_right_img(t_sprites *sprites, int i)
{
	t_img	tmp;
	int		current_frame;

	current_frame = sprites->frame / ANIMATIONSPEED;
	if (sprites->arr[i].type == T_LUTIN)
		tmp = sprites->lutin_t[current_frame % 5];
	else if (sprites->arr[i].type == T_MOINE)
		tmp = sprites->moine_t[current_frame % 3];
	else
		tmp = sprites->pirate_t[current_frame % 3];
	return (tmp);
}

void	render_all_sprites(t_ctx *ctx)
{
	t_sprite_calc	calc;
	int				i;
	t_img			tmp;

	i = 0;
	ctx->sprites.frame++;
	set_sprdist(ctx);
	sort_sprdist(&ctx->sprites);
	while (i < ctx->sprites.count)
	{
		if (ctx->sprites.arr[i].type == T_MOINE 
				&& ctx->sprites.arr[i].dist < 0.5)
		{
			player_take_damage(ctx, 100);
		}
		if (ctx->sprites.arr[i].type != T_NULL)
		{
			calc_transform(ctx, &calc, i);
			setup_base_calc(&calc);
			sprite_draw_calc(&calc);
			tmp = get_right_img(&ctx->sprites, i);
			draw_sprite(ctx, &calc, &tmp);
		}
		i++;
	}
}
