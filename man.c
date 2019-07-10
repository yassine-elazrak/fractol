/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 15:45:01 by yelazrak          #+#    #+#             */
/*   Updated: 2019/07/10 17:03:27 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <fcntl.h>



 char *ft_tab_2(char *name)
{
  char *line;
  int fd;
   char *str;
   char *tmp;
   
   
   str = ft_strnew(0);
  

  if ((0 > (fd = open(name,O_RDONLY))))
    return (NULL);
  
 
  while (get_next_line(fd,&line))
  {
    tmp = str;
    str = ft_strjoin(str,line);
    free(tmp);
  }
  close (fd);
  return (str);
}


static int	ft_rgb(unsigned char r,unsigned char g,unsigned char b)
{
	unsigned char color[4];

	color[0] = b;
	color[1] = g;
	color[2] = r;
	color[3] = 0;

	return (*(int *)color);
}

void    ft_01(t_cl *cl,t_init *init)
{
      cl->num_of_device = 0;
    cl->num_of_platform = 0;
    if (!(cl->buffer =  (int *)malloc(sizeof(int)* 3)))
      return ;
cl->buffer[0] = WIDTH;
cl->buffer[1] = HEIGHT;
cl->buffer[2] = init->max;
}

void    ft_imag_of_win(t_init *init,t_cl *cl)
{
  int i = 0;
     int x = 0;
     int y = 0;
     cl_uint a = 0;
     while (i < (WIDTH * HEIGHT))
     {
        a = cl->ptr[i];
        x = i % WIDTH;
        y = i / WIDTH; 
       if ( a < init->max)
        init->str_img[x + y * WIDTH] = ft_rgb(255,255,255) * ((2 + cos(4*(3.14)*a*init->q) ) / 2 ); //ft_rgb(a,a*10%256,a*4%256);
      else
      {
        //ft_putnbr(cl->tab_2[i]);ft_putchar('\n');
       init->str_img[x + y * WIDTH] =ft_rgb(0,0,0);// a + 1 - log(log((cl->tab_2[i])));
      }
       i++;
     }
}
int ft_platform_of_cl(t_cl *cl,t_init *init)
{
  if (clGetPlatformIDs(1,&cl->platform_id,&cl->num_of_platform) != CL_SUCCESS)
    {
      ft_putendl("error of platform");
      return (1);
    }
    if (clGetDeviceIDs(cl->platform_id,CL_DEVICE_TYPE_GPU,1,&cl->device_id,&cl->num_of_device)!= CL_SUCCESS)
    {
      ft_putendl("error device");
      return (1);
    }
     int i = 0;
    const char *t = (const char *)ft_tab_2("tst");

    cl->context = clCreateContext(NULL,1,&cl->device_id,NULL,NULL,&i);
    cl->queue = clCreateCommandQueue(cl->context,cl->device_id,0,&i);
     cl->input = clCreateBuffer(cl->context, CL_MEM_READ_ONLY,sizeof(int) *  3, NULL, NULL);//CL_FALSE
     clEnqueueWriteBuffer( cl->queue, cl->input, CL_TRUE ,  0,  sizeof(int)*  3, cl->buffer,  0,  NULL,  NULL);
    cl->program = clCreateProgramWithSource(cl->context,1,&t,NULL,&i);
    if (clBuildProgram(cl->program,1,&cl->device_id,NULL,NULL,NULL) != CL_SUCCESS)
    {
      ft_putendl("error of COMPIL");
      return (1);
    }
    ft_putendl(init->name_of_fractol);
    cl->kernel = clCreateKernel( cl->program, init->name_of_fractol, NULL );
     cl->output = clCreateBuffer(cl->context, CL_MEM_WRITE_ONLY,sizeof( double) * (WIDTH * HEIGHT), NULL, NULL);
     // cl->tab = clCreateBuffer(cl->context, CL_MEM_WRITE_ONLY,sizeof( double) * (WIDTH * HEIGHT), NULL, NULL);
return (0);
}

void    ft_set_arg_of_kernel(t_cl *cl,t_init *init)
{
    clSetKernelArg(cl->kernel, 0, sizeof(cl->output), (void*) &cl->output);
      clSetKernelArg(cl->kernel, 1, sizeof(cl->input), (void*) &cl->input);
       clSetKernelArg(cl->kernel, 2, sizeof( double),  &init->Re.min);
        clSetKernelArg(cl->kernel, 3, sizeof( double),  &init->Re.max);
         clSetKernelArg(cl->kernel, 4, sizeof( double),  &init->Im.min);
          clSetKernelArg(cl->kernel, 5, sizeof( double),  &init->Im.max);
           //clSetKernelArg(cl->kernel, 6, sizeof( cl->tab),  &cl->tab);
         if (ft_strcmp(init->name_of_fractol,"julia") == 0)
          {
             clSetKernelArg(cl->kernel, 6, sizeof( double),  &init->c_r);
             clSetKernelArg(cl->kernel, 7, sizeof( double),  &init->c_i);
          }
 }

int main_4(t_init *init)
{
    t_cl *cl;
    size_t global_work_size;
     if (!(cl =  (t_cl *)malloc(sizeof(t_cl))))
      return (0);  
    global_work_size = WIDTH * HEIGHT ;   
    ft_01(cl,init);
    ft_platform_of_cl(cl,init);   
    ft_set_arg_of_kernel(cl,init);
    clEnqueueNDRangeKernel( cl->queue,cl->kernel,1, NULL,
     &global_work_size,NULL, 0, NULL, NULL);
    clFinish( cl->queue );
    cl->ptr = (cl_uint *) clEnqueueMapBuffer( cl->queue,cl->output,  CL_TRUE, CL_MAP_READ,
     0, (WIDTH * HEIGHT) * sizeof(cl_uint), 0, NULL, NULL, NULL );
   // cl->tab_2 = (cl_double *) clEnqueueMapBuffer( cl->queue,cl->tab,  CL_TRUE, CL_MAP_READ,
    // 0, (WIDTH * HEIGHT) * sizeof(cl_int), 0, NULL, NULL, NULL ); 
    ft_imag_of_win(init,cl);
    clReleaseContext(cl->context);
    clReleaseCommandQueue(cl->queue);
    clReleaseMemObject(cl->output);
      return 0;

}

void	ft_00(t_init *init)
{
	init->z = 1;
	init->Re.max = 2;
	init->Re.min = -2;
	init->Im.max = 2;
	init->Im.min = -2;
	init->max = 30;
	init->a = 0;
	init->b = 0;
	init->c_r = 0;
	init->c_i = 0;
	init->mouseIm =0;
	init->mouseRe = 0;
  init->arg = 0;
  init->stop = 2;
  init->q = 11;

}

int      ft_get_name_of_fractal(char *name,int argc,t_init *init)
{
  if (ft_strcmp(name,"mandlebrot") == 0 && argc == 2)
      init->name_of_fractol = ft_strdup("mandlebrot");
  else if (ft_strcmp(name,"julia") == 0 && argc == 2)
      init->name_of_fractol = ft_strdup("julia");
  else if (ft_strcmp(name,"burning_ship") == 0  && argc == 2)
    init->name_of_fractol = ft_strdup("burning_ship");
  else
  {
    ft_putendl("usage:");
    ft_putendl("                  mandlebrot");
    ft_putendl("                  julia");
    ft_putendl("                  burning_ship");
       	return (0);
  }
	return (1);
  
}

int main(int argc ,char **argv)
{

	int s_l;
	int bpp;
	int end;
	t_init *init;

	
	if (!(init = (t_init *)malloc(sizeof(t_init))))
		exit(0);
	ft_00(init);
  if ((ft_get_name_of_fractal(argv[1],argc,init) == 0))
     	return (0);

	init->ptr = mlx_init();
	init->win = mlx_new_window(init->ptr,WIDTH,HEIGHT,"fractol");
	init->img = mlx_new_image(init->ptr,WIDTH,HEIGHT);
	init->str_img = (int*)mlx_get_data_addr(init->img,&bpp,&s_l,&end);
	main_4(init);
	mlx_put_image_to_window(init->ptr, init->win, init->img, 0, 0);
	mlx_hook(init->win,2,0,ft_key,init);
  mlx_hook(init->win,6,0,ft_move,init);
	 mlx_mouse_hook(init->win, mouse_press, init);
	mlx_loop(init->ptr);
	return (0);
}