#include <stdio.h>
#include <string.h>

int main()
{
	int N, i, j, count[128], colorcount, max;
	char color[128][16], s[16];

	while (scanf("%d", &N) != EOF && N) {
		max = colorcount = 0;
		memset(count, 0, sizeof(count));
		for (i = 0; i < N; i++)
			color[i][0] = '\0';
		for (j = 0; j < N; j++) {
			scanf("%s", s);
			for (i = 0; i < colorcount; i++)
				if (!strcmp(s, color[i]))
					break;
			if (count[i] == 0) {
				strcpy(color[i], s);
				colorcount++;
			}
			count[i]++;
		}
		for (i = 0; i < N; i++)
			if (count[i] > count[max])
				max = i;
		printf("%s\n", color[max]);
	}
	return 0;
}

