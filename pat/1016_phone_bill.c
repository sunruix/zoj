#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[24];
	char time[16];
	int month, day, hour, minute;
	int status;
} record;

int cmp(const void *a, const void *b)
{
	int result;
	if ((result = strcmp((*((record *)a)).name, (*((record *)b)).name)) != 0)
		return result;
	else
		return strcmp((*((record *)a)).time, (*((record *)b)).time);
}

int main()
{
	int N, i, j, k, price[25], next, money, money_sum, dur, flag;
	char s[16], *t;
	record records[1024], *p1, *p2;

	for (i = 0; i < 24; i++)
		scanf("%d", &price[i]);
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%s", records[i].name);
		scanf("%s", records[i].time);
		sscanf(records[i].time, "%d:%d:%d:%d", 
				&records[i].month, &records[i].day,
				&records[i].hour, &records[i].minute);
		scanf("%s", s);
		if (s[1] == 'n')
			records[i].status = 0;
		else
			records[i].status = 1;
	}
	qsort(records, N, sizeof(record), cmp);
	for (i = 0; i < N; i = j) {
		t = records[i].name;
		next = 0; p2 = p1 = NULL;
		money_sum = 0; flag = 0;
		for (j = i; j < N; j++) {
			if (strcmp(t, records[j].name))
				break;
			if (next == 0 && records[j].status != 0)
				continue;
			if (next == 1 && records[j].status != 1) {
				p1 = &records[j];
				continue;
			}
			if (p1 == NULL) {
				p1 = &records[j];
				next = 1;
			}
			else {
				if (!flag) {
					printf("%s %02d\n", p1->name, p1->month);
					flag = 1;
				}
				p2 = &records[j];
				if (p2->day > p1->day || p2->hour > p1->hour) {
					dur = (60- p1->minute);
					money = (60 - p1->minute) * price[p1->hour];
				}
				else {
					dur = 0 - p1->minute;
					money = (0 - p1->minute) * price[p1->hour];
				}
				dur += p2->minute;
				money += (p2->minute) * price[p2->hour];
				for (k = p1->hour + 1; k < (p2->day - p1->day) * 24 + p2->hour; k++) {
					dur += 60;
					money += 60 * price[k % 24];
				}
				printf("%s %s %d $%.2f\n", p1->time + 3, p2->time + 3,
					   dur, (float)money / 100);
				p1 = p2 = NULL;
				next = 0;
				money_sum += money;
			}
		}
		if (flag)
			printf("Total amount: $%.2f\n", (float)money_sum / 100);
	}
	return 0;
}
