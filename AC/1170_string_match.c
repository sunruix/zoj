#include <stdio.h>
#include <string.h>

int gcd(int m, int n)
{
	int p;
	while (p = m % n) {
		m = n;
		n = p;
	}
	return n;
}

int main()
{
	int l1, l2, max, m, i, j, k, g;
	char s[256], t[256];

	while (scanf("%s %s", s, t) != EOF && strcmp(s, "-1")) {
		l1 = strlen(s), l2 = strlen(t);
		for (i = 0, max = 0; i < l1; i++) {
			for (j = i, k = 0, m = 0; j < l1 && k < l2; j++, k++)
				if (s[j] == t[k])
					m++;
			if (max < m)
				max = m;
		}
		for (i = 0; i < l2; i++) {
			for (j = i, k = 0, m = 0; j < l2 && k < l1; j++, k++)
				if (t[j] == s[k])
					m++;
			if (max < m)
				max = m;
		}
		max *= 2;
		if (max == l1 + l2 || max == 0)
			printf("appx(%s,%s) = %d\n", s, t, max / (l1 + l2));
		else {
			g = gcd(l1 + l2, max);
			printf("appx(%s,%s) = %d/%d\n", s, t, max / g, (l1 + l2) / g);
		}
	}
	return 0;
}
