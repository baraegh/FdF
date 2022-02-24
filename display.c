
#include "header.h"

int get_diplay(t_data *data)
{
    data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (0);
	data->win_ptr = mlx_new_window(data->mlx_ptr, W_WIDTH, W_HEIGHT, "");
	if (!data->win_ptr)
	{
		free(data->mlx_ptr);
		return (0);
	}
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, W_WIDTH, W_HEIGHT);
	if (!data->img.mlx_img)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->mlx_ptr);
		return (0);
	}
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
		&data->img.line_len, &data->img.endian);
    return (1);
}

int	display(t_data data)
{
	if (!get_diplay(&data))
	{
		// mlx_destroy_image(data.mlx_ptr, &data.img);
		// mlx_destroy_window(data.mlx_ptr, data.win_ptr);
		// free(data.mlx_ptr);
        return (0);
	}
	render(&data);
	// mlx_loop_hook(data.mlx_ptr, &render, &data);
	// mlx_hook(data.win_ptr, EVENT_KEY_PRESS, KeyPressMask, &handle_keypress, &data);
	// mlx_hook(data.win_ptr, EVENT_KEY_PRESS, KEY_PRESS_MASK, &handle_tr_move, &data);
	// mlx_mouse_hook(data.win_ptr, &handle_mouse, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, &data.img);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	/* we will exit the loop if there's no window left, and execute this code */
	// mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (1);
}