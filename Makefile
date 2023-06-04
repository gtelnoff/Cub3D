SRCS	= srcs/Error/error_malloc.c srcs/Error/error_map_parsing_one.c srcs/Error/error_parsing.c srcs/Free_functions/free_settings_struct.c srcs/main.c srcs/Mlx_part/Key_interaction/key_hook.c srcs/Mlx_part/Key_interaction/key_init.c srcs/Mlx_part/Key_interaction/key_pressed.c srcs/Mlx_part/Key_interaction/key_release.c srcs/Mlx_part/Ray_casting_algo/hit_horizontal_wall.c srcs/Mlx_part/Ray_casting_algo/hit_vertical_wall.c srcs/Mlx_part/Ray_casting_algo/start_ray_casting.c srcs/Mlx_part/set_mlx.c srcs/Mlx_part/Utils/fix_pi.c srcs/Mlx_part/Utils/my_get_color_pixel.c srcs/Mlx_part/Utils/my_mlx_pixel_put.c srcs/Mlx_part/Utils/set_line.c srcs/Mlx_part/Visual/draw_wall.c srcs/Mlx_part/Visual/make_new_image.c srcs/Mlx_part/Visual/print_ceil_floor.c srcs/parsing.c srcs/Parsing/map_parser.c srcs/Parsing/map_parser_functions/check_all_params.c srcs/Parsing/map_parser_functions/check_empty_line.c srcs/Parsing/map_parser_functions/check_map_closed.c srcs/Parsing/map_parser_functions/equalize_map.c srcs/Parsing/map_parser_functions/set_info_palyer.c srcs/Parsing/settings_parser.c srcs/Parsing/settings_parser_function/check_colors.c srcs/Parsing/settings_parser_function/check_duplicate_params.c srcs/Parsing/settings_parser_function/check_extension.c srcs/Parsing/settings_parser_function/check_have_unknow_params.c srcs/Parsing/settings_parser_function/check_no_empty_params.c srcs/Parsing/settings_parser_function/convert_rgb_to_hex.c srcs/Parsing/settings_parser_function/set_first_params.c srcs/start_game.c srcs/Utils/convert_file_to_2d_array.c srcs/Utils/free_2d_array.c srcs/Utils/free_rx_ry.c srcs/Utils/ft_atoi.c srcs/Utils/ft_calloc.c srcs/Utils/ft_get_len_2d_array.c srcs/Utils/ft_printf/ft_printf.c srcs/Utils/ft_printf/ft_printf_utils.c srcs/Utils/ft_putstr_fd.c srcs/Utils/ft_split.c srcs/Utils/ft_strdup.c srcs/Utils/ft_strncmp.c srcs/Utils/ft_strtrim.c srcs/Utils/ft_substr.c srcs/Utils/ft_trunc_str.c srcs/Utils/gnl/get_next_line.c srcs/Utils/gnl/get_next_line_utils.c srcs/Utils/print_2d_array.c srcs/Utils/set_new_map.c srcs/Utils/trim_2d_array.c 
OBJS	= $(SRCS:.c=.o)
NAME 	= cub3D
MLX		= mlx_linux/libmlx.a
CC		= clang -g -Wall -Werror -Wextra

all : $(NAME)

%.o: %.c
	$(CC) -c $< -o $@

$(NAME) : $(OBJS) $(MLX)
		$(CC) $(OBJS) $(MLX) -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) 
		echo "It's good !"

$(MLX):
	make -sC mlx_linux

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
