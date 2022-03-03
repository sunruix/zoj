#include <stdio.h>

int main()
{
	int s, m, i, j, k;
	while (scanf("%d %d", &s, &m) != EOF) {
		i = s > m ? s : m;
		j = s < m ? s : m;
		while (k = i % j)
			i = j, j = k;
		printf("%10d%10d    ", s, m);
		if (j == 1)
			printf("Good Choice\n\n");
		else
			printf("Bad Choice\n\n");
	}
	return 0;
}
