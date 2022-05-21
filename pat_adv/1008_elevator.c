#include <stdio.h>

int main()
{
	int N, i, sum, pre = 0, cur;

	scanf("%d", &N);
	sum = 5 * N;
	for (i = 0; i < N; i++) {
		scanf("%d", &cur); 
		if (cur > pre)
			sum += 6 * (cur - pre);
		else if (cur < pre)
			sum += 4 * (pre - cur);
		pre = cur;
	}
	printf("%d\n", sum);
	return 0;
}
