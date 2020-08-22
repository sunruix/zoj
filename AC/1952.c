#include<stdio.h>
#include<math.h>
#include<string.h>
#define INF 99999999
int count = 0;
char name[201][40];
int find(char *a)
{
    int i;
    for( i = 1; i <= count; i++ )
        if( strcmp(a,name[i]) == 0 )
            return i;
    count = i;
    strcpy(name[i],a);
    return i;
}
int main( void)
{
    int n,r,t,max,l=1;
    int start,end,j,i,now;
    int from,to;
    int mat[201][201];
    int dist[201],flag[201];
    char a[40],b[40];
    while( scanf("%d%d",&n,&r) != EOF )
    {
        if( !n && !r ) break;
        for( i = 1; i <= n; i++ )
        {
            dist[i] = 0;
            flag[i] = 0;
            for( j = 1; j <= n; j++ )
                mat[i][j] = 0;
        }
        for( i = 1; i <= r; i++ )
        {
            scanf("%s%s",a,b);
            from = find(a);
            to = find(b);
            scanf("%d",&j);
            mat[from][to] = mat[to][from] = j;
        }
        scanf("%s%s",a,b);
        start = find(a);
        end = find(b);
        
        dist[now = start] = INF;
        flag[now] = 1;
        for(i = 1; i < n; i++ )
        {
            for( j = 1; j <= n; j++ )
            {
                if( flag[j] ) continue;
                t = dist[now]<mat[now][j]?dist[now]:mat[now][j];
                if( dist[j] < t )
                    dist[j] = t;
            }   
            for( j = 1,max = -1; j <= n; j++ )
                if( flag[j] == 0 && dist[j] > max )
                    max = dist[now=j];
            flag[now] = 1;
        }
        printf("Scenario #%d/n",l++);
        printf("%d tons/n/n",dist[end]);        
    }
    return 0;
}
