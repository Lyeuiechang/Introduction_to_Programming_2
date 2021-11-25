#include<iostream>
#include<map>
using namespace std;
string s[200001];
map<long long int, string> c;
map<long long int, string>::iterator c_it;
int main(void)
{
    int i, j, n;
    long long int k;
    while(scanf("%d %lld",&n,&k)!=EOF)
    {
        string buf;
        long long int ans = 0;
        for(i=0;i<n;i++)
        {
            cin >> s[i];
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i!=j)
                {
                    buf = s[i]+s[j];
                    //cout << buf << endl;
                    c.insert(pair<long long int, string>(stoll(buf),buf));
                }
            }
        }
        for(c_it=c.begin();c_it!=c.end();c_it++)
        {
            if(c_it->first%k == 0)
            {
                ans++;
            }
        }
        cout << ans << endl;
        c.clear();
    }
    return 0;
}
