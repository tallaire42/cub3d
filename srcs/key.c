/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 13:33:59 by tallaire          #+#    #+#             */
/*   Updated: 2020/07/06 13:34:01 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_released(int keycode, t_env *env)
{
	if (keycode == 119)
		env->key.forward = 0;
	else if (keycode == 115)
		env->key.back = 0;
	else if (keycode == 97)
		env->key.left = 0;
	else if (keycode == 100)
		env->key.right = 0;
	else if (keycode == 65361)
		env->key.rot_left = 0;
	else if (keycode == 65363)
		env->key.rot_right = 0;
	else if (keycode == 65307)
		env->key.escape = 1;
//	printf("release = %d\n", keycode);
	return (keycode);
}

int	key_pressed(int keycode, t_env *env)
{
	if (keycode == 65307)
		exit_game(env);
	else if (keycode == 119)
		env->key.forward = 1;
	else if (keycode == 115)
		env->key.back = 1;
	else if (keycode == 97)
		env->key.left = 1;
	else if (keycode == 100)
		env->key.right = 1;
	else if (keycode == 65361)
		env->key.rot_left = 1;
	else if (keycode == 65363)
		env->key.rot_right = 1;
//	printf("press = %d\n", keycode);
	return (keycode);
}