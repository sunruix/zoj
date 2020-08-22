#include <stdio.h>

typedef struct {
	int x, y;
} node;

int main()
{
	int n, i, j, ans;
	char s[128];
	node worm[20], temp;

	while (scanf("%d\n", &n) != EOF && n) {
		for (i = 0; i < 20; i++)
			worm[i].x = 30 - i, worm[i].y = 25;
		scanf("%s", s);
		for (i = 0, ans = 0; i < n && !ans; i++) {
			temp.x = worm[0].x, temp.y = worm[0].y;
			switch (s[i]) {
				case 'N':
					temp.y--;
					break;
				case 'S':
					temp.y++;
					break;
				case 'W':
					temp.x--;
					break;
				case 'E':
					temp.x++;
			}
			if (!temp.x || !temp.y || temp.x > 50 || temp.y > 50)
				ans = 2;
			for (j = 19; j > 0 && !ans; j--) {
				worm[j].x = worm[j - 1].x, worm[j].y = worm[j - 1].y;
				if (worm[j].x == temp.x && worm[j].y == temp.y)
					ans = 1;
			}
			worm[0].x = temp.x, worm[0].y = temp.y;
		}
		switch (ans) {
			case 1:
				printf("The worm ran into itself on move %d.\n", i);
				break;
			case 2:
				printf("The worm ran off the board on move %d.\n", i);
				break;
			default:
				printf("The worm successfully made all %d moves.\n", n);
		}
	}
	return 0;
}