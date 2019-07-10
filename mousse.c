/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 20:38:49 by yelazrak          #+#    #+#             */
/*   Updated: 2019/07/10 17:00:31 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_change(t_init *init)
{
		mlx_clear_window(init->ptr,init->win);
    	ft_bzero(init->str_img,4*HEIGHT*WIDTH);	
     	main_4(init);
    	mlx_put_image_to_window(init->ptr, init->win, init->img, 0,0);
}

double ft_zoom(double a, double b, double k)
{
    return (a + ((b - a) * k));
}

void ft_displyzoom(t_init *init,  double zoom)
{
     
     init->Re.min = ft_zoom(init->mouseRe, init->Re.min, zoom);
     init->Im.min = ft_zoom(init->mouseIm, init->Im.min, zoom);
     init->Re.max = ft_zoom(init->mouseRe, init->Re.max, zoom);
     init->Im.max = ft_zoom(init->mouseIm, init->Im.max, zoom);
	
	
}

int	mouse_press(int button,int x, int y, t_init *init)
{
	init->mouseRe = x / (WIDTH/ (init->Re.max - init->Re.min)) + init->Re.min;
    init->mouseIm = y / (HEIGHT / (init->Im.max -init->Im.min)) +init->Im.min;
	if (button == 5)
	{	
		init->max += 1;
		ft_displyzoom(init, 0.9);
		ft_change(init);
		return 0;
 	}
	if (button == 4)
	{	if(init->max > 30)
			init->max -= 1;
		ft_displyzoom(init, 1/0.9);
		ft_change(init);
		return 0;
	}

	return 0;
}

int	ft_move(int x, int y, t_init *init)
{
	if (init->stop == 0)
		return 0;
	init->c_i = y / (HEIGHT / (init->Im.max -init->Im.min)) +init->Im.min;
	init->c_r =  x / (WIDTH/ (init->Re.max - init->Re.min)) + init->Re.min;
	ft_change(init);
printf("(%f,%f)\n",init->c_r,init->c_i);

	return 0;
}
int   ft_info_key_1(int s,t_init *lst)
{   
	if (s == 125)
	{  lst->Im.min -= 0.09;
		lst->Im.max -= 0.09;
	}
	else if (s == 126)
	{ lst->Im.max += 0.09;
	 lst->Im.min += 0.09;
	}
	else if (s == 34)
	  lst->stop = 2;	 
	else if (s == 35)
	  lst->stop = 0;
	  else
	  {
		  return (0);
	  }
	  return (1);
}

int   ft_info_key_2(int s,t_init *lst)
{	  
	if (s == 123)
	{  lst->Re.max += 0.09;
		lst->Re.min += 0.09;
	}
	else if (s == 12)
	lst->q +=2;

	else if (s == 124)
	{  lst->Re.min -= 0.09;
		lst->Re.max -= 0.09;
	}			     
	else 
		return(0);
	return (1);
}

int  ft_key(int key,t_init *init)
{
		if(key == 53)
		{
			mlx_destroy_window(init->ptr,init->win);
			mlx_destroy_image(init->ptr,init->img);
			free(init);
				exit(1);
		}
			
		if ( ft_info_key_1(key,init) || ft_info_key_2(key,init))
				ft_change(init);
		
		
		return 0;
}