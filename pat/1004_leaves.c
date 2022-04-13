#include <stdio.h>
#include <string.h>

typedef struct {
	int parent;
	int level;
	int child[128];
	int chd_num;
} node;
node nodes[128];
int maxlevel = 1;

void count_level(int id)
{
	int i;
	nodes[id].level = nodes[nodes[id].parent].level + 1;
	if (nodes[id].level > maxlevel)
		maxlevel = nodes[id].level;
	for (i = 0; i < nodes[id].chd_num; i++)
		count_level(nodes[id].child[i]);
}

int main()
{
	int N, M, K, ID, id, i, j, count;

	for (i = 0; i < 128; i++) {
		nodes[i].parent = 0;
		nodes[i].level = 0;
		nodes[i].chd_num = 0;
		memset(nodes[i].child, 0, sizeof(nodes[i].child));
	}
	scanf("%d %d", &N, &M);
	for (i = 0; i < M; i++) {
		scanf("%d %d", &ID, &K);
		nodes[ID].chd_num = K;
		for (j = 0; j < K; j++) {
			scanf("%d", &id);
			nodes[ID].child[j] = id;
			nodes[id].parent = ID;
		}
	}
	count_level(1);
	for (i = 1; i <= maxlevel; i++) {
		count = 0;
		for (j = 0; j < 128; j++) {
			if (nodes[j].level == i && !nodes[j].chd_num)
				count++;
		}
		printf("%d", count);
		if (i < maxlevel)
			printf(" ");
	}
	printf("\n");
	return 0;
}
