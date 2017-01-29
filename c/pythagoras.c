#include <stdio.h>
#include <math.h>
#include <sys/timeb.h>

void main(void)
{
  struct timeb start, stop;
  double       elapsed;

  int i;

  ftime(&start);
  for(i=0; i < 1000000000; i++)
  {
    double y1 = 58.7545;
    double x1 = 17.0118;
    double y2 = 58.9960;
    double x2 = 16.2067;

    double x = pow((x2 - x1), 2);
    double y = pow(((y2 -y1) * cos(y1)), 2);

    double dist = ((2 * M_PI * 3961.3) / 360) * sqrt(x + y);
  }
  ftime(&stop);

  elapsed = ((double) stop.time + ((double) stop.millitm * 0.001)) -
            ((double) start.time + ((double) start.millitm * 0.001));

  printf("%f \n", elapsed);
}
