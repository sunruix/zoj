#include <stdio.h>

#define isleap(y) ((!((y) % 4) && ((y) % 100)) || !((y) % 400))

int main()
{
	int n, i, j, k, l;
	int mon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	char week[8][16] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

	while (scanf("%d", &n) != EOF && n > 0) {
		for (i = 2000, j = n + 1, k = isleap(i) ? 366 : 365; j > k; j -= k, i++, k = isleap(i) ? 366 : 365);
		for (mon[1] = isleap(i) ? 29 : 28, l = 0; j > mon[l]; j -= mon[l], l++);
		printf("%d-%02d-%02d %s\n", i, l + 1, j, week[n % 7]);
	}
	return 0;
}