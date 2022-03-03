#include <stdio.h>
#include <string.h>

int main()
{
	int n, i, time, times, max_solve, min_score, this_solve, this_score;
	char name[1024], ans[1024];

	while (scanf("%d", &n) != EOF) {
		max_solve = 0, min_score = 0x7fffffff;
		while (n--) {
			scanf("%s", name), this_solve = this_score = 0;
			for (i = 0; i < 4; i++) {
				scanf("%d %d", &times, &time);
				if (time)
					this_solve++, this_score += time + (times - 1) * 20;
			}
			if (this_solve > max_solve || (this_solve == max_solve && this_score < min_score))
				max_solve = this_solve, min_score = this_score, strcpy(ans, name);
		}
		printf("%s %d %d\n", ans, max_solve, min_score);
	}
	return 0;
}
