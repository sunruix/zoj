#include <stdio.h>

int check (int n, int m)
{
	int i, ans;
	ans = m % 2 ? 2 : 1;
	for (i = 3; i <= n; i++) {
		ans = (ans + m) % i;
		if (!ans)
			ans = i;
	}
	return ans == 1;
}

int main()
{
	int n, i, k;
	
	while (scanf("%d", &n) != EOF && n) {
		for (i = 2; !check(n - 1, i); i++);
		printf("%d\n", i);
	}
	return 0;
}