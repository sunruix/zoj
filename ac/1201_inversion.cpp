#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE node;

struct NODE {
	int item;
	node *next;
};

int main()
{
	int n, i, j, k, a[64], b[64];
	char c;
	node *head, *p, *temp;

	while (scanf("%d\n", &n) != EOF && n) {
		scanf("%c", &c);
		for (i = 1; i <= n; i++)
				scanf("%d", &a[i]);
		head = (node *)malloc(sizeof(node));
		head->item = n, head->next = NULL;
		if (c == 'P') {
			for (i = 1; i <= n; i++) {
				for (j = i - 1, k = 0; j >= 1; j--)
					if (a[j] > a[i])
						k++;
				b[a[i]] = k;
			}
			for (i = 1; i < n; i++)
				printf("%d ", b[i]);
			printf("%d\n", b[i]);
		}
		else {
			for (i = n; i >= 1; i--) {
				p = head, k = a[i];
				while (p->next && k) {
					if (p->item > i)
						k--;
					p = p->next;
				}
				temp = p->next;
				p->next = (node *)malloc(sizeof(node));
				p->next->item = i, p->next->next = temp;
			}
			p = head->next;
			while (p->next) {
				printf("%d ", p->item);
				p = p->next;
			}
			printf("%d\n", p->item);
			while (head->next) {
				temp = head->next;
				head->next = temp->next;
				free(temp);
			}
		}
	}
	return 0;
}
