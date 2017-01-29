#include <stdio.h>
#include <math.h>
#include <sys/timeb.h>

#define R 6371.8
#define TO_RAD(val) (val * (M_PI / 180))

void main(void)
{
  struct timeb start, stop;
  double       elapsed;

  int i;

  ftime(&start);
  for(i=0; i < 1000000000; i++)
  {
    double lat1 = 58.7530;
    double lon1 = 17.0115;
    double lat2 = 58.7515;
    double lon2 = 16.9857;

    double d_lat = TO_RAD(lat2 - lat1);
    double d_lon = TO_RAD(lon2 - lon1);
    lat1 = TO_RAD(lat1);
    lat2 = TO_RAD(lat2);

    double a = pow(sin(d_lat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(d_lon / 2), 2);
    double c = 2 * asin(sqrt(a));

    double result = R * c;
  }
  ftime(&stop);

  elapsed = ((double) stop.time + ((double) stop.millitm * 0.001)) -
            ((double) start.time + ((double) start.millitm * 0.001));

  printf("%f \n", elapsed);
}
