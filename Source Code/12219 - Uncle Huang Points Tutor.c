#include<stdio.h>
#include<stdlib.h>

long long int fastPowerMod(long long int x, long long int y, long long int m){
    if(m == 0){return 0;}
    if(y == 0 || x == 1){return 1 % m;}
    else if(y == 1){return x % m;}
    else if(y % 2){return ((x % m) * (fastPowerMod(((x % m) * (x % m)) % m, y >> 1, m) % m)) % m;}
    else if(!(y % 2)){return fastPowerMod(((x % m) * (x % m)) % m, y >> 1, m) % m;}
}

int main(){
    long long int x = 0, y = 0, m = 0;
    scanf("%lld %lld %lld", &x, &y, &m);

    printf("%lld\n", fastPowerMod(x, y, m));

    return 0;
}
