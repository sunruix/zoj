#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int arrive;
	int h, m, s;
	int process;
} record;
record line[131072];
int window[128], win_size;

int comp(const void *a, const void *b)
{
	return (*(record *)a).arrive > (*(record *)b).arrive ? 1 : -1;
}
int delete()
{
	int i, j, x, last;
	x = window[1];
	last = window[win_size--];
	for (i = 1; 2 * i <= win_size; i = j) {
		j = 2 * i;
		if ((j != win_size) && (window[j + 1] < window[j]))
			j++;
		if (last > window[j])
			window[i] = window[j];
		else
			break;
	}
	window[i] = last;
	return x;
}

void insert(int x)
{
	int i, j;
	for (i = ++win_size; i >= 1; i = j) {
		j = i / 2;
		if (x < window[j])
			window[i] = window[j];
		else
			break;
	}
	window[i] = x;
}

int main()
{
	int N, K, i, j, t;
	int wait_time = 0, head = 0, win[128], temp;

	scanf("%d %d", &N, &K);
	for (i = 0; i < N; i++) {
		scanf("%d:%d:%d %d", &line[i].h, &line[i].m, 
				&line[i].s, &line[i].process);
		if (line[i].process > 60)
			line[i].process = 60;
		line[i].process *= 60;
		line[i].arrive = 3600 * line[i].h + 60 * line[i].m + line[i].s;
		if (line[i].arrive > 61200)
			i--, N--;
	}
	memset(window, 0, sizeof(window));
	qsort(line, N, sizeof(record), comp);
	for (t = 28800; t <= 61200; t++) {
		for (i = head; i < N; i++) {
			if (t < line[i].arrive)
				break;
			for (j = 1; j <= K; j++) {
				if (window[j] != 0)
					continue;
				window[j] = line[i].process;
				wait_time += (t - line[i].arrive);
				head++;
				break;
			}
			if (j > K)
				break;
		}
		for (j = 1; j <= K; j++) {
			if (window[j] > 0)
				window[j]--;
		}
	}
	for (i = 1; i <= K; i++)
		win[i] = window[i];
	win_size = 0;
	for (i = 1; i <= K; i++)
		insert(win[i]);
	while (head < N) {
		while (head < N) {
			if (win_size < K) {
				insert(line[head].process);
				wait_time += (t - line[head].arrive);
				head++;
			}
			if (win_size == K)
				break;
		}
		temp = delete();
		for (i = 1; i <= win_size; i++)
			window[i] -= temp;
		t += temp;
	}
	printf("%.1f\n", ((float)wait_time / 60) / N);
	return 0;
}
