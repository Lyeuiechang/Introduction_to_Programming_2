#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long long count[100001]={0};

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

int upper_bound(long long *arr,int end,long long tar)
{
    int l = 0;
    int r = end;

    while(l < r)
    {
        int mid = (l+r)/2;
        if(arr[mid]>tar)
            r = mid;
        else
            l = mid + 1;
    }
    return r;
}

int lower_bound(long long *arr,int end,long long tar)
{
    int l = 0;
    int r = end;

    while(l < r)
    {
        int mid = (l+r)/2;
        if(arr[mid]>=tar)
            r = mid;
        else
            l = mid + 1;
    }
    return r;
}

long long query(long long *arr,long long number,int end)
{
    int upper,lower;
    upper = upper_bound(arr, end,number);
    lower = lower_bound(arr, end,number);
    return upper-lower;
}

int main()
{
    int N;
    scanf("%d",&N);
    int i,j;
    int lines;

    for(i=0;i<N;i++)
    {
        scanf("%lld",&count[i]);
    }
    qsort(count,N,sizeof(count[0]),compare);
    for(j=0;j<N;j++)
    {
        printf("%lld ",count[j]);
    }
    scanf("%d",&lines);
    while(lines)
    {
        int number;
        long long ans;
        scanf("%d",&number);
        ans = query(count,number,N);
        printf("%lld\n",ans);
        lines--;
    }
    return 0;
}
