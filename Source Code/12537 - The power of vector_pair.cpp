#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
// pair<index, value>
vector<pair<int, int>> vp;
int status = 0;
bool sortbyvalue(const pair<int,int> &a, const pair<int,int> &b)
{
    if(a.second == b.second)
    {
        return a.first<b.first;
    }
    else
    {
        return a.second<b.second;
    }
}
int main(void)
{
    int i, n, t, capacity;
    string s;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> s;
        if(s.compare("push_back") == 0)
        {
            cin >> t;
            capacity = vp.size();
            if(status != 0)
            {
                status = 0;
                sort(vp.begin(), vp.end());
            }
            vp.push_back(make_pair(capacity, t));
        }
        else if(s.compare("pop_back") == 0)
        {
            capacity = vp.size();
            if(capacity != 0)
            {
                if(status != 0)
                {
                    status = 0;
                    sort(vp.begin(), vp.end());
                }
                vp.pop_back();
            }
        }
        else if(s.compare("find") == 0)
        {
            cin >> t;
            t--;
            capacity = vp.size();
            if(capacity > t)
            {
                if(status != 0)
                {
                    status = 0;
                    sort(vp.begin(), vp.end());
                }
                cout << vp[t].second << endl;
            }
        }
        else if(s.compare("min") == 0)
        {
            capacity = vp.size();
            if(capacity != 0)
            {
                if(status != 1)
                {
                    status = 1;
                    sort(vp.begin(), vp.end(), sortbyvalue);
                }
                cout << vp[0].second << " " << vp[0].first+1 << endl;
            }
        }
        else if(s.compare("max") == 0)
        {
            capacity = vp.size();
            if(capacity != 0)
            {
                if(status != 1)
                {
                    status = 1;
                    sort(vp.begin(), vp.end(), sortbyvalue);
                }
                cout << vp[capacity-1].second << " " << vp[capacity-1].first+1 << endl;
            }
        }
    }
    return 0;
}
