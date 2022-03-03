#include <stdio.h>

int main()
{
	int a, b, c, d, h1, m1, h2, m2, ph, pm, ans;

	printf("Program 3 by team X\n");
	printf("Initial time  Final time  Passes\n");
	while (scanf("%d %d %d %d", &a, &b, &c, &d) != EOF) {
		h1 = a, m1 = b, h2 = c, m2 = d;
		h1 = (h1 == 12 ? 0 : h1) * 5 + m1 / 12;
		h2 = (h2 == 12 ? 0 : h2) * 5 + m2 / 12;
		ans = pm = ph = 0;
		if (h1 == m1)
			ans = 1;
		while (h1 != h2 || m1 != m2) {
			if (m1 == h1 && pm < ph)
				ans++;
			pm = m1, ph = h1;
			if (++m1 % 12 == 0)
				h1++;
			if (m1 == 60)
				m1 = 0;
			if (h1 == 60)
				h1 = 0;
		}
		printf("       %02d:%02d       %02d:%02d      %2d\n", a, b, c, d, ans);
	}
	printf("End of program 3 by team X\n");
	return 0;
}
