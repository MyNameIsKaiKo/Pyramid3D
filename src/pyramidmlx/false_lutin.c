/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   false_lutin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 17:43:29 by jleray            #+#    #+#             */
/*   Updated: 2026/07/22 17:43:29 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	false_lutin(t_ctx *ctx)
{
	int w;
	int h;
	char *texs[5];
	char *tex;

	tex = ft_strdup("texture/assets/lutin/lutin1.xpm");
	texs[0] = tex;
	ctx->lutin.pos.x = 3.5;
	ctx->lutin.pos.y = 3.5;
	ctx->lutin.frame = 0;
}
