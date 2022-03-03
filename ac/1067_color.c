#include <stdio.h>

typedef struct {
	int R;
	int G;
	int B;
} color;

int dist(color c1, color c2)
{
	int d1, d2, d3;
	d1 = c1.R - c2.R;
	d2 = c1.G - c2.G;
	d3 = c1.B - c2.B;
	return d1 * d1 + d2 * d2 + d3 *d3;
}

int main()
{
	int n, i, d, min;
	const int D = 3 * 256 * 256;
	color c, p, array[16];

	for (i = 0; i < 16; i++)
		scanf("%d %d %d", &array[i].R, &array[i].G, &array[i].B);
	while (scanf("%d %d %d", &c.R, &c.G, &c.B) && c.R != -1) {
		min = D;
		for (i = 0; i < 16; i++) {
			d = dist(c, array[i]);
			if (min > d) {
				min = d;
				p = array[i];
			}
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n", c.R, c.G, c.B, p.R, p.G, p.B);
	}
	return 0;
}
