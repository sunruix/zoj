#include <stdio.h>

int main()
{
	int n, i;
	double ans[100001];
	const double one = 1.0, two = 2.0;

	for (i = 2, ans[1] = 0.5; i <= 100000; i++)
		ans[i] = ans[i - 1] + one / (double)i / two;
	printf("# Cards  Overhang\n");
	while (scanf("%d", &n) != EOF) {
		printf("%5d%10.3f\n", n, ans[n]);
	}
	return 0;
}