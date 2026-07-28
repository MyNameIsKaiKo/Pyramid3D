/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_struct_def.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 21:34:12 by ldepenne          #+#    #+#             */
/*   Updated: 2026/07/27 16:37:15 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_STRUCT_DEF_H
# define CUB_STRUCT_DEF_H

# include <stdio.h>

# ifndef BONUS
#  define BONUS 0
# endif

// -- WINDOW SIZE --
# define WIDTH 1920
# define HEIGHT 1080

// -- MINIMAP DATA --
# define START_X 20
# define START_Y 20
# define SIZE_MMAP 240
# define SIZE_BLOCK 20
# define MCOLOR_WALL 0xff3B2E2E
# define MCOLOR_FLOOR 0xffBD9E77
# define MCOLOR_LUTIN 0xff1B610E
# define MCOLOR_MOINU 0xff693F0D
# define MCOLOR_PIRATE 0xff8E4DC9
# define MCOLOR_VOID 0xff070736

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
# define NB_BONUS_TEX_WTHT_SPRITE 8
# define NB_BONUS_TEXTURES 11

// -- Sprites --
# define SWIDTH 128
# define ANIMATIONSPEED 10
# define MAXLFRAME 5
# define MAXMFRAME 3
# define MAXPFRAME 3
# define MAXWFRAME 3

typedef enum e_weapon_state
typedef enum e_weapon_state
{
	W_IDLE,
	W_HOLD,
	W_FIRE
}					t_weapon_state;

typedef enum e_tile_type
{
	FLOOR = '0',
	WALL = '1',
	WALL2 = '2',
	WALL3 = '3',
	WALL4 = '4',
	WALL5 = '5',
	WALL6 = '6',
	EMPTY = ' ',
	N_PLAYER = 'N',
	E_PLAYER = 'E',
	S_PLAYER = 'S',
	W_PLAYER = 'W',
	LUTIN = 'L',
	MOINE = 'M',
	PIRATE = 'P'
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

typedef enum e_bonus_tex
{
	B_WALL1,
	B_WALL2,
	B_WALL3,
	B_WALL4,
	B_WALL5,
	B_WALL6,
	B_F_FLOOR_COLOR,
	B_C_CEILING_COLOR,
	B_L_LUTIN,
	B_M_MOINE,
	B_P_PIRATE
}					t_bonus_tex;

typedef enum e_sp_type
{
	T_LUTIN,
	T_MOINE,
	T_PIRATE,
	T_NULL
}					t_sp_type;

typedef struct s_floor
{
	double			x;
	double			y;
	int				tex_x;
	int				tex_y;
	double			cfloor_x;
	double			cfloor_y;
}					t_floor;

typedef struct s_texture
{
	int				x;
	int				y;
	double			wallx;
	t_floor			floor;
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

typedef struct s_tex_mgnt_bonus
{
	char			*cmp;
	t_bonus_tex		textures;
}					t_tex_mgnt_bonus;

typedef struct s_ttype_mgnt
{
	t_tile_type		tile_type;
}					t_ttype_mgnt;

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_lenght;
	int				endian;
}					t_img;

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
	double			veloville;
	int				hp;
	int				as;
	t_weapon_state	wstate;
	char			*weapon_p[MAXWFRAME];
	t_img			weapon_t[MAXWFRAME];
	int				weapon_w;
	int				weapon_h;
	int				timer;
}					t_player;
typedef struct s_map
{
	char			**parse_map;
	char			**map_tab;
	int				y;
	int				x;
	t_vec2			starting_coord;
	char			p_orient;
	size_t			nb_player;
}					t_map;

typedef struct s_mouse
{
	t_vec2			pos;
	double			sensivity;
}					t_mouse;

typedef struct s_sprite
{
	t_vec2			pos;
	double			dist;
	t_sp_type		type;
}					t_sprite;

typedef struct s_sprites
{
	t_sprite		arr[NB_BONUS_TEXTURES];
	int				count;
	t_img			lutin_t[MAXLFRAME];
	t_img			moine_t[MAXMFRAME];
	t_img			pirate_t[MAXPFRAME];
	char			*lutin_p[MAXLFRAME];
	char			*moine_p[MAXMFRAME];
	char			*pirate_p[MAXPFRAME];
	int				is_l;
	int				is_m;
	int				is_p;
	int				frame;
	double			buffer[WIDTH];
}					t_sprites;

typedef struct s_sprite_calc
{
	double			t_x;
	double			t_y;
	int				screen_x;
	int				sprite_h;
	int				sprite_w;
	int				draw_start_y;
	int				draw_end_y;
	int				tex_x;
	int				tex_y;
	int				stripe;
	int				draw_start_x;
	int				draw_end_x;
	t_img			*tex;
}					t_sprite_calc;

typedef struct s_ctx
{
	t_map			*map;
	t_texture		tex;
	char			*tab_textures[NB_ALL_TEXTURES];
	char			*tab_tex_bonus[NB_BONUS_TEXTURES];
	size_t			n_textures;
	t_img			wall_tex[NB_ALL_TEXTURES];
	t_img			wall_tex_bonus[NB_BONUS_TEXTURES];
	int				colors[NB_COLOR];
	t_img			fandc_tex[NB_COLOR];
	t_img			img;
	t_sprites		sprites;
	t_player		player;
	t_mouse			mouse;
	t_weapon_state	state;
	void			*win;
	void			*mlx;
}					t_ctx;

#endif
