#include <stdio.h>

int main()
{
	int T, p, pa, pb;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &p, &pa, &pb);
		if (p - pa < p - pb)
			printf("A\n");
		else
			printf("B\n");
	}
	return 0;
}
