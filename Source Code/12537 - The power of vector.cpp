#include<iostream>
#include<vector>
using namespace std;
vector<int> v;
vector<int> it_v;
int main(void)
{
    int i, j, n, t;
    cin >> n;
    string s;
    for(i=0;i<n;i++)
    {
        cin >> s;
        if(s.compare("push_back") == 0)
        {
            cin >> t;
            //cout << "hi";
            v.push_back(t);
        }
        else if(s.compare("pop_back") == 0)
        {
            if(v.size()!=0)
            {
                v.pop_back();
            }
        }
        else if(s.compare("find") == 0)
        {
            cin >> t;
            t--;
            if(v.size() > t)
            {
                cout << v[t] << endl;
            }
        }
        else if(s.compare("min") == 0)
        {
            int capacity = v.size();
            int min_index;
            int min_value = 2147483647;
            if(capacity!=0)
            {
                for(j=0;j<capacity;j++)
                {
                    if(min_value > v[j])
                    {
                        min_value = v[j];
                        min_index = j;
                    }
                }
            }
        }
        else if(s.compare("max") == 0)
        {
            int capacity = v.size();
            int max_index;
            int max_value = -2147483647;
            if(capacity!=0)
            {
                for(j=0;j<capacity;j++)
                {
                    if(max_value <= v[j])
                    {
                        max_value = v[j];
                        max_index = j;
                    }
                }
            }

        }
    }
    return 0;
}
