#include <stdio.h>

int main()
{
	int max, W, WW, H, HH, w, h;

	freopen("input1", "r", stdin);
	while (scanf("%d", &max) != EOF && max) {
		WW = W = HH = H = 0;
		while (scanf("%d %d", &w, &h) != EOF && (w != -1 || h != -1)) {
			if (W + w > max) {
				W = w;
				if (W > WW)
					WW = W;
				H = h;
				HH += H;
			}
			else {
				W += w;
				if (W > WW)
					WW = W;
				if (h > H) {
					HH += h - H;
					H = h;
				}
			}
		}
		printf("%d x %d\n", WW, HH);
	}
	return 0;
}
