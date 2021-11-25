#include<iostream>
#include<utility>
#include<set>
#include<vector>
using namespace std;
vector<int> v;
set<pair<int,int>> sp;
set<pair<int,int>>::iterator sp_it;

int main(void)
{
    int i, n, c, d, t;
    string s;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> s;
        if(s.compare("push_back") == 0)
        {
            cin >> t;
            v.push_back(t);
            c = v.size();
            sp.insert(make_pair(t, c));
        }
        else if(s.compare("pop_back") == 0)
        {
            c = v.size();
            if(c != 0)
            {
                t = v[c-1];
                v.pop_back();
                /*for(sp_it = sp.begin();sp_it!=sp.end();sp_it++)
                {
                    if(sp_it->second == c)
                    {
                        sp.erase(sp_it);
                        break;
                    }
                }*/
                sp_it = sp.find(make_pair(t, c));
                sp.erase(sp_it);
            }
        }
        else if(s.compare("find") == 0)
        {
            cin >> t;
            t--;
            c = v.size();
            if(c > t)
            {
                cout << v[t] << endl;
            }
        }
        else if(s.compare("min") == 0)
        {
            if(v.size()!=0)
            {
                cout << sp.begin()->first << " " << sp.begin()->second << endl;
            }
        }
        else if(s.compare("max") == 0)
        {
            if(v.size()!=0)
            {
                cout << sp.rbegin()->first << " " << sp.rbegin()->second << endl;
            }
        }
    }
    return 0;
}
