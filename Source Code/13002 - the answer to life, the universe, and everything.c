#include<stdio.h>
#define MAX_LENGTH 1000000000000000000
int main(void)
{
    long long n, buffer, x;
    int i;
    long long faboncci[87] = {0};
    faboncci[0] = 1;
    faboncci[1] = 2;
    for(i=2;i<87;i++)
    {
        faboncci[i] = faboncci[i-1] + faboncci[i-2];
    }
    //printf("%lld\n",MAX_LENGTH - faboncci[86]);
    while(scanf("%lld",&n)!=EOF)
    {
        if(n == 0)
        {
            printf("0\n");
        }
        else
        {
            for(i=85;i>0;i--)
            {
                if(n >= faboncci[i-1])
                {
                    if((n-faboncci[i-1])%faboncci[i] == 0)
                    {
                        printf("%lld\n",(n-faboncci[i-1])/faboncci[i]);
                        break;
                    }
                }
            }
            if(i == 0)
            {
                printf("%lld\n",n-1);
            }
        }
    }
    return 0;
}
