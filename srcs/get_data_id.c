/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param_id_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 16:35:27 by tallaire          #+#    #+#             */
/*   Updated: 2020/07/29 16:00:58 by harlock          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	int	get_sprite_path(t_env *env, char *str)
{
	size_t		i;

	i = 0;
	(void)env;
	while (*str != ' ' && *str)
		++str;
	while (*str == ' ' && *str)
		++str;
	if (check_path(str) <= 0)
		return (aie_error("invalid sprite path in data.cub\n"));
	if (!(env->vars.path_sprite = ft_strdup(str)))
		return (aie_error("path sprite, malloc failed\n"));
	return (1);
}


static	void	get_res(t_env *env, char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i] && str[i] != ' ')
		++i;
	while (str && str[i] && str[i] == ' ')
		++i;
	while (str && str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		env->vars.res_x = env->vars.res_x * 10;
		env->vars.res_x = env->vars.res_x + (str[i] - '0');
		++i;
	}
	while (str && str[i] && str[i] == ' ')
		++i;
	while (str && str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		env->vars.res_y = env->vars.res_y * 10;
		env->vars.res_y = env->vars.res_y + (str[i] - '0');
		++i;
	}
	if (env->vars.res_x > 1920)
		env->vars.res_x = 1920;
	if (env->vars.res_y > 1080)
		env->vars.res_y = 1080;
}

int	get_data_id(t_env *env, char *str)
{
	if (*str == 'R')
	{
		get_res(env, str);
		if (env->vars.res_x == 0 || env->vars.res_y == 0)
			return (aie_error("resolution null\n"));
	}
	if (*str == 'S')
		return (get_sprite_path(env, str));
	if (*str == 'F' || *str == 'C')
		return (get_color_ceil_and_floor(env, str));
	return (1);
}
