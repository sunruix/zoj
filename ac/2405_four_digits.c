#include <stdio.h>

int convert12(int n)
{
	int sum = 0;
	while (n) {
		sum += n % 12;
		n /= 12;
	}
	return sum;
}

int convert16(int n)
{
	int sum = 0;
	while (n) {
		sum += n % 16;
		n /= 16;
	}
	return sum;
}

int convert10(int n)
{
	int sum = 0;
	while (n) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main()
{
	int sum10, sum12, sum16, n = 2992;
	while (n < 10000) {
		sum10 = convert10(n);
		sum12 = convert12(n);
		sum16 = convert16(n);
		if (sum10 == sum12 && sum12 == sum16)
			printf("%d\n", n);
		n++;
	}
	return 0;
}
		
