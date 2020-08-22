#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct {
	double x, y;
} point;

double dist(point p1, point p2)
{
	return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int main()
{
	int n, i, j, k, lose;
	char s[128], ans[32];
	double x, y, d[128][128], sqrt3;
	point p[128];

	p[0].x = p[0].y = 0.0, sqrt3 = sqrt(3.0);
	while (scanf("%d", &n) != EOF && n) {
		scanf("%s", s);
		for (i = 2; i <= n; i++) {
			x = (1 - i), y = (1 - i) * sqrt3;
			for (j = ((i * (i - 1)) >> 1) + 1; j <= (i * (i + 1)) >> 1; j++)
				p[j - 1].x = x, p[j - 1].y = y, x += 2;
		}
		for (n = (n * (n + 1)) >> 1, i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				d[i][j] = dist(p[i], p[j]);
		memset(ans, 0, sizeof(ans));
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				for (k = 0; k < n; k++)
					if (j != k && fabs(d[i][j] - d[i][k]) < 1e-8 && fabs(d[i][j] - d[j][k]) < 1e-8 &&
						s[j] == s[k] && s[i] == s[j])
						ans[s[j] - 'a'] = 1;
		for (lose = 1, i = 0; i < 26; i++)
			ans[i] ? printf("%c", i + 'a'), lose = 0 : 0;
		if (lose)
			printf("LOOOOOOOOSER!");
		printf("\n");
	}
	return 0;
}