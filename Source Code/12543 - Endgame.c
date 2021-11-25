#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char map[1001][1001];

int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    int i,j;
    printf("%d %d\n",N,M);
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            scanf(" %c",&map[i][j]);
            printf("Input: %c\n",map[i][j]);
        }
    }
    return 0;
}
