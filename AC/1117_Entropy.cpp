#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

using namespace std;

struct node {
	int weight, height;
	node *left, *right;
};

struct cmp {
	bool operator() (node *a, node *b) {
		return a->weight > b->weight;
	}
};

void height(node *n, int h)
{
	n->height = h;
	if (n->left)
		height(n->left, h + 1);
	if (n->right)
		height(n->right, h + 1);
}

node N[27], *n1, *n2, *n3;

int main()
{
	int i, ascii, Huffman;
	char s[32768];
	priority_queue <node *, vector <node *>, cmp> q;

	while (scanf("%s", s) != EOF && strcmp(s, "END")) {
		memset(N, 0, sizeof(N));
		for (i = 0; s[i] != '\0'; i++)
			s[i] == '_' ? N[26].weight++ : N[s[i] - 'A'].weight++;
		ascii = 8 * i;
		for (i = 0; i < 27; i++)
			if (N[i].weight)
				q.push(&(N[i]));
		while (q.size() > 1) {
			n1 = q.top(), q.pop();
			n2 = q.top(), q.pop();
			n3 = (node *)malloc(sizeof(node));
			n3->weight = n1->weight + n2->weight;
			n3->left = n1, n3->right = n2;
			q.push(n3);
		}
		height(q.top(), 1), q.pop();
		for (i = Huffman = 0; i < 27; i++)
			Huffman += N[i].height > 1 ? N[i].weight * (N[i].height - 1) : N[i].weight * N[i].height;
		printf("%d %d %.1f\n", ascii, Huffman, (double)ascii / Huffman);
	}
	return 0;
}