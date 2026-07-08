/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 01:20:05 by jleray            #+#    #+#             */
/*   Updated: 2026/07/08 13:32:58 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(void)
{
	t_ctx	ctx;

	ft_memset(&ctx, 0, sizeof(t_ctx));
	fill_fmap(&ctx);
	player_init(&ctx);
	pyramid_loop(&ctx);
	return (0);
}
