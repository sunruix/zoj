#include <stdio.h>
#include <string.h>

int main()
{
	int T, res;
	char y1[8], y2[8], m1[8], m2[8], d1[8], d2[8], a1[32], a2[32];
	scanf("%d", &T);
	while (T--) {
		scanf("%s %s %s", y1, m1, d1);
		scanf("%s %s %s", y2, m2, d2);
		sprintf(a1, "%s %s %s", y1, m1, d1);
		sprintf(a2, "%s %s %s", y2, m2, d2);
		res = strcmp(a1, a2);
		if (res < 0)
			printf("javaman\n");
		else if (res > 0)
			printf("cpcs\n");
		else
			printf("same\n");
	}
	return 0;
}
