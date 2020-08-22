#include <stdio.h>

int main()
{
	int A, B, n, i, j, f[1024], m[1024][2], pos0, pos1, find;
	while (scanf("%d %d %d", &A, &B, &n) != EOF && A && B && n) {
		f[1] = f[2] = m[2][0] = m[2][1] = 1;
		for (i = 3, find = 0; i <= n && !find; i++) {
			f[i] = (A * f[i - 1] + B * f[i - 2]) % 7;
			m[i][0] = f[i - 1], m[i][1] = f[i];
			for (j = 2; j < i; j++)
				if (m[j][0] == m[i][0] && m[j][1] == m[i][1]) {
					pos0 = j, pos1 = i, find = 1;
					break;
				}
		}
		if (i >= n)
			printf("%d\n", f[n]);
		else
			printf("%d\n", f[pos0 + (n - pos0) % (pos1 - pos0)]);
	}
	return 0;
}

