#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
	struct Node *left;
	struct Node *right;
	char s[128], t;
} node;

int comp(char *s, char *t)
{
	int ls, lt;

	ls = strlen(s), lt = strlen(t);
	if (ls != lt)
		return ls - lt;
	return strcmp(s, t);
}

void work(node *x)
{
	x->t = 1;
	if (!x->left && !x->right)
		return;
	if (x->left && !x->left->t)
		work(x->left);
	if (x->right && !x->right->t)
		work(x->right);
	if (!x->left)
		strcat(x->s, x->right->s);
	else if (!x->right)
		strcat(x->s, x->left->s);
	else
		strcat(x->s, comp(x->left->s, x->right->s) > 0 ? x->left->s : x->right->s);
}

int main()
{
	int n, m, i, j, k;
	char c, ans[128];
	node *g[128][128];

	while (scanf("%d %d\n", &m, &n) != EOF && (m || n)) {
		memset(g, 0, sizeof(g));
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++)
				if ((c = getchar()) >= '0' && c <= '9') {
					g[i][j] = (node *)malloc(sizeof(node));
					g[i][j]->t = 0, g[i][j]->s[0] = c, g[i][j]->s[1] = '\0';
					g[i][j]->left = g[i][j]->right = NULL;
				}
			getchar();
		}
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				if (g[i][j]) {
					if (i < n - 1)
						g[i][j]->left = g[i + 1][j];
					if (j < m - 1)
						g[i][j]->right = g[i][j + 1];
				}
		for (ans[0] = '\0', i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				if (g[i][j] && !g[i][j]->t) {
					work(g[i][j]);
					for (k = 0; g[i][j]->s[k] == '0' && g[i][j]->s[k] != '\0'; k++);
					if (comp(g[i][j]->s + k, ans) > 0)
						strcpy(ans, g[i][j]->s + k);
				}
		printf("%s\n", ans);
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				if (g[i][j])
					free(g[i][j]);
	}
	return 0;
}
