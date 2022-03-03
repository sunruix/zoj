#include <stdio.h>

char tian[10][8] = {"Ren", "Gui", "Jia", "Yi", "Bing", "Ding", "Wu", "Ji", "Geng", "Xin"};
char di[12][8] = {"chen", "si", "wu", "wei", "shen", "you", "xu", "hai", "zi", "chou", "yin", "mao"};
int main()
{
	int t, a, b;

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &a);
		if (a < 0)
			a++;
		if (a >= 2012) {
			b = a - 2012;
			printf("%s%s\n", tian[b % 10], di[b % 12]);
		}
		else {
			b = 2012 - a;
			printf("%s%s\n", tian[(10 - b % 10) % 10], di[(12 - b % 12) % 12]);
		}
	}
	
	return 0;
}