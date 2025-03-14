/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:17:56 by saeby             #+#    #+#             */
/*   Updated: 2025/03/14 13:36:58 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	key_handler(int keycode, t_vars *vars)
{
	if (keycode == 53 || keycode == XK_Escape)
		close_window(vars);
	else if ((keycode == 2 || keycode == XK_d) && !vars->won)
		update_player_position(vars, (t_point){vars->player.pos.px_x + 1, \
													vars->player.pos.px_y});
	else if ((keycode == 0 || keycode == XK_a) && !vars->won)
		update_player_position(vars, (t_point){vars->player.pos.px_x - 1, \
													vars->player.pos.px_y});
	else if ((keycode == 13 || keycode == XK_w) && !vars->won)
		update_player_position(vars, (t_point){vars->player.pos.px_x, \
												vars->player.pos.px_y - 1});
	else if ((keycode == 1 || keycode == XK_s) && !vars->won)
		update_player_position(vars, (t_point){vars->player.pos.px_x, \
												vars->player.pos.px_y + 1});
	return (0);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_linelen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

int	check_map_name(char *s)
{
	size_t	l;

	l = ft_strlen(s) - 1;
	if (s[l] == 'r' && s[l - 1] == 'e' && s[l - 2] == 'b' && s[l - 3] == '.')
		return (0);
	return (1);
}
