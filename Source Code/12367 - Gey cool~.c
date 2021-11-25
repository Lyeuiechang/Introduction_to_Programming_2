#include<stdio.h>
long long numbers[2000001];
long long prefix_sum[2000001];
int main(void)
{
    int n,q,i,a,b,max_a,max_b;
    long long query, max_query;
    while(scanf("%d %d",&n,&q)!=EOF)
    {
        max_query = -1;
        for(i=0;i<2000001;i++)
        {
            numbers[i] = 0;
            prefix_sum[i] = 0;
        }
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&numbers[i]);
        }
        /*for(i=1;i<=n;i++)
        {
            printf("%lld ",numbers[i]);
        }
        printf("\n");*/
        for(i=1;i<=n;i++)
        {
            prefix_sum[i] = prefix_sum[i-1] + numbers[i];
        }
        /*for(i=1;i<=n;i++)
        {
            printf("%lld ",prefix_sum[i]);
        }
        printf("\n");*/
        for(i=0;i<q;i++)
        {
            scanf("%d %d",&a,&b);
            if(a > b)
            {
                query = (prefix_sum[n]-prefix_sum[a-1])+prefix_sum[b];
                //printf("Max_range: (%d,%d); Value: %lld\n",a,b,(prefix_sum[n]-prefix_sum[a-1])+prefix_sum[b]);
            }
            else if(a < b)
            {
                query = prefix_sum[b]-prefix_sum[a-1];
                //printf("Max_range: (%d,%d); Value: %lld\n",a,b,prefix_sum[b]-prefix_sum[a-1]);
            }
            else if(a==b)
            {
                query = numbers[a];
                //printf("Max_range: (%d,%d); Value: %lld\n",a,b,numbers[a]);
            }
            if(max_query < query)
            {
                max_a = a;
                max_b = b;
                max_query = query;
            }
        }
        printf("Max_range: (%d,%d); Value: %lld\n",max_a,max_b,max_query);
    }
    return 0;
}
