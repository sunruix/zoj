#include <stdio.h>
#include <stdlib.h>

typedef struct node *link;
typedef link Tree;

struct node {
	int item;
	link left, right;
};

int b[1024], c[1024], p, q;

Tree insert(Tree T, int x)
{
	if (T == NULL) {
		T = (Tree)malloc(sizeof(struct node));
		T->item = x, T->left = T->right = NULL;
	}
	else if (T->item > x)
		T->left = insert(T->left, x);
	else
		T->right = insert(T->right, x);
	return T;
}

void pre1(Tree T)
{
	b[p++] = T->item;
	if (T->left)
		pre1(T->left);
	if (T->right)
		pre1(T->right);
}

void pre2(Tree T)
{
	c[q++] = T->item;
	if (T->right)
		pre2(T->right);
	if (T->left)
		pre2(T->left);
}

void post1(Tree T, Tree root)
{
	if (T->left)
		post1(T->left, root);
	if (T->right)
		post1(T->right, root);
	printf("%d%c", T->item, T == root ? '\n' : ' ');
}

void post2(Tree T, Tree root)
{
	if (T->right)
		post2(T->right, root);
	if (T->left)
		post2(T->left, root);
	printf("%d%c", T->item, T == root ? '\n' : ' ');
}

int main()
{
	int n, a[1024], i;
	Tree T = NULL;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]), T = insert(T, a[i]);
	p = 0, pre1(T), q = 0, pre2(T);
	for (i = 0; i < n && a[i] == b[i]; i++);
	if (i == n)
		printf("YES\n"), post1(T, T);
	else {
		for (i = 0; i < n && a[i] == c[i]; i++);
		if (i == n)
		printf("YES\n"), post2(T, T);
		else
			printf("NO\n");
	}
	return 0;
}


