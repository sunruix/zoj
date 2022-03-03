#include <stdio.h>
#include <string.h>

int main()
{
	int k, m, num[9999], total, need, i, j, temp, flag;

	while (scanf("%d", &k) != EOF && k) {
		scanf("%d", &m);
		flag = 1;
		memset(num, 0, sizeof(num));
		for (i = 0; i < k; i++) {
			scanf("%d", &j);
			num[j] = 1;
		}
		for (i = 0; i < m; i++) {
			scanf("%d %d", &total, &need);
			for (j = 0; j < total; j++) {
				scanf("%d", &temp);
				if (num[temp])
					need--;
			}
			if (need > 0)
				flag = 0;
		}
		if (flag)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
