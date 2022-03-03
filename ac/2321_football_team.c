#include <stdio.h>
#include <string.h>

int main()
{
	double speed, weight, strength;
	struct {
		char position[16];
		double speed, weight, strength;
	} record[3];
	int count, i;
	freopen("input", "r", stdin);
	strcpy(record[0].position, "Wide Receiver\0");
	strcpy(record[1].position, "Lineman\0");
	strcpy(record[2].position, "Quarterback\0");
	record[0].speed = 4.5, record[0].weight = 150, record[0].strength = 200;
	record[1].speed = 6.0, record[1].weight = 300, record[1].strength = 500;
	record[2].speed = 5.0, record[2].weight = 200, record[2].strength = 300;
	while (scanf("%lf %lf %lf", &speed, &weight, &strength) != EOF &&
			(speed || weight || strength)) {
		count = 0;
		for (i = 0; i < 3; i++) {
			if (speed <= record[i].speed && weight >= record[i].weight &&
					strength >= record[i].strength) {
				if (count)
					printf(" ");
				printf("%s", record[i].position);
				count++;
			}
		}
		if (!count)
			printf("No positions\n");
		else
			printf("\n");
	}
	return 0;
}
