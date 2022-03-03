#include <stdio.h>

int main()
{
	int n, a, b, c, i, aver, temp, bully, victim, m[128];
	char name[128][128];
	freopen("input", "r", stdin);
	while (scanf("%d", &n) != EOF && n != -1) {
		for (i = 0, aver = 0; i < n; i++) {
			scanf("%d %d %d %s", &a, &b, &c, name[i]);
			m[i] = a * b * c;
			aver += m[i];
		}
		aver /= n;
		for (i = 0; i < n; i++) {
			if (m[i] > aver)
				bully = i;
			else if (m[i] < aver)
				victim = i;
		}
		printf("%s took clay from %s.\n", name[bully], name[victim]);
	}
	return 0;
}
