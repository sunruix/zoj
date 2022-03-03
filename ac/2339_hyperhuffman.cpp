#include <cstdio>
#include <queue>

using namespace std;

struct node {
	long long frq, len;
	friend bool operator <(struct node a, struct node b) {
		return a.frq < b.frq;
	}
	friend bool operator >(struct node a, struct node b) {
		return a.frq > b.frq;
	}
};

void insert(struct node x, node *heap, int *size)
{
	int i, j;

	for (i = ++*size; i > 1 && x < heap[j = i >> 1]; i = j)
		heap[i] = heap[j];
	heap[i] = x;
}

struct node deletemin(node *heap, int *size)
{
	int i, j;
	struct node min = heap[1], last = heap[(*size)--];

	for (i = 1; (j = i << 1) <= *size && last > heap[j += (heap[j] > heap[j + (j < *size)])]; heap[i] = heap[j], i = j);
	heap[i] = last;
	return min;
}

int main ()
{
	int t, n, i, size;
	node a[500005], n1, n2;

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (size = i = 0; i < n; i++) {
			scanf("%lld", &n1.frq), n1.len = 0;
			insert(n1, a, &size);
		}
		while (size > 1) {
			n1 = deletemin(a, &size);
			n2 = deletemin(a, &size);
			n1.len = n1.len + n1.frq + n2.len + n2.frq;
			n1.frq += n2.frq;
			insert(n1, a, &size);
		}
		printf("%lld\n%s", a[1].len, t ? "\n" : "");
	}
	return 0;
}