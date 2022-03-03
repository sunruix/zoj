#include <stdio.h>

int dis(int *a, int *b)
{
	int i, j, res;

	for (res = i = 0; i < 5; i++)
		for (j = i + 1; j < 5; j++)
			if ((a[i] - a[j]) * (b[i] - b[j]) < 0)
				res++;
	return res;
}

int main()
{
	int n, i, j, k, ans, I[8], m[128][8], a[128][8], pos;
	char s[8], c;

	for (s[5] = 0, k = I[0] = 0; I[0] < 5; I[0]++) {
		for (I[1] = 0; I[1] < 5; I[1]++) {
			if (I[1] == I[0]) continue;
			for (I[2] = 0; I[2] < 5; I[2]++) {
				if (I[2] == I[1] || I[2] == I[0]) continue;
				for (I[3] = 0; I[3] < 5; I[3]++) {
					if (I[3] == I[2] || I[3] == I[1] || I[3] == I[0]) continue;
					for (I[4] = 0; I[4] < 5; I[4]++)
						if (I[4] != I[0] && I[4] != I[1] && I[4] != I[2] && I[4] != I[3]) {
							for (i = 0; i < 5; i++)
								m[k][i] = I[i];
							k++;
						}
				}
			}
		}
	}
	while (scanf("%d\n", &n) != EOF && n) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < 5; j++)
				c = getchar(), a[i][c - 'A'] = j;
			getchar();
		}
		for (ans = 0x7fffffff, i = 0; i < 120; i++) {
			for (k = j = 0; j < n; j++)
				k += dis(m[i], a[j]);
			if (k < ans)
				ans = k, pos = i;
		}
		for (i = 0; i < 5; i++)
			s[m[pos][i]] = 'A' + i;
		printf("%s is the median ranking with value %d.\n", s, ans);
	}
	return 0;
}
