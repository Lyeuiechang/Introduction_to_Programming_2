#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char S[1001]= {};
char s[1001]= {};




int main(void)
{
    int t,i,j,l,r;
    while(scanf("%s",S)!=EOF)
    {
        int st[1001]= {};
        int P_st[1001]= {};
        int ed[1001]= {};
        int P_ed[1001]= {};
        scanf("%s",s);
        scanf("%d",&t);
        int S_length = strlen(S);
        int s_length = strlen(s);

        char *loc = strstr(S,s);
        while(loc != NULL)
        {
            ++ed[loc - S + s_length - 1];
            ++st[loc - S];
            loc = strstr(loc+1,s);
        }

        for(int i = 0; i<S_length; ++i)
        {
            P_ed[i] += ed[i];
            P_st[i] += st[i];
            if(i > 0)
            {
                P_st[i] += P_st[i-1];
                P_ed[i] += P_ed[i-1];
            }
        }
        int answer = -1;
        for(i=0; i < t; ++i)
        {
            scanf("%d%d",&l,&r);
            --l;
            --r;
            int a;
            if(l > 0)
                a = P_ed[r]-P_st[l-1];
            else
                a = P_ed[r];
            if(a > answer)
                answer = a;
        }
        printf("%d\n",answer);
    }

    return 0;
}


