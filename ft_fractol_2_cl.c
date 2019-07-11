/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol_2_cl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:26:27 by yelazrak          #+#    #+#             */
/*   Updated: 2019/07/11 17:00:35 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_platform(t_cl *cl)
{
	if (clGetPlatformIDs(1, &cl->platform_id,
				&cl->num_of_platform) != CL_SUCCESS)
	{
		ft_putendl("error of platform");
		return (1);
	}
	if (clGetDeviceIDs(cl->platform_id, CL_DEVICE_TYPE_GPU, 1,
				&cl->device_id, &cl->num_of_device) != CL_SUCCESS)
	{
		ft_putendl("error device");
		return (1);
	}
	return (0);
}

void	ft_msg_error(void)
{
	ft_putendl("usage:");
	ft_putendl("                  mandlebrot");
	ft_putendl("                  julia");
	ft_putendl("                  burning_ship");
}
