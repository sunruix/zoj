#include <stdio.h>
#include <string.h>

int main()
{
	int t, E, F, n, ni, pi, wi, i, j, p[10000], w[10000], m[10000];

	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &E, &F, &ni), F -= E, n = 0;
		memset(m, 0, sizeof(m));
		while (ni--) {
			scanf("%d %d", &pi, &wi), i = F / wi;
			for (j = 1; i > j - 1; j <<= 1);
			for (j >>= 2; j < i && j; j >>= 1)
				w[n] = wi * j, p[n] = j * pi, n++, i -= j;
			i ? (w[n] = wi * i, p[n] = i * pi, n++) : 0;
		}
		for (i = 0; i < n; i++)
			for (j = F; j >= w[i]; j--)
				if (j == w[i] || m[j - w[i]])
					if (!m[j] || (m[j] && p[i] + m[j - w[i]] < m[j]))
						m[j] = p[i] + m[j - w[i]];

		m[F] ? printf("The minimum amount of money in the piggy-bank is %d.\n", m[F]) :
			printf("This is impossible.\n");
	}
	return 0;
}