#include <stdio.h>

int main()
{
	int T, age;
	char *map[12] = {"Dragon", "Rabbit", "Tiger", "Ox", "Rat", "Pig", "Dog",
		"Rooster", "Monkey", "Ram", "Horse", "Snake"};
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &age);
		printf("%s\n", map[age % 12]);
	}
	return 0;
}

