#include <stdio.h>
#include <string.h>

typedef struct
{
	int capacity;
	int left;
	int space;
} jug;

void fill(jug *a)
{
	a->space = 0;
	a->left = a->capacity;
}

void empty(jug *a)
{
	a->space = a->capacity;
	a->left = 0;
}

void pour(jug *a, jug *b)
{
	if (a->left <= b->space)
	{
		b->space -= a->left;
		b->left += a->left;
		empty(a);
		return;
	}
	
	a->space += b->space;
	a->left -= b->space;
	fill(b);
}

int target;
int flag;
char op[100][11];
int i;
char *s = "success\0";

void work(jug A, jug B, char opstr[], char oper)
{
	jug a = A;
	jug b = B;
	if (opstr[0] == 'f')
	{
		if (oper == 'a')
		{
			fill(&a);
			if (a.left == target)
			{
				strcpy(op[i++], s);
				strcpy(op[i++], opstr);
				flag = 1;
				return;
			}
			work(a, b, "pour A B", 'a');
		}
		else
		{
			fill(&b);
			if (b.left == target)
			{
				strcpy(op[i++], s);
				strcpy(op[i++], opstr);
				flag = 1;
				return;
			}
			work(a, b, "pour B A",'b');
		}
	}
	else if (opstr[0] == 'e')
	{
		if (oper == 'a')
		{
			if (!b.left)
				return;
			empty(&a);
			work(a, b, "pour B A", 'b');
		}
		else
		{
			if (!a.left)
				return ;
			empty(&b);
			work(a, b, "pour A B", 'a');
		}
	}
	else /*if (opstr[0] == 'p')*/
	{
		if (oper == 'a')
		{
			pour(&a, &b);
			if (a.left == target || b.left == target)
			{
				strcpy(op[i++], s);
				strcpy(op[i++], opstr);
				flag = 1;
				return;
			}
			if (!a.left)
				work(a, b, "fill A", 'a');
			work(a, b, "empty B", 'b');
		}
		else
		{
			pour(&b, &a);
			if (a.left == target || b.left == target)
			{
				strcpy(op[i++], s);
				strcpy(op[i++], opstr);
				flag = 1;
				return;
			}
			if (!b.left)
				work(a, b, "fill B", 'b');
			work(a, b, "empty A", 'a');
		}
	}
	if (flag)
		strcpy(op[i++], opstr);
}


int main()
{
	jug A, B;

	while (scanf("%d %d %d", &(A.capacity), &(B.capacity), &target) != EOF)
	{
		empty(&A);
		empty(&B);
		flag = 0;
		for (i = 0; i < 100; i++)
			*op[i] = '\0';
		i = 0;
		if (target <= A.capacity)
			work(A, B, "fill A", 'a');
		else
			work(A, B, "fill B", 'b');
		for (i--; i >=0; i--)
			printf("%s\n", op[i]);
	}
	return 0;
}

