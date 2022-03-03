#include <stdio.h>

int main()
{
	int t, i, j, k, ans;
	char s[8];

	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &i, &j), ans = (j - i + 1) * (i + j) >> 1;
		for (scanf("%s", &s), j = 1, i = 5; i >= 0; i--, j *= 10)
			ans -= s[i] == '|' ? 5 * j : 0;
		scanf("%s", &s), scanf("%s", &s), scanf("%s", &s);
		for (k = 1; k <= 4; k++)
			for (scanf("%s", &s), j = 1, i = 5; i >= 0; i--, j *= 10)
				ans -= s[i] == '|' ? k * j : 0;
		printf("%s\n", ans ? "Mistake" : "No mistake");
	}
	return 0;
}