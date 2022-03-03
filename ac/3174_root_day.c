#include <stdio.h>

int table[12] = {1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144};
int check(int n)
{
	int i;
	for (i = 0; i < 12; i++)
		if (n == table[i])
			return 1;
	return 0;
}

int main()
{
	int t, i, y1, y2, count;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &y1, &y2);
		for (i = y1, count = 0; i <= y2; i++)
			if (check(i % 1000) || check(i % 100))
				count++;
		printf("%d\n", count);
	}
	return 0;
}
