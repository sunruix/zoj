#include <stdio.h>

int main()
{
	int n, i, pre, cur, count;
	while (scanf("%d", &n) != EOF) {
		scanf("%d", &pre);
		for (i = 1, count = 1; i < n; i++) {
			scanf("%d", &cur);
			if (cur == pre)
				count++;
			else
				count--;
			if (count < 0) {
				count = 1;
				pre = cur;
			}
		}
		printf("%d\n", pre);
	}
	return 0;
}
