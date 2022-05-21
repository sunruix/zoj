#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *left;
	struct node *right;
	int key;
};
typedef struct node *Tree;

typedef struct {
	Tree array[32];
	int head, tail;
	int capa, size;
} queue;

int N;
int post[32], in[32], result[32];
queue q;

void enqueue(Tree x)
{
	q.array[q.tail++] = x;
	q.tail %= q.capa;
	q.size++;
}
Tree dequeue()
{
	Tree t;
	t = q.array[q.head++];
	q.head %= q.capa;
	q.size--;
	return t;
}

Tree build(int pl, int pr, int il, int ir)
{
	Tree T;
	int root, lnum, rnum, i;
	int p1l, p1r, p2l, p2r, i1l, i1r, i2l, i2r;
	if (pr < pl || ir < il)
		return NULL;
	p1l = pl; p2r = pr - 1;
	i1l = il; i2r = ir;
	root = post[pr];
	T = malloc(sizeof(struct node));
	T->key = root;
	for (i = il, lnum = 0; i <= ir && in[i] != root; i++, lnum++);
	i1r = i - 1; i2l = i + 1;
	p1r = p1l + lnum - 1; p2l = p1r + 1;
	T->left = build(p1l, p1r, i1l, i1r);
	T->right = build(p2l, p2r, i2l, i2r);
	return T;
}

int main()
{
	int i, j, k;
	Tree T, t;
	//freopen("input1", "r", stdin);
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &post[i]);
	for (i = 0; i < N; i++)
		scanf("%d", &in[i]);
	q.head = q.tail = q.size = 0;
	q.capa = N;
	T = build(0, N - 1, 0, N - 1);
	if (T)
		enqueue(T);
	k = 1;
	while (q.size > 0) {
		t = dequeue(q);
		if (k++ < N)
			printf("%d ", t->key);
		else
			printf("%d\n", t->key);
		if (t->left)
			enqueue(t->left);
		if (t->right)
			enqueue(t->right);
	}
	return 0;
}
