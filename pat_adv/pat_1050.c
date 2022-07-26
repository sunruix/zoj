#include <stdio.h>

char s[100000], t[100000], map[128], *p;

int main() {
	fgets(s, sizeof(s), stdin);
    fgets(t, sizeof(t), stdin);
	for (p = t; *p != '\n'; p++)
		map[*p] = 1;
	for (p = s; *p != '\n'; p++)
		if (!map[*p])
			putchar(*p);
	putchar('\n');
	
	return 0;
}
