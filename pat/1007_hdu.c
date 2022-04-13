#include <stdio.h>

int main(void)
{
    int T, N;
    int first, last, tmpfirst;
    int i, j;
    int S, Sum, A[100001];

    scanf("%d", &T);
    for (i = 1; i <= T; i++)
    {
        scanf("%d", &N);
        S = 0;
        Sum = -1000;
        first = tmpfirst = last = 1;

        for (j = 1; j <= N; j++)
        {
            scanf("%d", &A[j]);

            S += A[j];
            if (S > Sum)
            {
                Sum = S;
                last = j;
                if (first < tmpfirst)
                    first = tmpfirst;
                if (Sum <= 0)
                    first = j;
            }
            if (S < 0)
            {
                S = 0;
                tmpfirst = j + 1;
            }
        }
        printf("Case %d:\n", i);
        printf("%d %d %d\n",  Sum, first, last);
        if (i != T)
            printf("\n");
    }
    return 0;
}
