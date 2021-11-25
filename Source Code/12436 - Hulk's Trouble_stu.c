#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long long arr[100001]={};
long long arr2[100001]={};
int count[100001]={};
long long compare( const void* a, const void* b)
{
     long long ll_a = * ( (long long*) a );
     long long ll_b = * ( (long long*) b );

     if ( ll_a == ll_b )
        return 0;
     else if ( ll_a < ll_b )
        return -1;
     else
        return 1;
}

int main()
{
    int N;
    scanf("%d",&N);
    int i,j;
    for(i=0;i<N;i++)
    {
        scanf("%lld",&arr[i]);
    }
    qsort(arr,N,sizeof(arr[0]),compare);
    int count1=0,count2=1;
    int biggest;
    for(i=0;i<N;i++)
    {
        if(i==0)
        {
            arr2[count1]=count2;
            count2++;
            count[count1]=arr[i];
        }
        else
        {
            if(arr[i]!=arr[i-1])
            {
                count2=1;
                count1++;
                count[count1]=arr[i];
            }
            else
            {
                count2++;
            }
            arr2[count1]=count2;
        }
    }
    biggest = count1;
    int M;
    scanf("%d",&M);
    for(i=0;i<M;i++)
    {
        long long a;
        scanf("%lld",&a);
        for(j=0;j<biggest;j++)
        {
            if(a==count[j])
            {
                printf("%lld\n",arr2[j]);
                break;
            }
            else if(a < count[j])
            {
                printf("0\n");
                break;
            }
            else if(a > count[j] && j==biggest-1)
            {
                printf("0\n");
            }
        }
    }
    return 0;
}