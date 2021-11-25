#include<iostream>
//#include<stdlib.h>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
vector<long long> a;
vector<long long> lite_a;
map<string, long long> m;
map<string, long long>::iterator m_s;
int i, j, n, times;
long long buffer_a, k, cur_a, c, ans;
int find_next(int low, int high, long long x, int n)
{
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if ((mid == n - 1 || x < a[mid + 1]) && a[mid] == x)
            return mid;
        else if (x < a[mid])
            return find_next(low, (mid - 1), x, n);
        else
            return find_next((mid + 1), high, x, n);
    }
    return -1;
}
int main(void)
{
    while(scanf("%d %lld",&n,&k)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            cin >> buffer_a;
            a.push_back(buffer_a);
        }
        sort(a.begin(), a.end());
        for(i=0,times = 0,cur_a=a[0];i<n;)
        {
            //cout << "HI" << endl;
            buffer_a = a[i];
            //times++;
            if(buffer_a == cur_a)
            {
                if(times < 3)
                {
                    //i++;
                    lite_a.push_back(buffer_a);
                }
                else
                {
                    i = find_next(0, n, buffer_a, n)+1;
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
                //i++;
            }
        }
        c = lite_a.size();
        //cout << c << endl;
        for(i=0;i<c;i++)
        {
            for(j=0;j<c;j++)
            {
                if(i!=j)
                {
                    string si = to_string(lite_a[i]);
                    string sj = to_string(lite_a[j]);
                    m.insert(make_pair(si+sj,stoll(si+sj)));
                }
            }
        }
        ans = 0;
        for(m_s=m.begin();m_s!=m.end();m_s++)
        {
            if(m_s->second % k == 0)
            {
                ans++;
            }
        }
        cout << ans << endl;
        a.clear();
        lite_a.clear();
        m.clear();
    }
    return 0;
}
