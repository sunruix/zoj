#include <stdio.h>

int main()
{
	int i, h, u, d, f, k;

	while (scanf("%d %d %d %d", &h, &u, &d, &f) != EOF && h) {
		f *= u, h *= 100, u *= 100, d *= 100;
		for (k = 0, i = 1; ; i++, u = u >= f ? u - f : 0)
			if ((k += u) > h) {
				printf("success");
				break;
			}
			else if ((k -= d) < 0) {
				printf("failure");
				break;
			}
		printf(" on day %d\n", i);
	}
	return 0;
}