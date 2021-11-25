#include<stdio.h>
int main(void)
{
    int i,j,n,m;
    long long minimum, value;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%lld",&value);
            if(minimum > value)
            {
                minimum = value;
            }
        }
    }
    printf("%lld\n",minimum);
    return 0;
}
