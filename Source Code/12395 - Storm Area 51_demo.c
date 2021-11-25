#include <stdio.h>
#include <ctype.h>
int calculate(void);
int main(void)
{
    printf("=%d\n", calculate());
    return 0;
}
int calculate(void)
{
    int c;
    int ans;
    int op1, op2;
    c = getchar();
    if (isspace(c))
    {
        ans = calculate();
    }
    else if (c=='+')
    {
        printf("(");
        op1 = calculate();
        printf("+");
        op2 = calculate();
        printf(")");
        ans = op1 + op2;
    }
    else if (c=='-')
    {
        printf("(");
        op1 = calculate();
        printf("-");
        op2 = calculate();
        printf(")");
        ans = op1 - op2;
    }
    else if (c=='*')
    {
        printf("(");
        op1 = calculate();
        printf("*");
        op2 = calculate();
        printf(")");
        ans = op1 * op2;
    }
    else if (c=='/')
    {
        printf("(");
        op1 = calculate();
        printf("/");
        op2 = calculate();
        printf(")");
        ans = op1 / op2;
    }
    else if (isdigit(c))
    {
        ungetc(c, stdin);

        scanf("%d", &ans);
        printf("%d", ans);
    }
    return ans;
}
