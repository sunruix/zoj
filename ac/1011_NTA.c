#include <stdio.h>
#include <string.h>

struct {
	int trans[256][2];
	int trans_num;
} table[16][16];
int tree[2048];
int n, m, k, level;

int work(int node, int sig)
{
	int ele, signal0, signal1, i;
	int valid0, valid1;
	ele = tree[node];
	for (i = 0; i < table[sig][ele].trans_num; i++) {
		signal0 = table[sig][ele].trans[i][0];
		signal1 = table[sig][ele].trans[i][1];
		if (tree[2 * node + 1] == -1) {
			if (signal0 >=  n - m && signal1 >= n - m)
				return 1;
		}
		else {
			valid0 = work(2 * node + 1, signal0);
			valid1 = work(2 * node + 2, signal1);
			if (valid0 && valid1)
				return 1;
		}
	}
	return 0;
}

int main()
{
	int i, j, ii, start, end, count = 0;
	char c;

	while (scanf("%d %d %d", &n, &m, &k) != EOF &&
			n != 0 && m != 0 && k != 0) {
		if (count)
			printf("\n");
		printf("NTA%d:\n", ++count);
		for (i = 0; i < n; i++) {
			j = 0; ii = 0;
			while (1) {
				scanf("%d %d", &table[i][j].trans[ii][0], &table[i][j].trans[ii][1]);
				if ((c = getchar()) == '\n') {
					table[i][j].trans_num = ii + 1;
					ii = 0; j++;
				}
				else
					ii++;
				if (j == k)
					break;
			}
		}
		while (scanf("%d\n", &level) != EOF && level >= 0) {
			memset(tree, -1, sizeof(tree));
			start = 1, end = 0;
			for (i = 0; i <= level; i++) {
				for (j = start - 1; j <= end; j++) {
					scanf("%c ", &c);
					if (c >= 'a' && c <= 'z')
						tree[j] = c - 'a';
				}
				start *= 2, end = 2 * (start - 1);
			}
			if (work(0, 0))
				printf("Valid\n");
			else
				printf("Invalid\n");
		}
	}
	return 0;
}
