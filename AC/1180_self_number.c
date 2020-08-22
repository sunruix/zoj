#include <stdio.h>

char map[1024 * 1024];

int main()
{
	int i, n, m;
	for (i = 1; i <= 1000 * 1000; i++) {
		n = m = i;
		while (m) {
			n += m % 10;
			m /= 10;
		}
		map[n] = 1;
		if (!map[i])
			printf("%d\n", i);
	}
	return 0;
}
