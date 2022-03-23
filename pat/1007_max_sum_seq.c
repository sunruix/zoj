#include <stdio.h>

int main()
{
	int N, i, a[10001], flag = 0;
	int localmax = 0, max = 0;
	int start = 1, end = 1, pos[10001], sum[10001];

	scanf("%d", &N);
	sum[0] = -1;
	for (i = 1; i <= N; i++) {
		scanf("%d", &a[i]);
		if (!flag && a[i] >= 0)
			flag = 1;
		if (sum[i - 1] < 0) {
			pos[i] = i;
			sum[i] = a[i];
		}
		else {
			pos[i] = pos[i - 1];
			sum[i] = sum[i - 1] + a[i];
		}
		if (localmax < sum[i])
			localmax = sum[i];
		if (max < localmax) {
			max = localmax;
			start = pos[i];
			end = i;
		}
	}
	if (flag) {
		if (max)
			printf("%d %d %d\n", max, a[start], a[end]);
		else
			printf("%d %d %d\n", max, 0, 0);
	}
	else
		printf("%d %d %d\n", max, a[1], a[N]);
	return 0;
}
