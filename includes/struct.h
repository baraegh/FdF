

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	int		width;
	int		heigth;
	char	***z_matrix;
	int		zoom;
	// int		color;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_data;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
} t_point;

typedef struct s_var
{
	int dx;
	int dy;
	int step_x;
	int step_y;
} t_var;


typedef struct s_rect
{
	t_point	p;
	int		width;
	int		height;
	int		color;
} t_rect;

typedef struct s_triangle
{
	t_point	p0;
	t_point	p1;
	t_point	p2;
	int		height;
	int		color;
} t_triangle;


# endif