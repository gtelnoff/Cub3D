/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:36:10 by gtelnoff          #+#    #+#             */
/*   Updated: 2023/02/01 11:30:38 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include	<unistd.h>
# include	<stdlib.h>
# include	<math.h>

# include	"Utils/gnl/get_next_line.h"
# include	"Utils/ft_printf/ft_printf.h"
# include	"../mlx_linux/mlx.h"
# include	"../mlx_linux/mlx_int.h"

# define TRUE			1
# define FALSE			0
# define SPEED			0.015
# define BUFFER_SIZE 	150
# define WIN_SIZE_X 	1200
# define WIN_SIZE_Y 	600
# define WIDTH_BLOCK	32
# define HEIGHT_BLOCK 	32
# define BLOCK 			32
# define PI 			3.1415
# define FOV			0.6
# define DIST			0.35

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*image;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx;

// 0 -> NO; 1 -> SO; 2 -> WE; 3 -> EA;
typedef struct s_texture
{
	int		width;
	int		heigth;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*addr_texture;
	void	*image;
}	t_texture;

typedef struct s_settings
{
	char		**file;
	char		**map;
	char		*map_name;
	int			*ceiling_color;
	int			*floor_color;
	int			heigth_map;
	int			length_map;
	t_texture	*texture;
}	t_settings;

typedef struct s_player
{
	char	direction;
	double	angle;
	double	pdx;
	double	pdy;
	double	x;
	double	y;
	int		speed;
	int		count;

}	t_player;

typedef struct s_ray_cast
{
	double	rx;
	double	ry;
	double	xo;
	double	yo;

}	t_ray_cast;

typedef struct s_keycode
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left_arrow;
	int	right_arrow;
}	t_keycode;

typedef struct s_all_structs
{
	struct s_ray_cast	cast;
	struct s_keycode	keycode;
	struct s_player		player;
	struct s_settings	settings;
	struct s_mlx		mlx;
}	t_all_structs;

void			free_error(t_settings *settings);
void			my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
unsigned int	my_get_color_pixel(t_settings *settings, int x, int y, int nbr);
void			error_malloc(t_settings *settings);
void			error_empty_file(t_settings *settings, char **file);
void			error_non_existent_file(void);
void			error_map_unknown_params(t_all_structs *all_structs, char c);
void			error_map_empty_line(t_all_structs *all_structs);
void			error_map_not_closed(t_all_structs *all_structs);
void			error_player_not_exist(t_all_structs *all_structs);
void			error_player_already_set(t_all_structs *all_structs);
int				get_file_heigth(t_all_structs *all_structs, char *file_name);
void			print_2d_array(char **array);
int				ft_close(t_all_structs *all_structs);
void			imposible_angle(t_all_structs *all_structs);
char			*ft_strdup(char *source);
int				ft_strncmp(const char *first, \
	const char *second, size_t length);
void			ft_putstr_fd(char *s, int fd);
int				ft_atoi(const char *nptr);
char			*ft_trunc_str(char *str, int start);
char			*ft_strtrim(char *s1, char *set);
char			**ft_split(char *s, char c);
void			*ft_calloc(size_t elementCount, size_t elementSize);
char			*ft_substr(char *s, int start, int len);
int				get_len_2d_array(char **array);
char			**trim_2d_array(char **array, char *set);
void			free_2d_array(char **array);
char			*ft_strtrim_free(char *s1, char *set);
void			free_settings_struct(t_settings *settings);
double			fix_pi(double pi);
void			draw_wall(t_all_structs *all_structs, \
	double height, double end, int nbr);
void			print_north(t_all_structs *all_structs, \
	double end_px, double end_py, double angle);
void			print_est(t_all_structs *all_structs, \
	double end_px, double end_py, double angle);
void			print_south(t_all_structs *all_structs, \
	double end_px, double end_py, double angle);
void			print_west(t_all_structs *all_structs, \
	double end_px, double end_py, double angle);
int				key_hook(t_all_structs *all_structs);
void			make_new_image(t_all_structs *all_structs);
double			fix_pi(double pi);
void			print_ceil_floor(t_all_structs *all_structs);
int				turn_off(t_all_structs *all_structs);

#endif
