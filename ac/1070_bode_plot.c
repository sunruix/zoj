#include <stdio.h>
#include <math.h>

int main()
{
	int n;
	double VS, VR, R, C, ome, thi;

	scanf("%lf %lf %lf %d", &VS, &R, &C, &n);
	while (n--) {
		scanf("%lf", &ome), thi = atan(1.0 / (R * C * ome));
		VR = VS * R * C * ome * sin(ome) / (ome * sin(ome + thi) - cos(ome + thi));
		printf("%.3f\n", VR);
	}
	return 0;
}
