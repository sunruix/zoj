#include <stdio.h>

int main()
{
	int I, N, i, j, a[128], b[128], stack, queue;

	scanf("%d", &I);
	while (I--) {
		scanf("%d", &N);
		stack = queue = 0;
		for (i = 0; i < N; i++)
			scanf("%d", &a[i]);
		for (i = 0; i < N; i++)
			scanf("%d", &b[i]);
		for (i = 0; i < N && a[i] == b[i]; i++);
		if (i == N)
			queue = 1;
		for (i = 0, j = N - 1; i < N && a[i] == b[j]; i++, j--);
		if (i == N)
			stack = 1;
		if (queue && stack)
			printf("both\n");
		else if (queue && !stack)
			printf("queue\n");
		else if (!queue && stack)
			printf("stack\n");
		else
			printf("neither\n");
	}
	return 0;
}
