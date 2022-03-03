#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int l, w;
} stick;

int comp(const void *a, const void *b)
{
	stick *pa, *pb;

	pa = (stick *)a, pb = (stick *)b;
	if (pa->l != pb->l)
		return pa->l - pb->l;
	return
		pa->w - pb->w;
}

int main()
{
	int t, n, i, j, ans, pre;
	stick s[5005];

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d %d", &s[i].l, &s[i].w);
		qsort(s, n, sizeof(stick), comp);
		for (i = ans = 0; i < n - 1; i++) {
			if (!s[i].l && ! s[i].w)
				continue;
			pre = i;
			for (j = i + 1; j < n; j++)
				if (s[pre].l <= s[j].l && s[pre].w <= s[j].w)
					s[pre].l = s[pre].w = 0, pre = j;
			s[pre].l = s[pre].w = 0;
			ans++;
		}
		if (s[i].l)
			ans++;
		printf("%d\n", ans);
	}
	return 0;
}