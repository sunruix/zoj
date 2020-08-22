#include <stdio.h>

int main()
{
	int n, b, z;
	scanf("%d", &n);
	while (n--) {
		scanf("%d %d", &b, &z);
		if (b >= z)
			printf("MMM BRAINS\n");
		else
			printf("NO BRAINS\n");
	}
	return 0;
}
