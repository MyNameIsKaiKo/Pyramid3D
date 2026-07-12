/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 21:49:26 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/10 12:05:37 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

// -- Local --
# include "cub_struct_def.h"
# include "gnl/get_next_line.h"
# include "libft/include/libft.h"
# include "minilibx/mlx.h"

// -- Externe --
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// -- utils Function --
void	data_player(t_map *map, size_t height, size_t width);
int		print_error(const char *err_msg);
void	free_ctx(t_ctx *ctx);

// -- parsing SECTION --
// -- parsing Function --
int		parse_extention(char *file, char *extention);
int		parsing(char *file, t_ctx *ctx);

// -- parse_textures Function --
int		parse_path(char **tab_textures);
int		parse_textures(char *line_read, t_ctx *ctx);

// -- parse_color Function --
int		parse_color(char **color);

// -- parse_map Function --
int		parse_map(t_map *map);
int		check_line_map(char *line_read, t_map *map);

// -- valid_map Function --
int		valid_lcolumn_border(char **map_tab, size_t height);
int		valid_rcolumn_border(char **map_tab, size_t height);
int		valid_border_line(char **map_tab, size_t max_height);

// -- falsemap Function --
void	fill_fmap(t_ctx *ctx);
void	texture_data(t_ctx *ctx);

// -- Free Function --
void	f_init(t_ctx *ctx);
void	map_free(t_map *map);
void	tex_free(t_ctx *ctx);

// -- Pyramid Hook Function --
int		handlebutton(int button, int x, int y, void *map);
int		handlekey_release(int keycode, void *map);
int		handlekey_press(int keycode, void *map);
int		close_app(t_ctx *ctx);

// -- mlx_tools Function --
void	my_mlx_pixel_put(t_ctx *ctx, int x, int y, int color);

// -- pyramid_init Function --
int		pyramid_loop(t_ctx *ctx);

// -- pyramid_math Function --
void	rotate_vector(t_ctx *ctx, double angle);

// -- pyramid_draw Function --
int		draw_frame(t_ctx *ctx);

// -- pyramid_draw_tools Function --
void	calc_deltadist(t_ray *ray);
void	calc_sidedist(t_ray *ray, t_ctx *ctx);
void	calc_drawing_value(t_ray *ray);
void	setup_draw_img(t_ctx *ctx);

// -- texture Function --
void	calc_tex_start(t_ctx *ctx);
void	calc_tex_step(t_ctx *ctx);
void	calc_tex_x(t_ctx *ctx);
void	calc_wallx(t_ctx *ctx);
int		get_texture_pixel(t_img *tex_img, int x, int y);
void	calc_tex_y(t_ctx *ctx);
void	get_tex_index(t_ctx *ctx);

// -- player_handler SECTION --
// -- player Function --
void	player_init(t_ctx *ctx);
void	apply_movement(t_ctx *ctx);
int		player_moved(t_player *player);

// -- player_movement Function --
void	player_forward(t_ctx *ctx);
void	player_backward(t_ctx *ctx);
void	player_right(t_ctx *ctx);
void	player_left(t_ctx *ctx);

// -- BONUS SECTION --
// -- Parser bonus Function --
int		parse_color_bonus(char **color);

#endif
