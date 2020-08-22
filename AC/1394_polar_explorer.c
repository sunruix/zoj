#include <stdio.h>
#include <string.h>

int main()
{
	int x, y, z, ans, get;
	double a, pi = 3.14159;
	char s[16];

	while (scanf("%s", &s) != EOF && strcmp(s, "ENDOFINPUT")) {
		get = 0, scanf("%d %d %d", &x, &y, &z);
		z > 180 ? (z = 360 - z) : 0;
		a = pi * x * z / 90;
		a - 5.0 * y < 1e-8 ? (get = 1, ans = (int)(y - a / 5.0)) : (ans = 5 * y);
		printf("%s %d\n", get ? "YES" : "NO", ans);
		scanf("%s", s);
	}
	return 0;
}