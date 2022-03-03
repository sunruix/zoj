#include <stdio.h>
#include <string.h>

int convert(char *bin, int left, int right)
{
	int i, res = 0;
	for (i = left; i <= right; i++) {
		res *= 2;
		res += bin[i] - '0';
	}
	return res;
}

int main()
{
	int N, i, j, k, dec[4];
	char bin[64];

	freopen("input", "r", stdin);
	scanf("%d", &N);
	while (N--) {
		scanf("%s", bin);
		j = strlen(bin) % 8;
		if (!j)
			j = 8;
		dec[0] = convert(bin, 0, j - 1);
		dec[1] = convert(bin, j, j + 7);
		dec[2] = convert(bin, j + 8, j + 15);
		dec[3] = convert(bin, j + 16, j + 23);
		for (i = 0; i < 3; i++)
			printf("%d.", dec[i]);
		printf("%d\n", dec[i]);
	}
	return 0;
}

