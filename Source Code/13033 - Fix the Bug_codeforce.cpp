#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int N = 2e5 + 5;
const int LOGN = 11;
vector<int> rems[LOGN];
int n, k;
int a[N];
int len[N];
int pw[LOGN];

int main()
{
    while(scanf("%d%d", &n, &k)!=EOF)
    {
        for (size_t i = 0; i < LOGN; i++)
        {
            rems[i].clear();
        }
        for(size_t i = 0; i < N; i++)
        {
            len[i] = 0;
        }
        for (size_t i = 0; i < n; i++)
            scanf("%d", &a[i]);

        pw[0] = 1;
        for (size_t i=0; i < LOGN-1; i++)
            pw[i + 1] = pw[i] * 10 % k;

        for (size_t i=0; i < n; i++)
        {
            int x = a[i];
            while (x > 0)
            {
                len[i]++;
                x /= 10;
            }
            rems[len[i]].push_back(a[i] % k);
        }

        for (size_t i=0; i < LOGN-1; i++)
            sort(rems[i].begin(), rems[i].end());

        ll ans = 0;
        for (size_t i=0; i < n; i++)
        {
            for (size_t j = 1; j < LOGN; j++)
            {
                int rem = (a[i] * ll(pw[j])) % k;
                int xrem = (k - rem) % k;
                auto l = lower_bound(rems[j].begin(), rems[j].end(), xrem);
                auto r = upper_bound(rems[j].begin(), rems[j].end(), xrem);
                ans += (r - l);
                if (len[i] == j && (rem + a[i] % k) % k == 0)
                    --ans;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
