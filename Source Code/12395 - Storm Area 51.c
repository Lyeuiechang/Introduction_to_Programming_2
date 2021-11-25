#include <stdio.h>
#include <ctype.h>
//#include <string.h>
int calculate(void);
char input[101] = {0};
int x,y,z;
int pointer = 0;
int main(void)
{
    fgets(input, 100, stdin);
    scanf("%d %d %d",&x,&y,&z);
    printf("\n%d\n", calculate());
    return 0;
}
int calculate(void)
{
    int c;
    int ans;
    int op1, op2;
    c = input[pointer];
    pointer++;
    if (isspace(c))
    {
        ans = calculate();
    }
    else if (c=='+')
    {
        //printf("(");
        op1 = calculate();
        printf("+");
        op2 = calculate();
        //printf(")");
        ans = op1 + op2;
    }
    else if (c=='-')
    {
        //printf("(");
        op1 = calculate();
        printf("-");
        op2 = calculate();
        //printf(")");
        ans = op1 - op2;
    }
    else if (c=='*')
    {
        //printf("(");
        op1 = calculate();
        printf("*");
        op2 = calculate();
        //printf(")");
        ans = op1 * op2;
    }
    else if (c=='/')
    {
        //printf("(");
        op1 = calculate();
        printf("/");
        op2 = calculate();
        //printf(")");
        ans = op1 / op2;
    }
    else if (isdigit(c))
    {
        //ungetc(c, stdin);
        pointer--;
        int end_pointer = pointer;
        char temp[4] = {0};
        while(isdigit(c))
        {
            end_pointer++;
            c = input[end_pointer];
        }
        strncpy(temp, input+pointer, end_pointer-pointer);
        ans = atoi(temp);
        //scanf("%d", &ans);
        printf("%d", ans);
        pointer = end_pointer;
    }
    else if(c=='x')
    {
        printf("x");
        ans = x;
    }
    else if(c=='y')
    {
        printf("y");
        ans = y;
    }
    else if(c=='z')
    {
        printf("z");
        ans = z;
    }
    return ans;
}
