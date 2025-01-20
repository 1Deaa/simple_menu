
#include "main_menu.h"

void	menu_img_init(t_menu *menu)
{
	int	width;
	int	height;

	menu->img.img_start = mlx_xpm_file_to_image(menu->mlx, "xpm/Render01.xpm", &width, &height);
	menu->img.img_exit = mlx_xpm_file_to_image(menu->mlx, "xpm/Render02.xpm", &width, &height);
}

int	close_simple_menu(t_menu *menu)
{
	if (menu->img.img_start)
		mlx_destroy_image(menu->mlx, menu->img.img_start);
	if (menu->img.img_exit)
		mlx_destroy_image(menu->mlx, menu->img.img_exit);
	if (menu->win)
		mlx_destroy_window(menu->mlx, menu->win);
	if (menu->mlx)
		mlx_destroy_display(menu->mlx);
	if (menu->mlx)
	{
		free(menu->mlx);
		menu->mlx = NULL;
	}
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_hook(int keycode, t_menu *menu)
{
	static int current_state = 1;
	if (keycode == XK_Escape)
	{
		close_simple_menu(menu);
	}
	if ((keycode == XK_Up || keycode == XK_Down) && current_state == 1)
	{
		mlx_put_image_to_window(menu->mlx, menu->win, menu->img.img_exit, 0, 0);
		current_state = 2;
	}
	else if ((keycode == XK_Up || keycode == XK_Down) && current_state == 2)
	{
		mlx_put_image_to_window(menu->mlx, menu->win, menu->img.img_start, 0, 0);
		current_state = 1;
	}
	if (keycode == XK_Return && current_state == 1)
	{
		return (0);
	}
	if (keycode == XK_Return && current_state == 2)
		close_simple_menu(menu);
	return (0);
}

void	start_simple_menu(char *menu_name)
{
	t_menu	menu;

	menu.mlx = mlx_init();
	menu.win = mlx_new_window(menu.mlx, 800, 600, menu_name);
	menu_img_init(&menu);
	mlx_put_image_to_window(menu.mlx, menu.win, menu.img.img_start, 0, 0);
	mlx_hook(menu.win, ClientMessage, StructureNotifyMask, close_simple_menu, &menu);
	mlx_hook(menu.win, KeyPress, KeyPressMask, key_hook, &menu);
	mlx_loop(menu.mlx);
}

int	main(void)
{
	start_simple_menu("Main Menu");
	return (0);
}