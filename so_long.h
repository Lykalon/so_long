/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lykalon <lykalon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:28:44 by lykalon           #+#    #+#             */
/*   Updated: 2022/06/22 20:28:58 by lykalon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include <fcntl.h>
# include "mlx.h"
# define SPEED 4

typedef struct s_map
{
	char			*line;
	struct s_map	*next;
}			t_map;

typedef struct s_mlx_data
{
	void	*mlx;
	void	*wnd;

	void	*p;
	void	*c;
	void	*wl;
	void	*door;
	void	*d_c;
	void	*d_o;
	void	*s;

	char	*str_score;

	t_map	*map;

	int		w_h_for_images_and_x_y_for_window;
	int		moving;
	int		color;
	int		moves;
	int		w;
	int		h;
	int		x_w;
	int		y_w;
	int		x_plr;
	int		y_plr;
	int		mod_x;
	int		mod_y;
}				t_mlx_data;

char	*ft_strdup(char *src);
void	ft_memset(void *buffer, int c, size_t len);
char	*ft_itoa(int n);
char	*ft_strjoin(char *s1, char *s2);
void	set_game(t_mlx_data *game);
void	refresh_str(t_mlx_data *g);
void	map_render(t_mlx_data *g);
void	map_init(t_mlx_data *g, char *map_dest);
t_map	*list_new(char *line);
t_map	*list_last(t_map *map);
int		list_count(t_map *first);
void	check_map(t_map *map);
void	set_direction(int key, t_mlx_data *g);
void	player_moving(t_mlx_data *g);
int		ft_strlen_no_nl(char *s);
int		count_item(char *line, char item);
void	check_extension(char *path);
void	events(t_mlx_data *g);

#endif
