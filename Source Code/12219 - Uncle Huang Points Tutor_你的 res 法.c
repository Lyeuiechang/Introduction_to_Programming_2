#include<stdio.h>
#include<stdlib.h>

long long int fastPowerMod(long long int x, long long int y, long long int m)
{
    long long int res = 1;
    while(y>0)
    {
        if(y%2 == 1)
        {
            res = (res * (x% m)% m);
        }
        y = y / 2;
        x = (x% m) * (x% m) ;
    }
    return res;
}

int main()
{
    long long int x = 0, y = 0, m = 0;
    scanf("%lld %lld %lld", &x, &y, &m);

    printf("%lld\n", fastPowerMod(x, y, m));

    return 0;
}
