/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_struct_def.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 21:34:12 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/08 19:52:57 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_STRUCT_DEF_H
# define CUB_STRUCT_DEF_H

# include <stdio.h>

# ifndef BONUS
#  define BONUS 0
# endif

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

// -- EXecutable --
# define EXT_FILE ".cub"
# define EXT_TEXT ".xpm"

// -- Textures --
# define NB_COLOR 2
# define NB_TEXTURES 4
# define NB_ALL_TEXTURES 6

typedef enum e_tile_type
{
	FLOOR = '0',
	WALL = '1',
	EMPTY = ' ',
	N_PLAYER = 'N',
	E_PLAYER = 'E',
	S_PLAYER = 'S',
	W_PLAYER = 'W'
}					t_tile_type;

/** @important Textures with paths must be placed before the RGB colours */
typedef enum e_e_textures
{
	NO_WALL,
	SO_WALL,
	WE_WALL,
	EA_WALL,
	FLOOR_COLOR,
	CEILING_COLOR
}					t_e_textures;

typedef struct s_texture
{
	int				x;
	int				y;
	double			wallx;
	int				height;
	int				witdh;
	double			step;
	double			start;
	int				index;
}					t_texture;

typedef struct s_moves
{
	int				forward;
	int				backward;
	int				left;
	int				right;
	int				left_turn;
	int				right_turn;
}					t_moves;

typedef struct s_ray
{
	double			camera_x;
	double			dir_x;
	double			dir_y;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	double			sidedist_x;
	double			sidedist_y;
	double			deltadist_x;
	double			deltadist_y;
	double			wall_dist;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
}					t_ray;

typedef struct s_vec2
{
	double			x;
	double			y;
}					t_vec2;

typedef struct s_tex_mgnt
{
	char			*cmp;
	t_e_textures	textures;
}					t_tex_mgnt;

typedef struct s_ttype_mgnt
{
	t_tile_type		tile_type;
}					t_ttype_mgnt;

typedef struct s_player
{
	t_ray			ray;
	t_vec2			pos;
	t_vec2			dir;
	t_vec2			plane;
	t_moves			moves;
	double			rotation_speed;
	double			time;
	double			old_time;
	// double		velocity;
	double			veloville;
}					t_player;

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_lenght;
	int				endian;
}					t_img;

typedef struct s_map
{
	char			**map_tab;
	int				height;
	int				width;
	// t_pos	starting_coord;
	t_vec2			starting_coord;
	char			p_orient;
	size_t			nb_player;
	// t_player	player;
}					t_map;

typedef struct s_ctx
{
	char			*tab_textures[NB_ALL_TEXTURES];
	t_map			*map;
	size_t			n_textures;
	t_player		player;
	t_img			wall_tex[NB_ALL_TEXTURES];
	int				colors[NB_COLOR];
	t_img			img;
	t_texture		tex;
	void			*win;
	void			*mlx;
}					t_ctx;

#endif
