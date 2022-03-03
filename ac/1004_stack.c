#include <stdio.h>
#include <string.h>

char src[101], des[101], temp[101];
char op_str[201];
int len;

void print()
{
	int i;

	for (i = 0; i < len; i++)
		printf("%c ", op_str[i]);
}

void check(char op, int tos, int op_p, int src_p, int des_p, char s[])
{

	char stack[101];
	strcpy(stack, s);
	if (op == 'i')
	{
		if (src[src_p] == '\0')
			return;
		op_str[op_p] = op;
		stack[tos + 1] = src[src_p];
		check('i', tos + 1, op_p + 1, src_p + 1, des_p, stack);
		check('o', tos + 1, op_p + 1, src_p + 1, des_p, stack);
	}
	else
	{
		if (!tos)
			return;
		op_str[op_p] = op;
		temp[des_p] = stack[tos];
		if (op_p >= len - 1)
		{
			if (!strcmp(des, temp))
			{
				print();
				printf("\n");
			}
			return;
		}
		check('i', tos - 1, op_p + 1, src_p, des_p + 1, stack);
		check('o', tos - 1, op_p + 1, src_p, des_p + 1, stack);
	}
}

int main()
{
	char s[101];

	while (scanf("%s", src) != EOF)
	{
		scanf("%s", des);

		if (strlen(src) != strlen(des))
		{
			printf("[\n");
			printf("]\n");
			continue;
		}

		len = 2 * strlen(src);
		memset(op_str, 0, 201);
		memset(temp, 0, 101);
		memset(s, 0, 101);
		s[0] = 'a';

		printf("[\n");
		check('i', 0, 0, 0, 0, s);
		printf("]\n");
	}
	return 0;
}

