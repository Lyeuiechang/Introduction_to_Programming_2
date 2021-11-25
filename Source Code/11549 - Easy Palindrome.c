#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    char A[8] = {0};
    char B[8] = {0};
    scanf("%s",&A);
    B[0] = A[2];
    B[1] = A[1];
    B[2] = A[0];
    B[3] = A[3];
    B[4] = A[6];
    B[5] = A[5];
    B[6] = A[4];
    //printf("%s %s\n",A,B);
    double a = atof(A);
    double b = atof(B);
    //printf("%.3lf %.3lf\n",a,b);
    double c = a + b;
    printf("%.3lf",c);
    return 0;
}
