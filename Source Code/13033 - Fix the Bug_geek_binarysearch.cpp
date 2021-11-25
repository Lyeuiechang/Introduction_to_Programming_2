#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> big_a;
vector<int> lite_a;
// Function to calculate and return the
// count of pairs
int countPairs(vector<int> a, int n, int k)
{
    map<int, int> rem[11];
    // Compute power of 10 modulo k
    vector<int> p(11);

    p[0] = 1;
    for (int i = 1; i <= 10; i++) {
        p[i] = (p[i - 1] * 10) % k;
    }

    vector<int> len(n);

    for (int i = 0; i < n; i++) {
        int x = a[i];

        // Calculate length of a[i]
        while (x > 0) {
            len[i]++;
            x /= 10;
        }

        // Increase count of remainder
        rem[len[i]][a[i] % k]++;
    }

    int ans = 0;

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
int find_next(vector<int> big_a, int low, int high, long long x, int n)
{
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if ((mid == n - 1 || x < big_a[mid + 1]) && big_a[mid] == x)
            return mid;
        else if (x < big_a[mid])
            return find_next(big_a, low, (mid - 1), x, n);
        else
            return find_next(big_a, (mid + 1), high, x, n);
    }
    return -1;
}
int main(void)
{
    int i, j, n, times, buffer_a, k, cur_a, c;

    while(scanf("%d %d",&n,&k)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            cin >> buffer_a;
            big_a.push_back(buffer_a);
        }
        sort(big_a.begin(), big_a.end());
        for(i=0,times = 0,cur_a=big_a[0];i<n;)
        {
            //cout << "HI" << endl;
            buffer_a = big_a[i];
            times++;
            if(buffer_a == cur_a)
            {
                if(times < 3)
                {
                    i++;
                    lite_a.push_back(buffer_a);
                }
                else
                {
                    i = find_next(big_a, 0, n, buffer_a, n)+1;
                    //cout << a[i] << endl;
                    //system("pause");
                    times = 0;
                }
            }
            else
            {
                lite_a.push_back(buffer_a);
                cur_a = buffer_a;
                times = 1;
                i++;
            }
        }
        c = lite_a.size();
        //cout << c << endl;
        cout << countPairs(lite_a, c, k) << endl;
        big_a.clear();
        lite_a.clear();
        //rem.clear();
    }
    return 0;
}
