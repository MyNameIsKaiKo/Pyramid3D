/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 13:45:29 by jleray            #+#    #+#             */
/*   Updated: 2026/07/23 13:45:29 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	calc_transform(t_ctx *ctx, t_sprite_calc *calc, int i)
{
	double		inversion;
	t_player	*player;
	t_vec2		delta;

	player = &ctx->player;
	delta = get_delta(ctx, i);
	inversion = 1.0 / (player->plane.x * player->dir.y - player->dir.x
			* player->plane.y);
	calc->t_x = inversion * (player->dir.y * delta.x - player->dir.x * delta.y);
	if (calc->t_x == 0)
		calc->t_x = 1.0 / 1e30f;
	calc->t_y = inversion * (-player->plane.y * delta.x + player->plane.x
			* delta.y);
	if (calc->t_y == 0)
		calc->t_y = 1.0 / 1e30f;
}

void	setup_base_calc(t_sprite_calc *calc)
{
	calc->screen_x = (int)(WIDTH / 2 * (1 + (calc->t_x / calc->t_y)));
	calc->sprite_w = (int)(fabs(HEIGHT / calc->t_y));
	calc->sprite_h = (int)(fabs(HEIGHT / calc->t_y));
}

void	sprite_draw_calc(t_sprite_calc *calc)
{
	calc->draw_start_y = -(calc->sprite_h / 2) + (HEIGHT / 2);
	if (calc->draw_start_y < 0)
		calc->draw_start_y = 0;
	calc->draw_end_y = (calc->sprite_h / 2) + (HEIGHT / 2);
	if (calc->draw_end_y >= HEIGHT)
		calc->draw_end_y = HEIGHT - 1;
	calc->stripe = -(calc->sprite_w / 2) + calc->screen_x;
	if (calc->stripe < 0)
		calc->stripe = 0;
	calc->draw_end_x = (calc->sprite_w / 2) + calc->screen_x;
	if (calc->draw_end_x >= WIDTH)
		calc->draw_end_x = WIDTH - 1;
}
