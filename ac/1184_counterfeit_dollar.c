#include <stdio.h>
#include <string.h>

int main()
{
	int t, i, j, k, l, r;
	char left[8], right[8], res[8], ans[16], chan[16];

	scanf("%d", &t);
	while (t--) {
		memset(ans, 0, sizeof(ans));
		for (i = 0; i < 3; i++) {
			scanf("%s %s %s", left, right, res);
			memset(chan, 0, sizeof(chan));
			if (!strcmp(res, "even"))
				for (j = strlen(left) - 1; j >= 0; j--) {
					l = left[j] - 'A', r = right[j] - 'A';
					ans[l] = ans[r] = 1;
				}
			else if (!strcmp(res, "up")) {
				for (j = strlen(left) - 1; j >= 0; j--) {
					l = left[j] - 'A', r = right[j] - 'A', chan[l] = chan[r] = 1;
					ans[l] = (ans[l] && ans[l] != 3) ? 1 : 3;
					ans[r] = (ans[r] && ans[r] != 2) ? 1 : 2;
				}
				for (j = 0; j < 12; j++)
					ans[j] = chan[j] ? ans[j] : 1;
			}
			else {
				for (j = strlen(left) - 1; j >= 0; j--) {
					l = left[j] - 'A', r = right[j] - 'A', chan[l] = chan[r] = 1;
					ans[l] = (ans[l] && ans[l] != 2) ? 1 : 2;
					ans[r] = (ans[r] && ans[r] != 3) ? 1 : 3;
				}
				for (j = 0; j < 12; j++)
					ans[j] = chan[j] ? ans[j] : 1;
			}
		}
		for (i = 0; i < 12  && ans[i] == 1; i++);
		printf("%c is the counterfeit coin and it is ", i + 'A');
		ans[i] == 2 ? printf("light.\n") : printf("heavy.\n");
	}
	return 0;
}