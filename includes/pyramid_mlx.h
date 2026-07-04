/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid_mlx.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 01:10:40 by jleray            #+#    #+#             */
/*   Updated: 2026/06/27 01:10:43 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PYRAMID_MLX_H
# define PYRAMID_MLX_H

# include "./libft/include/libft.h"
# include "./minilibx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// -- WINDOW SIZE --
# define WIDTH 800
# define HEIGHT 800

// -- KeyBoard Close --
# define K_ESC 65307

// -- Moving Keys --
# define K_A 97
# define K_D 100
# define K_S 115
# define K_W 119

// -- KeyBoard Arrow --
# define K_LEFT 65361
# define K_UP 65362
# define K_RIGHT 65363
# define K_DOWN 65364

typedef struct s_moves
{
	int			forward;
	int			backward;
	int			left;
	int			right;
	int			left_turn;
	int			right_turn;
}				t_moves;

typedef struct s_ray
{
	double		camera_x;
	double		dir_x;
	double		dir_y;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	double		wall_dist;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
}				t_ray;

typedef struct s_pos
{
	double		x;
	double		y;
}				t_pos;

typedef struct s_dir
{
	double		x;
	double		y;
}				t_dir;

typedef struct s_plane
{
	double		x;
	double		y;
}				t_plane;

typedef struct s_player
{
	t_ray		ray;
	t_pos		pos;
	t_dir		dir;
	t_plane		plane;
	t_moves		moves;
	double		rotation_speed;
	double		time;
	double		old_time;
	double		velocity;
}				t_player;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_lenght;
	int			endian;
}				t_img;

typedef struct s_map
{
	t_pos		starting_coord;
	t_player	player;
	char		**map_tab;
	void		*mlx;
	void		*win;
	t_img		img;
	int			width;
	int			height;
}				t_map;

// -- falsemap Function --
void			fill_fmap(t_map *map);

// -- Free Function --
void			f_init(t_map *map);

// -- Pyramid Hook Function --
int				handlebutton(int button, int x, int y, void *map);
int				handlekey_release(int keycode, void *map);
int				handlekey_press(int keycode, void *map);
int				close_app(t_map *map);

// -- mlx_tools Function --
void			my_mlx_pixel_put(t_map *map, int x, int y, int color);

// -- pyramid_init Function --
int				pyramid_loop(t_map *map);

// -- pyramid_math Function --
void			rotate_vector(t_map *map, double angle);

// -- pyramid_draw Function --
int				draw_frame(t_map *map);

// -- pyramid_draw_tools Function --
void			calc_deltadist(t_ray *ray);
void			calc_sidedist(t_ray *ray, t_map *map);
void			calc_drawing_value(t_ray *ray);

// -- player_handler SECTION --
// -- player Function --
void			player_init(t_map *map);
void			apply_movement(t_map *map);
int				player_moved(t_player *player);
#endif
