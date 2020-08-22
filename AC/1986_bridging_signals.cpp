#include <stdio.h>

int main()
{
	int t, n, a, m[40000], end, l, r, mid;

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		scanf("%d", &m[0]);
		end = 0;
		while (--n) {
			scanf("%d", &a);
			if (a > m[end])
				m[++end] = a;
			else if (a < m[0])
				m[0] = a;
			else {
				l = 0, r = end;
				while (l < r) {
					mid = (l + r) / 2;
					if (m[mid] < a) {
						if (m[mid + 1] > a) {
							m[mid + 1] = a;
							break;
						}
						else
							l = mid + 1;
					}
					else {
						if (m[mid - 1] < a) {
							m[mid] = a;
							break;
						}
						else
							r = mid - 1;
					}
				}
			}
		}
		printf("%d\n", end + 1);
	}
	return 0;
}