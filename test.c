void	render_julia(t_data *data)
{
	int	j;
	int	i;
	int	jul;

	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			jul = julia(data, (data->hp + i - WIDTH / 2) / data->zoom, (data->vp
						+ j - HEIGHT / 2) / data->zoom);
			my_mlx_pixel_put(data, i, j, get_color(jul, data->color_set));
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
}
