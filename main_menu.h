#ifndef MAIN_MENU_H
# define MAIN_MENU_H

#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdlib.h>

typedef struct s_render
{
	void	*img_start;
	void	*img_exit;
}	t_render;

typedef struct s_menu
{
	void	*mlx;
	void	*win;
	int		selected_option;
	t_render img;
}	t_menu;



#endif