/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid_mlx.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 17:19:42 by jleray            #+#    #+#             */
/*   Updated: 2026/06/25 17:19:42 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PYRAMID_MLX_H
# define PYRAMID_MLX_H

# include "./minilibx/mlx.h"
# include "./libft/include/libft.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>

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

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}			t_img;

typedef struct s_map
{
	float	x;
	float	y;
	float	**map_tab;
	void	*mlx;
	void	*win;
	t_img	img;
}			t_map;

// -- Free Function --
void	f_init(t_map *map);

#endif
