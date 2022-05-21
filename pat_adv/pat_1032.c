#include <stdio.h>

int next[100000], visited[100000];

int main()
{
	int a, b, as, bs, n, i, j, ans;
	char c;

	scanf("%d %d %d", &as, &bs, &n);
	ans = 0;
	while (n--) {
		scanf("%d %c %d", &a, &c, &b);
		next[a] = b;
	}
	for (ans = as; ans != -1; ans = next[ans])
		visited[ans] = 1;
	for (ans = bs; ans != -1 && !visited[ans]; ans = next[ans])
		visited[ans] = 1;
	if (ans > 0)
		printf("%.05d", ans);
	else
		printf("-1");
	return 0;
}