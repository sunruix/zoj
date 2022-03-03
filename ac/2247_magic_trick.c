#include <stdio.h>

typedef struct {
	int suit, face;
} card;

int comp(card a, card b)
{
	if (a.suit != b.suit)
		return a.suit < b.suit;
	return a.face < b.face;
}

int main()
{
	int t, i, j, k, pos;
	char suit, face, *s1 = "HCDS", *s2 = "123456789TJQK";
	card a[8], ans;

	scanf("%d\n", &t);
	while (t--) {
		for (i = 0; i < 4; i++) {
			scanf("%c%c ", &face, &suit);
			for (j = 0; s1[j] != suit && s1[j] != '\0'; j++);
			for (k = 0; s2[k] != face && s2[k] != '\0'; k++);
			a[i].suit = j, a[i].face = k;
		}
		ans.suit = a[0].suit;
		i = comp(a[1], a[2]), j = comp(a[2], a[3]), k = comp(a[1], a[3]);
		if (i && j && k)
			pos = 1;
		else if (i && !j && k)
			pos = 2;
		else if (!i && j && k)
			pos = 3;
		else if (i && !j && !k)
			pos = 4;
		else if (!i && j && !k)
			pos = 5;
		else
			pos = 6;
		ans.face = (pos + a[0].face) % 13;
		printf("%c%c\n", s2[ans.face], s1[ans.suit]);
	}
	return 0;
}