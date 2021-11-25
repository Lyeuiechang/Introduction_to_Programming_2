#include<stdio.h>
long long A[1002][1002] = {0};
long long A_PrefixSum[1002][1002] = {0};
int main(void)
{
    int i,j,x1,x2,y1,y2,n,m;
    long long value;
    double mean, minimum_mean;
    minimum_mean = 9223372036854775807;
    scanf("%d %d",&n,&m);
    for(y1=1;y1<=n;y1++)
    {
        for(x1=1;x1<=m;x1++)
        {
            scanf("%lld",&A[x1][y1]);
            A_PrefixSum[x1][y1] = A[x1][y1] + A_PrefixSum[x1-1][y1] + A_PrefixSum[x1][y1-1] - A_PrefixSum[x1-1][y1-1];
        }
    }
    for(y1=1;y1<=n;y1++)
    {
        for(x1=1;x1<=m;x1++)
        {
            printf("%lld ",A_PrefixSum[x1][y1]);
        }
        printf("\n");
    }
    for(y1=1;y1<=n;y1++)
    {
        for(x1=1;x1<=m;x1++)
        {
            for(y2=1;y2<=n;y2++)
            {
                for(x2=1;x2<=m;x2++)
                {
                    value = A_PrefixSum[x2][y2] - A_PrefixSum[x1-1][y2] - A_PrefixSum[x2][y1-1] + A_PrefixSum[x1-1][y1-1];
                    mean = value / ((x2-x1+1)*(y2-y1+1));
                    if(minimum_mean > mean)
                    {
                        minimum_mean = mean;
                    }
                }
            }
            printf("%f\n",minimum_mean);
            return 0;
        }
    }
}
