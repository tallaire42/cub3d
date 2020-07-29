/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 19:58:52 by tallaire          #+#    #+#             */
/*   Updated: 2020/05/27 19:58:53 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		check_param_file(t_env *env)
{
	size_t		i;
	size_t		j;
	size_t		k;
	int		ret;

	i = 0;
	j = 0;
	ret = 0;
	while (env->vars.map && env->vars.map[j])
	{
		k = 0;
		i = 0;
		while (env->vars.map[j][0] == '\0')
			++j;
		while (env->vars.map[j][i] == ' ')
			++i;
		while (env->vars.map[j][i + k] >= 'A' &&
		env->vars.map[j][i + k] <= 'Z' &&
		env->vars.map[j][i + k] != ' ')
			++k;
		if ((k > 2 || env->vars.map[j][i + k] != ' ')
		&& (ret = is_map_start(env->vars.map[j])) < 0)
			return (-1);
		if (ret > 0)
			break ;
		++j;
	}
	return (1);
}