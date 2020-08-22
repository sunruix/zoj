#include <stdio.h>

int flaga, flagb, flag;

void search(int A, int B, int i)
{
	if (A == 1)
		flaga = 1;
	if (B == 1)
		flagb = 1;
	if (A == 1 && B == 1)
		flag = 1;
	if (i > 100)
		return;

	if (!flag)
		search(A, B, i + 1);
	if (!flag && !(A % i))
		search(A / i, B, i + 1);
	if (!flag && !(B % i))
		search(A, B / i, i + 1);
}

int main()
{
	int A, B, winner;

	while (scanf("%d %d", &A, &B) != EOF)
	{
		if (B > A)
		{
			B += A;
			A = B - A;
			B -= A;
		}
		winner = A;

		flaga = flagb = flag = 0;
		search(A, B, 2);

		if (flagb && (!flaga || !flag))
			winner = B;
		printf("%d\n", winner);
	}
	return 0;
}

