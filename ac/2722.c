#include <stdio.h>

int main()
{
	int n, i, r;
	while (scanf("%d", &n) != EOF && n) {
		for (i = 0, r = 0; n != 1; i++, n /= 2)
			if (!r)
				r = n % 2;
		if (r)
			i++;
		printf("%d\n", i);
	}
	return 0;
}
