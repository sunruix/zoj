#include <stdio.h>

int main()
{
	int a, b, c, d, A, B, C, D, n;

	for (a = 6; a <= 200; a++) {
		A = a * a * a;
		for (b = 2; b < a; b++) {
			B = b * b * b;
			for (c = b; c < a; c++) {
				C = c * c * c;
				for (d = c; d < a; d++) {
					D = d * d * d;
					if (A == B + C + D)
						printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
				}
			}
		}
	}
	return 0;
}