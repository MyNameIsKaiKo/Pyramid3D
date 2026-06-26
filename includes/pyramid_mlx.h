/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid_mlx.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 17:19:42 by jleray            #+#    #+#             */
/*                                                                            */
/*   Updated: 2026/06/25 17:19:42 by jleray           ###   ########.fr       */
/* ************************************************************************** */

#ifndef PYRAMID_MLX_H
# define PYRAMID_MLX_H

# include "./libft/include/libft.h"
# include "./minilibx/mlx.h"
# include <math.h>
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

typedef struct s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct s_player
{
	t_pos		coord;
	int			velocity;
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
	t_pos		coord;
	t_player	player;
	float		**map_tab;
	void		*mlx;
	void		*win;
	t_img		img;
}				t_map;

// -- Free Function --
void			f_init(t_map *map);

// -- Pyramid Hook Function --
int				handlebutton(int button, int x, int y, void *map);
int				handlekey_release(int keycode, void *map);
int				handlekey_press(int keycode, void *map);
int				close_app(t_map *map);

#endif
