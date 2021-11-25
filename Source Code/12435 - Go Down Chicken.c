#include<stdio.h>
#define MOD 1000000007
//long long int tiles_height[1000001] = {0};
typedef struct tiles{
    long long int round;
    long long int ways;
}tiles;
tiles tiles_possible[1000001];
long long int fastPowerMod(long long int x, long long int y, long long int m){
    if(m == 0){return 0;}
    if(y == 0 || x == 1){return 1 % m;}
    else if(y == 1){return x % m;}
    else if(y % 2){return ((x % m) * (fastPowerMod(((x % m) * (x % m)) % m, y >> 1, m) % m)) % m;}
    else if(!(y % 2)){return fastPowerMod(((x % m) * (x % m)) % m, y >> 1, m) % m;}
}

int main(void)
{
    int i,j,n,q,query;
    long long int possible_ways, max_possible_ways, tiles_height;
    char emoji_trashcan[8];
    while(scanf("%d %d",&n,&q)!=EOF)
    {
        max_possible_ways = -1;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&tiles_height);
            if(tiles_height%2==0)
            {
                possible_ways = fastPowerMod(2, tiles_height/2, MOD);
                if(max_possible_ways < possible_ways)
                {
                    max_possible_ways = possible_ways;
                }
                tiles_possible[i] = possible_ways;
            }
            scanf("%s",&emoji_trashcan);
            scanf("%s",&emoji_trashcan);
        }
        /*for(i=0;i<n;i++)
        {
            printf("%d ",tiles_height[i]);
        }
        printf("\n");*/
        for(i=0;i<q;i++)
        {
            scanf("%d",&query);
            if(query > max_possible_ways)
            {
                j = n;
            }
            else
            {
                for(j=0;j<n;j++)
                {
                    if(tiles_possible[j] == query)
                    {
                        break;
                    }
                }
            }
            if(j<n)
            {
                printf("%d\n", j+1);
            }
            else
            {
                printf("Go Down Chicken 404\n");
            }
        }
        for(i=0;i<n;i++)
        {
            tiles_possible[i] = 0;
        }
    }
    return 0;
}
