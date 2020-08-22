#include <stdio.h>

int main()
{
	int t, n, temp, max, min;
	char type[16];
	scanf("%d", &t);
	while (t--) {
		scanf("%s", type);
		scanf("%d", &n);
		max = 0, min = 2048;
		while (n--) {
			scanf("%d", &temp);
			if (temp > max)
				max = temp;
			if (temp < min)
				min = temp;
		}
		if (type[0] == 'F')
			printf("%d\n", min);
		else
			printf("%d\n", max);
	}
	return 0;
}
