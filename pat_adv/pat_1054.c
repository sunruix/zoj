#include <stdio.h>

int main()
{
	int n, m, i, j, ans, count;

	scanf("%d %d", &n, &m);
	for (ans = count = 0, i = n * m; i > 0; i--) {
		scanf("%d", &j);
		if (!count)
			ans = j, count = 1;
		else if (ans == j)
			count++;
		else count--;
	}
	printf("%d\n", ans);
	return 0;
}
			
