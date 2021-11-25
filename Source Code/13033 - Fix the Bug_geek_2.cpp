#include <iostream>
#include <unordered_map>
#include<string>
#include<map>
#include<vector>
using namespace std;
vector<long long> a;
map<long long, int> ma;
map<long long, int>::iterator ma_it;
map<long long, int>::iterator ma_jt;
// Function to calculate and return the
// count of pairs
long long concatenate(long long x, long long y) {
    long long pow = 10;
    while(y >= pow)
        pow *= 10;
    return x * pow + y;
}

long long countPairs(vector<long long> a, int n, long long k)
{
    map<int, int> rem[11];
    vector<int> len(n);

    // Compute power of 10 modulo k
    vector<int> p(11);
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
    long long k, buf;
    long long duplicate;
    while(cin >> n >> k)
    {
        for(i=0;i<n;i++)
        {
            cin >> buf;
            ma[buf]++;
        }
        duplicate = 0;
        for(ma_it=ma.begin();ma_it!=ma.end();ma_it++)
        {
            if(ma_it->second > 1)
            {
                if(concatenate(ma_it->first,ma_it->first)%k == 0)
                {
                    duplicate++;
                }
            }
            /*for(ma_jt=ma_it;ma_jt!=ma.end();ma_jt++)
            {
                if(ma_jt != ma_it)
                {
                    if(concatenate(ma_it->first,ma_jt->first)%k == 0)
                    {
                        duplicate++;
                    }
                    if(concatenate(ma_jt->first,ma_it->first)%k == 0)
                    {
                        duplicate++;
                    }
                }

            }*/
            a.push_back(ma_it->first);
        }
        for(i=0;i<a.size();i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        //cout << duplicate << endl;
        //cout << a.size() << endl;
        cout << countPairs(a, a.size(), k)+duplicate << endl;
        ma.clear();
        a.clear();
    }
    return 0;
}
