#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MOD 1000000007

char s[2000001];
char right[2000001];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int x;
        scanf("%d %s",&x,s);
        int l = strlen(s);
        int i,j;
        int L = l,idx = 0;
        while(L < x)
        {
            int cnt = s[idx]-'1';
            strcpy(right,s+idx+1);
            int copy_length = strlen(right);
            for(i=0;i<cnt;i++)
            {
                strcpy(s+L,right);
                L += copy_length;
                if(L > x)
                    break;
            }
            ++idx;
        }
        long long sol = l;
        for(i=0;i<x;i++)
        {
            sol += (s[i]-'1')*(sol-i-1);
            sol %= MOD;
            sol += MOD;
        }
        printf("%lld\n",sol%MOD);
    }
    return 0;
}
