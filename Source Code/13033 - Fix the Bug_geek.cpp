#include<iostream>
#include<map>
#include<vector>
using namespace std;
map<long long, int> a_map;
long long a[200001];
int len[200001];
// Function to calculate and return the
// count of pairs
long long countPairs(int n, long long k)
{
    map<int, int> rem[11];
    for(int i=0;i<n;i++)
    {
        len[i] = 0;
    }
    // Compute power of 10 modulo k
    int p[11];
    p[0] = 1;
    for (int i = 1; i <= 10; i++) {
        p[i] = (p[i - 1] * 10) % k;
    }

    for (int i = 0; i < n; i++) {
        long long x = a[i];

        // Calculate length of a[i]
        while (x > 0) {
            len[i]++;
            x /= 10;
        }

        // Increase count of remainder
        rem[len[i]][a[i] % k]++;
    }

    long long ans = 0;

    for (int i = 0; i < n; i++) {

        for (int j = 1; j <= 10; j++) {

            // Calculate (a[i]* 10^lenj) % k
            int r = (a[i] * p[j]) % k;

            // Calculate (k - (a[i]* 10^lenj)% k) % k
            int xr = (k - r) % k;

            // Increase answer by count
            ans += rem[j][xr];

            // If a pair (a[i], a[i]) is counted
            if (len[i] == j
                && (r + a[i] % k) % k == 0)
                ans--;
        }
    }

    // Return the count of pairs
    return ans;
}
int main(void)
{
    int i, n;
    long long k;
    while(cin >> n >> k)
    {
        for(i=0;i<n;i++)
        {
            cin >> a[i];
        }
        cout << countPairs(n, k) << endl;
    }
    return 0;
}
