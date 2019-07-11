__kernel void mandlebrot(   global uint *dst, global int *src,
const  double r_min,const  double r_max,const  double i_min,
const double i_max)               
  {                                                      
      uint i;
      uint px;
      uint py;
      double tmp;
       double x;
      double y;
     double x0 = 0.0f;
      double y0 = 0.0f;
     
     
      
      uint a = 0;
      
      i = get_global_id(0);
      px = i % src[0] ;
      py = i /src[0] ;  
       if (px >= src[0] || py >= src[1] )
        return ;
      x = 0;
      y = 0;
      x0 = (px * (r_max - r_min))/src[0]  +r_min;
      y0 = (py * (i_max - i_min))/src[1] + i_min;
      while ( a < src[2]  && ((x * x + y * y)  <= 4) )
      {
        tmp = x * x - y * y + x0;
        y = (2 * y * x) + y0;
        x = tmp;
        a++;
      } 
      dst[i] = a;
          
                   
  } 

  __kernel void julia(   global uint *dst, global int *src,const  double r_min,
  const  double r_max,const  double i_min,const double i_max,
  const  double mossex,const double mossey)               
  {                                                      
      uint i;
      uint px;
      uint py;
      double tmp;
       double x;
      double y;
     double x0 = 0.0f;
      double y0 = 0.0f;
     
     
      
      uint a = 0;
      
      i = get_global_id(0);
      px = i % src[0] ;
      py = i /src[0] ;  
       if (px >= src[0] || py >= src[1] )
        return ;
      x0 = mossex;
      y0 = mossey;
      x = (px * (r_max - r_min))/src[0]  +r_min;
      y = (py * (i_max - i_min))/src[1] + i_min;
      while ( a < src[2]  && ((x * x + y * y)  <= 4) )
      {
        tmp = x * x - y * y + x0;
        y = 2 * y * x + y0;
        x = tmp;
        a++;
      } 
    
     
      dst[i] = a;
          
                   
  }

  __kernel void burning_ship(   global uint *dst, global int *src,
  const  double r_min,const  double r_max,
  const  double i_min,const double i_max)               
  {                                                      
      uint i;
      uint px;
      uint py;
      double tmp;
       double x;
      double y;
     double x0 = 0.0f;
      double y0 = 0.0f;
     
     
      
      uint a = 0;
      
      i = get_global_id(0);
      px = i % src[0] ;
      py = i /src[0] ;  
       if (px >= src[0] || py >= src[1] )
        return ;
      x = 0;
      y = 0;
      x0 = (px * (r_max - r_min))/src[0]  +r_min;
      y0 = (py * (i_max - i_min))/src[1] + i_min;
      while ( a < src[2]  && ((x * x + y * y)  <= 4) )
      {
        tmp = x * x - y * y + x0;
        y = fabs(2 * y * x) + y0;
        x = tmp;
        a++;
      } 
      dst[i] = a;
          
                   
  }
  