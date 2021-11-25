#include<stdio.h>
#include<string.h>
int main(void)
{
    char S[1002] = {0};
    while(scanf("%s",&S)!=EOF)
    {
        int len_p, len_S, i, q, a, b, query, max_query;
        char p[1002] = {0};
        int highlighter[1002] = {0};
        int prefix_sum[1002] = {0};
        scanf("%s",&p);
        len_p = strlen(p);
        len_S = strlen(S);
        for(i=0;i<len_S;i++)
        {
            if(S[i] == p[0])
            {
                //printf("HI\n");
                if(strncmp(S+i,p,len_p) == 0)
                {
                    highlighter[i+1] = 1;
                }
            }
        }
        /*for(i=0;i<len_S;i++)
        {
            printf("%d",highlighter[i]);
        }
        printf("\n");*/
        for(i=1;i<len_S+1;i++)
        {
            prefix_sum[i] = prefix_sum[i-1] + highlighter[i];
        }
        scanf("%d",&q);
        max_query = -1;
        for(i=0;i<q;i++)
        {
            scanf("%d %d",&a,&b);
            query = prefix_sum[b-len_p+1] - prefix_sum[a-1];
            if(max_query < query)
            {
                max_query = query;
            }
        }
        printf("%d\n",max_query);
        for(i=0;i<len_S;i++)
        {
            S[i] = 0;
        }
    }
    return 0;
}
