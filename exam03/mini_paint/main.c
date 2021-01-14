#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>

typedef struct		s_struct
{
	int	x;
	int	y;
	char	c;
	char	c_fill;
	float	s_x;
	float	s_y;
	float	rad;
	char	new_c;
	char	**arr;
	char 	n;
}			t_struct;

int		ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (1);
}

int		free_arr(char **arr, int i)
{
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
	return (1);
}

int		make_arr(t_struct *w)
{
	int i;
	int size;
	int j;

	j = 0;
	if (w->x > 300 || w->y > 300 || w->x < 1 || w->y < 1)
		return (1);
	i = 0;
	w->arr = malloc(sizeof(char *) * (w->y + 1));
	if (w->arr == NULL)
		return (1);
	w->arr[w->y] = 0;
	while (i < w->y)
	{
		w->arr[i] = malloc(w->x + 1);
			if (w->arr[i] == NULL)
				return (free_arr(w->arr, i));
		while (j < w->x)
		{
			w->arr[i][j] = w->c;
			j++;
		}
		w->arr[i][j] = 0;
		j = 0;
		i++;
	}
	return (0);
}

void		mini_paint(t_struct *w)
{
	float i;
	float j;

	i = 0.0;
	while (i <= w->rad)
	{
		j = sqrtf(powf(w->rad, 2) - powf(i, 2));
		if (!(w->s_y + j < 0 || w->s_y + j >= w->y || w->s_x + i >= w->x || w->s_x + i < 0))
			w->arr[(int)(w->s_y + j)][(int)(w->s_x + i)] = w->new_c;
		if (!(w->s_y + j < 0 || w->s_y + j >= w->y || w->s_x - i >= w->x || w->s_x - i < 0))
			w->arr[(int)(w->s_y + j)][(int)(w->s_x - i)] = w->new_c;
		if (!(w->s_y - j < 0 || w->s_y - j >= w->y || w->s_x + i >= w->x || w->s_x + i < 0))
			w->arr[(int)(w->s_y - j)][(int)(w->s_x + i)] = w->new_c;
		if (!(w->s_y - j < 0 || w->s_y - j >= w->y || w->s_x - i >= w->x || w->s_x - i < 0))
			w->arr[(int)(w->s_y - j)][(int)(w->s_x - i)] = w->new_c;
		i = i + 0.01;
	}
}

void		mini_paint_full(t_struct *w)
{
	float i;
	float j;
	float i1;

	i1 = 0.0;
	i = 0.0;
	while (i <= w->rad)
	{
		j = sqrtf(powf(w->rad, 2) - powf(i, 2));
		while (i1 <= i)
		{
			if (!(w->s_y + j <= 0 || w->s_y + j >= w->y || w->s_x + i1 >= w->x || w->s_x + i1 <= 0))
				w->arr[(int)(w->s_y + j)][(int)(w->s_x + i1)] = w->new_c;
			if (!(w->s_y + j <= 0 || w->s_y + j >= w->y || w->s_x - i1 >= w->x || w->s_x - i1 <= 0))
				w->arr[(int)(w->s_y + j)][(int)(w->s_x - i1)] = w->new_c;
			if (!(w->s_y - j <= 0 || w->s_y - j >= w->y || w->s_x + i1 >= w->x || w->s_x + i1 <= 0))
				w->arr[(int)(w->s_y - j)][(int)(w->s_x + i1)] = w->new_c;
			if (!(w->s_y - j <= 0 || w->s_y - j >= w->y || w->s_x - i1 >= w->x || w->s_x - i1 <= 0))
				w->arr[(int)(w->s_y - j)][(int)(w->s_x - i1)] = w->new_c;
			i1 = i1 + 1;
		}
		i1 = 0;
		i = i + 0.01;
	}
}		

void		write_arr(t_struct *w)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (w->arr[i])
	{
		while (w->arr[i][j])
		{
			write(1, &w->arr[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
		j = 0;
	}
}

int		main(int argc, char **argv)
{
	FILE *fd;
	int ret;
	t_struct w;
	int i;

	ret = 0;
	if (argc != 2)
		return (ft_putstr("Error: argument\n"));
	fd = fopen(argv[1], "r");
	ret = fscanf(fd, "%i%i%c%c%c", &w.x, &w.y, &w.c, &w.c, &w.n);
	if (ret == -1)
		return (1);
	if (make_arr(&w))
		return (1);
	while (fscanf(fd, "%c%f%f%f%c%c%c", &w.c_fill, &w.s_x, &w.s_y, &w.rad, &w.new_c, &w.new_c, &w.n) != -1)
	{
		if (w.c_fill == 'c')
			mini_paint(&w);		
		if (w.c_fill == 'C')
			mini_paint_full(&w);
	}
	write_arr(&w);
	fclose(fd);
	return (0);
}			
			
