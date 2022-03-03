#include <stdio.h>

void p_(int s)
{
	putchar(' ');
	while (s--)
		putchar('-');
	putchar(' ');
}

void ph(int n, int s)
{
	int i;
	if (n == 1 || n == 4)
		for (i = 0; i < s + 2; i++)
			putchar(' ');
	else
		p_(s);
}
void pm(int n, int s)
{
	int i;
	if (n == 1 || n == 7 || n == 0)
		for (i = 0; i < s + 2; i++)
			putchar(' ');
	else
		p_(s);
}
void pl(int n, int s)
{
	int i;
	if (n == 1 || n == 4 || n == 7)
		for (i = 0; i < s + 2; i++)
			putchar(' ');
	else
		p_(s);
}
void pu(int n, int s)
{
	int i;
	if (n == 1 || n == 2 || n == 3 || n == 7) {
		for (i = 0; i < s + 1; i++)
			putchar(' ');
		putchar('|');
	}
	else if (n == 5 || n == 6) {
		putchar('|');
		for (i = 0; i < s + 1; i++)
			putchar(' ');
	}
	else {
		putchar('|');
		while (s--)
			putchar(' ');
		putchar('|');
	}
}
void pd(int n, int s)
{
	int i;
	if (n == 2) {
		putchar('|');
		for (i = 0; i < s + 1; i++)
			putchar(' ');
	}
	else if (n == 6 || n == 8 || n == 0) {
		putchar('|');
		while (s--)
			putchar(' ');
		putchar('|');
	}
	else {
		for (i = 0; i < s + 1; i++)
			putchar(' ');
		putchar('|');
	}
}
int main()
{
	int s, i, j, k, l;
	char t[16];
	while (scanf("%d %s", &s, t) != EOF && (s || t[0] != '0')) {
		for (i = 0; t[i] != '\0'; i++) {
			if (i)
				putchar(' ');
			ph(t[i] - '0', s);
		}
		putchar('\n');
		for (i = 0; i < s; i++) {
			for (j = 0; t[j] != '\0'; j++) {
				if (j)
					putchar(' ');
				pu(t[j] - '0', s);
			}
			putchar('\n');
		}
		for (i = 0; t[i] != '\0'; i++) {
			if (i)
				putchar(' ');
			pm(t[i] - '0', s);
		}
		putchar('\n');
		for (i = 0; i < s; i++) {
			for (j = 0; t[j] != '\0'; j++) {
				if (j)
					putchar(' ');
				pd(t[j] - '0', s);
			}
			putchar('\n');
		}
		for (i = 0; t[i] != '\0'; i++) {
			if (i)
				putchar(' ');
			pl(t[i] - '0', s);
		}
		printf("\n\n");
	}
	return 0;
}

