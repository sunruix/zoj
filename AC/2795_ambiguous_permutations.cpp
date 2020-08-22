#include <stdio.h>
#include <stdlib.h>

int a[100001], b[100001];

int main()
{
	int n, i;
	
	while (scanf("%d", &n) != EOF && n) {
		for (i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			b[a[i]] = i;
		}
		for (i = 1; i <= n && a[i] == b[i]; i++);
		if (i > n)
			printf("ambiguous\n");
		else
			printf("not ambiguous\n");
	}
	return 0;
}