/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 14:30:12 by tallaire          #+#    #+#             */
/*   Updated: 2020/08/24 18:08:11 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		sprite(t_env *env)
{
	int		stripe;
	int		d;
	int		y;
	int		tex_x;
	int		tex_y;
	unsigned	int	color;
	int				u_div;
	int				v_div;
	float			v_move;
	int				v_move_screen;

	stripe = 0;
	d = 0;
	y = 0;
	tex_x = 0;
	tex_y = 0;
	color = 0;
	//spriteX et spriteY
	env->sprite.X = env->sprite.x[0] - env->player.pos_x;
	env->sprite.Y = env->sprite.y[0] - env->player.pos_y;

	// invDet
	env->sprite.inv_det = 1.0 / (env->ray.plane_x * env->ray.dir_y -
	env->ray.dir_x * env->ray.plane_y);

	// transformX et transformY
	env->sprite.transform_x = env->sprite.inv_det * (env->ray.dir_y *
	env->sprite.X - env->ray.dir_x * env->sprite.Y);

	env->sprite.transform_y = env->sprite.inv_det * (-env->ray.plane_y *
	env->sprite.X + env->ray.plane_x * env->sprite.Y);

	// spriteScreenX
	env->sprite.screen_x = (int)(env->vars.res_x / 2) *
	(1 + env->sprite.transform_x / env->sprite.transform_y);

	// define
	u_div = 1;
	v_div = 1;
	v_move = 0.0;
	v_move_screen = (int)(v_move / env->sprite.transform_y);

	// spriteHeight
	env->sprite.height_sprite = abs((int)(env->vars.res_y /
	env->sprite.transform_y)) / u_div;

	// drawStartY et drawEndY
	
	env->sprite.draw_start_y = -env->sprite.height_sprite / 2 +
	env->vars.res_y / 2 + v_move_screen;

	if (env->sprite.draw_start_y < 0)
		env->sprite.draw_start_y = 0;

	env->sprite.draw_end_y = env->sprite.height_sprite / 2 +
	env->vars.res_y / 2 + v_move_screen;

	if (env->sprite.draw_end_y >= env->vars.res_y)
		env->sprite.draw_end_y = env->vars.res_y - 1;

	// spriteWidth
	env->sprite.width_sprite = abs((int)(env->vars.res_y /
	env->sprite.transform_y)) / u_div;

	// drawStartX et drawEndX
	env->sprite.draw_start_x = -env->sprite.width_sprite / 2 +
	env->sprite.screen_x;

	if (env->sprite.draw_start_x < 0)
		env->sprite.draw_start_x = 0;

	env->sprite.draw_end_x = env->sprite.width_sprite / 2 +
	env->sprite.screen_x;

	if (env->sprite.draw_end_x >= env->vars.res_x)
		env->sprite.draw_end_x = env->vars.res_x - 1;

	// stripe, boucle pour print le sprite
	stripe = env->sprite.draw_start_x;
	while (stripe < env->sprite.draw_end_x)
	{
		tex_x = (int)(256 * (stripe - (-env->sprite.width_sprite / 2 +
		env->sprite.screen_x)) * env->sprite.width /
		env->sprite.width_sprite) / 256;

		// condition :
		// 1/ transformY > 0
		// 2/ stripe > 0
		// 2/ stripe < w
		// 3/ transformY < ZBuffer[stripe]
		y = env->sprite.draw_start_y;
		if (env->sprite.transform_y > 0 && stripe > 0 &&
		stripe < env->vars.res_x && env->sprite.transform_y <
		env->sprite.z_buffer[stripe])
		{
			while (y < env->sprite.draw_end_y)
			{
				d = (y - v_move_screen) * 256 - env->vars.res_y * 128 +
				env->sprite.height_sprite * 128;
				tex_y = ((d * env->sprite.height) / env->sprite.height_sprite)
				/ 256;
				color = env->sprite.sprite[env->sprite.width * tex_y + tex_x];
				if ((color & 0X00FFFFFF) != 0)
					my_mlx_pixel_put(env, stripe, y, color);
				++y;
			}
		}
		++stripe;
	}


}















