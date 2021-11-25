#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct holes{
    int visit;
    int x;
    int y;
}holes;
holes hole[10001];

int distance(int a,int b,int c,int d)
{
    return sqrt((a-b)*(a-b)+(c-d)*(c-d));
}

int main()
{
    int numbers,distance;
    scanf("%d%d",&numbers,&distance);
    int i,j,k;
    for(i=0;i<numbers;i++)
    {
        hole[i].visit = 0;
        scanf("%d %d",&hole[i].x,&hole[i].y);
    }
    for(i=0;i<numbers;i++)
    {
        for(j=i+1;j<numbers;j++)
        {
            int ans = distance(hole[i].x,hole[i].y,hole[j].x,hole[j].y);
            printf("%d\n",ans);
        }
    }
}
