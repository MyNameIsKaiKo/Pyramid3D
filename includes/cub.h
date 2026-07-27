/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 21:49:26 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/24 18:52:25 by ldepenne         ###   ########.fr       */
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
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// -- Free Function --
void	f_init(t_ctx *ctx);
void	tex_free(t_ctx *ctx);
void	free_ctx(t_ctx *ctx);

// -- Free_map Function --
void	free_parse_map(t_map *map);
void	free_map_tab(t_map *map);

// -- utils Function --
void	data_player(t_map *map, size_t y, size_t x);
int		print_error(const char *err_msg);
size_t	ft_strcharlen(char *s, char c);

// -- parsing SECTION --
// -- parsing Function --
int		parse_extention(char *file, char *extention);
int		parsing(char *file, t_ctx *ctx);

// -- parse_textures Function --
int		parse_path(char **tab_textures);
int		parse_textures(char *line_read, t_ctx *ctx);

// -- parse_color Function --
int		parse_color(char **color);

// -- copy_map Function --
int		space_in_map(char **tab, size_t y, size_t x);
int		copy_map(t_map **map);

// -- parse_map Function --
int		parse_map(t_map *map);
int		check_line_map(char *line_read, t_map *map);

// -- valid_map Function --
int		valid_lcolumn_border(char **tab, size_t y);
int		valid_rcolumn_border(char **tab, size_t y);
int		valid_border_line(char **tab, size_t max_y);

// -- falsemap Function --
void	fill_fmap(t_ctx *ctx);
void	texture_data(t_ctx *ctx);

// -- Pyramid Hook Function --
int		handlebutton(int button, int x, int y, void *map);
int		handlebutton_release(int button, int x, int y, void *data);
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
void	set_north(t_player *player);
void	set_south(t_player *player);
void	set_east(t_player *player);
void	set_west(t_player *player);

// -- player_movement Function --
void	player_forward(t_ctx *ctx);
void	player_backward(t_ctx *ctx);
void	player_right(t_ctx *ctx);
void	player_left(t_ctx *ctx);
void	protect_player(t_ctx *ctx);

// -- player_mouse Function --
int		mouse_handler(int x, int y, t_ctx *ctx);
void	mouse_init(t_ctx *ctx);

// -- draw cross air Function --
void	draw_crossair(t_ctx *ctx);

// -- BONUS SECTION --
void	init_bonus(t_ctx *ctx);
// -- draw_bonus Function --
void	calc_floorxy(t_ctx *ctx);
void	calc_floortex(t_ctx *ctx, int y);
void	draw_img_bonus(t_ctx *ctx, int x);
void	draw_bonus(t_ctx *ctx);

// -- minimap_bonus Function --
void	print_minimap(t_ctx *ctx);

// -- display_minimap_bonus Function --
void	display_map(t_ctx *ctx);

// -- parse_map_bonus Function --
int		parse_map_bonus(t_ctx *ctx);

// -- parse_tex_bonus Function --
int		parse_path_bonus(char **textures);
int		parse_tex_bonus(char *line_read, t_ctx *ctx);

// -- utils_bonus Function --
bool	iswall(t_tile_type c);
int		close_map(char **tab, size_t y, size_t x);
void	data_sprite(t_ctx *ctx, size_t y, size_t x, t_sp_type type);
void	free_bonus_struct(t_ctx *ctx);

// -- parsing_bonus Function --
int		parsing_bonus(char *file, t_ctx *ctx);

// -- Texture_data_bonus Function --
void	texture_data_bonus(t_ctx *ctx, int *w, int *h);

// -- Sprites SECTION --
void	render_all_sprites(t_ctx *ctx);
void	load_sprite(t_ctx *ctx);

// -- Sprites Tools Function --
t_vec2	get_delta(t_ctx *ctx, int i);
void	set_sprdist(t_ctx *ctx);
void	sort_sprdist(t_sprites *sprites);

// -- Sprites Calc Function --
void	sprite_draw_calc(t_sprite_calc *calc);
void	setup_base_calc(t_sprite_calc *calc);
void	calc_transform(t_ctx *ctx, t_sprite_calc *calc, int i);

// -- recover_tex_sprite_bonus Function --
int		sprite_recover(char *line, t_ctx *ctx);

// -- Weapon Function --
void	false_gun(t_ctx *ctx);
void	draw_gun(t_ctx *ctx);

// -- Player Health Function --
void	player_take_damage(t_ctx *ctx, int amount);
void	init_player_bonus(t_ctx *ctx);


#endif
