#include <stdio.h>
#include <string.h>

int main()
{
	int n, i, count, rec[32];
	char v1, v2;

	count = 1;
	while (scanf("%d\n", &n) != EOF && n) {
		memset(rec, 0, sizeof(rec)), rec[0] = 1;
		while (n--) {
			scanf("%c = %c\n", &v1, &v2);
			rec[v1 - 'a'] = rec[v2 - 'a'];
		}
		printf("Program #%d\n", count++);
		for (i = 0; i < 32 && rec[i] == 0; i++);
		if (i == 32)
			printf("none\n\n");
		else {
			for (; i < 32; i++)
				if (rec[i])
					printf("%c ", 'a' + i);
			printf("\n\n");
		}
	}
	return 0;
}