#include <stdio.h>

typedef struct {
	int l, w;
} rect;

int equal(rect r1, rect r2)
{
	if ((r1.l == r2.l && r1.w == r2.w) ||
			(r1.l == r2.w && r1.w == r2.l))
		return 1;
	return 0;
}

int iszero(rect r)
{
	if (!r.l)
		return 1;
	return 0;
}

int main()
{
	int i, j, count, res;
	rect box[6];

	while (scanf("%d %d", &box[0].l, &box[0].w) != EOF) {
		res = 0;
		for (i = 1; i < 6; i++)
			scanf("%d %d", &box[i].l, &box[i].w);
		for (i = 0, count = 0; i < 6; i++) {
			if (iszero(box[i]))
				continue;
			box[count].l = box[i].l, box[count].w = box[i].w;
			count++;
			for (j = i + 1; j < 6; j++)
				if (equal(box[i], box[j])) {
					box[j].l = 0;
					break;
				}
		}
		if (count == 3) {
			if (box[0].l == box[1].l) {
				box[3].l = box[0].w, box[3].w = box[1].w;
				res = equal(box[2], box[3]);
			}
			if (!res && box[0].l == box[1].w) {
				box[3].l = box[0].w, box[3].w = box[1].l;
				res = equal(box[2], box[3]);
			}
			if (!res && box[0].w == box[1].l) {
				box[3].l = box[0].l, box[3].w = box[1].w;
				res = equal(box[2], box[3]);
			}
			if (!res && box[0].w == box[1].w) {
				box[3].l = box[0].l, box[3].w = box[1].l;
				res = equal(box[2], box[3]);
			}
		}
		if (res)
			printf("POSSIBLE\n");
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}
