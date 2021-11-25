#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007
typedef struct _array{
   long long int round;
   long long int ways;
} arr;
//arr game[1000000];
int cmp(const void *a, const void *b){

   const arr *c = (arr *)a;
   const arr *d = (arr *)b;
   if ((c->ways) == (d->ways)) //if ways equals,sort by round
      return (int)(c->round) - (d->round);
   else
      return (int)(c->ways) - (d->ways);
}
long long int power(long long int base, long long int exp){
   long long int ans = 1;
   while (exp)
   { //exp!=0
      if (exp & 1)
         ans = ((ans % MOD) * (base % MOD)) % MOD; // (a*b)%p = ((a%p)*(b%p))%p
      base = ((base % MOD) * (base % MOD)) % MOD;
      exp >>= 1;
   }
   return ans;
}
long long int Search(long long int times, long long int n, arr *game)
{
   long long int l = 0, r = n, m;
   while (l < r)
   {
      m = (l + r) / 2;
      if (times <= game[m].ways)
         r = m;
      else //times>ways
         l = m + 1;
   }
   if (game[r].ways == times)
      return r;
   else //not found
      return -1;
}
int main()
{

   long long int n, q, times, found; //n integers,q queries
   while (scanf("%lld %lld", &n, &q) != EOF)
   {
      arr game[n + 1];
	  long long int cols;
      for (long long int i = 0; i < n; i++)
      {
         game[i].round = i + 1;
         scanf("%lld(/`A`)/ ~I__I", &cols);
         if (cols % 2 == 1) //odd
            game[i].ways = 0;
         else //even
            game[i].ways = power(2, cols / 2);
      }
      qsort(game, n, sizeof(arr), cmp); //sort ways
      while (q--)
      {
         scanf("%lld", &times);
         found = Search(times, n, game);
         if (found != -1)
            printf("%lld\n", game[found].round);
         else //found==-1
            printf("Go Down Chicken 404\n");
      }
   }
}
