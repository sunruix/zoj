#include <stdio.h>

#define pi 3.1415927
#define fpm 5280
#define ipf 12

int main()
{
	float diameter, time;
	float distance, mph;
	int revolutions, count = 0;

	while(1)
	{
		count++;
		scanf("%f %d %f", &diameter, &revolutions, &time);
		if (!revolutions)
			break;
		distance = diameter * pi * revolutions / (ipf * fpm);
		mph = distance * 60 * 60 / time;
		printf("Trip #%d: %.2f %.2f\n", count, distance, mph);
	}
	return 0;
}
