#include <stdio.h>
int main() {
    long long i, n, t1 = 1, t2 = 1, nextTerm;
    printf("Enter the number of terms: ");
    //scanf("%lld", &t2);
    n=95;
    printf("Fibonacci Series: ");
    for (i = 1; i <= n; ++i) {
        printf("%lld, ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }

    return 0;
}
