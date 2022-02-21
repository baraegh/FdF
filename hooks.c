

#include "header.h"

int	handle_no_event(void *data)
{
    (void)  data;
	/* This function needs to exist, but it is useless for the moment */
	return (0);
}

int	handle_input(int keysym, t_data *data)
{
	if (keysym == KEY_ESC)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

int	handle_mouse(int x, int y, void *data)
{
	(void)	data;
	(void)	x;
	(void)	y;
	
	return (0);
}