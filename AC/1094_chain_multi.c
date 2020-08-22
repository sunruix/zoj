#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int a, b;
} node;
typedef struct {
	int top;
	node array[256];
} stackrecord;
typedef stackrecord *stack;

void push(node x, stack s, int *ans, int *err)
{
	if (x.a < 0 || !s->top || s->array[s->top].a < 0) {
		s->array[++s->top].a = x.a;
		s->array[s->top].b = x.b;
		return;
	}
	if (s->array[s->top].b != x.a) {
		*err = 1;
		return;
	}
	*ans += s->array[s->top].a * x.a * x.b;
	s->array[s->top].b = x.b;
}

node pop(stack s)
{
	return s->array[s->top--];
}

int main()
{
	int N, i, j, ans, a, b, err;
	char t[256], c;
	node n, map[26], temp[256];
	stack s;

	s = malloc(sizeof(stackrecord));
	scanf("%d\n", &N);
	while (N--) {
		scanf("%c %d %d\n", &c, &a, &b);
		map[c - 'A'].a = a, map[c - 'A'].b = b;
	}
	while (scanf("%s", t) != EOF) {
		ans = err = s->top = 0;
		for (j = 0; t[j] != '\0'; j++) {
			if (t[j] == '(') {
				n.a = -1;
				push(n, s, &ans, &err);
			}
			else if (t[j] == ')') {
				for (i = 0; s->top && s->array[s->top].a > 0; i++)
					temp[i] = pop(s);
				pop(s);
				while (i--)
					push(temp[i], s, &ans, &err);
			}
			else
				push(map[t[j] - 'A'], s, &ans, &err);
		}
		if (err)
			printf("error\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}

