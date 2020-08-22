#include <stdio.h>
#include <string.h>

int link(int a[], int pos)
{
	int i, head;

	if (!a[pos - 1])
		head = pos, a[pos] = -1;
	else if (a[pos - 1] > 0)
		head = a[pos - 1], a[head]--, a[pos] = head;
	else
		head = pos - 1, a[head]--, a[pos] = head;
	for (a[head] += a[pos + 1], i = pos + 1; a[i]; i++)
		a[i] = head;
	return -1 * a[head];
}

void delink(int a[], int pos)
{
	int i, head1, head2, n;

	if (!a[pos + 1]) {
		if (a[pos] > 0)
			a[a[pos]] -= -1;
		a[pos] = 0;
		return;
	}
	head1 = a[pos] > 0 ? a[pos] : pos;
	head2 = pos + 1;
	n = -a[head1];
	a[head1] = -1 * (head2 - head1 - 1);
	a[head2] = -1 * (n + a[head1] - 1);
	for (i = head2 + 1; a[i]; i++)
		a[i] = head2;
	a[pos] = 0;
}
	
int main()
{
	int t, n, a[5000], i, j, k, pos, ans;

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		ans = 0, memset(a, 0, sizeof(a));
		for (i = 0; i < n; i++) {
			scanf("%d", &pos);
			if (!a[pos]) {
				if((k = link(a, pos)) > ans)
				ans = k;
			}
			else
				delink(a, pos);
		}
		printf("%d\n", ans);
	}
	return 0;
}