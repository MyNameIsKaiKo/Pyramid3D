/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 13:02:50 by jleray            #+#    #+#             */
/*   Updated: 2026/07/23 15:27:04 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
			y = calc->draw_start_y - 1;
			while (++y < calc->draw_end_y)
			{
				calc->tex_y = ((y - orig_start_y) * SWIDTH) / calc->sprite_h;
				color = get_texture_pixel(img, calc->tex_x, calc->tex_y);
				if (color != 0x000000)
					my_mlx_pixel_put(ctx->mlx, calc->stripe, y, color);
			}
		}
		calc->stripe++;
	}
}

static void	update_animations(t_sprites *sprites)
{
	int tick;
	int anim_speed = 10;

	tick = 1;
	tick++;
	if (tick >= anim_speed)
	{
		sprites->frame++;
		if (sprites->frame >= 5)
			sprites->frame = 0;
		tick = 0;
	}
}

static t_img	get_right_img(t_sprites *sprites, int i)
{
	t_img	tmp;
	int current_frame;

	current_frame = sprites->frame / ANIMATIONSPEED;
	if (sprites->arr[i].type == LUTIN)
		tmp = sprites->lutin_t[current_frame % 5];
	else
		tmp = sprites->moine_t[current_frame % 3];
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
		calc_transform(ctx, &calc, i);
		setup_base_calc(&calc);
		sprite_draw_calc(&calc);
		tmp = get_right_img(&ctx->sprites, i);
		draw_sprite(ctx, &calc, &tmp);
		i++;
	}
}
