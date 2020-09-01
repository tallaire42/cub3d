/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:29:37 by tallaire          #+#    #+#             */
/*   Updated: 2020/09/01 20:25:23 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		new_image(t_env *env)
{
	if (!(env->wall.img = mlx_new_image(env->vars.mlx, env->vars.res_x,
	env->vars.res_y)))
	{
		ft_printf("Error\nGenerating new image failed\n");
		return (-1);
	}
	env->wall.addr = (unsigned int *)mlx_get_data_addr(env->wall.img,
	&env->wall.bpp, &env->wall.line_length, &env->wall.endian);
	return (1);
}

