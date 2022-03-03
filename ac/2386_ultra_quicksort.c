#include <stdio.h>

int b[512 * 1024];
long long invert;

void merge(int a[], int i1, int i2, int j1, int j2)
{
	int i = i1, j = j1, k;
	k = i;
	while (i <= i2 && j <= j2) {
		if (a[i] <= a[j])
			b[k++] = a[i++];
		else {
			b[k++] = a[j++];
			invert += (i2 - i + 1);
		}
	}
	while (i <= i2)
		b[k++] = a[i++];
	while (j <= j2)
		b[k++] = a[j++];
	for (i = i1; i <= j2; i++)
		a[i] = b[i];
}

void mergesort(int a[], int left, int right)
{
	int i, j, mid;
	if (left >= right)
		return;
	mid = (left + right) / 2;
	mergesort(a, left, mid);
	mergesort(a, mid + 1, right);
	merge(a, left, mid, mid + 1, right);
}

int main()
{
	int n, i, j, a[512 * 1024];

	while (scanf("%d", &n) != EOF && n) {
		invert = 0;
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		mergesort(a, 0, n - 1);
		printf("%Ld\n", invert);
	}
	return 0;
}
