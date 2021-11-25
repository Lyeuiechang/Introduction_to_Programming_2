#include<iostream>
#include<string>
#define MOD 1000000007
using namespace std;
int main(void)
{
    int i, j, t;
    long long x, len_s;
    string s;
    cin >> t;
    for(i=0;i<t;i++)
    {
        cin >> x;
        cin >> s;
        len_s = s.length();
        for(j=0;j<x;j++)
        {
            if(s[j] == '1')
            {
                //len_s = len_s - j;
            }
            else if(s[j] == '2')
            {
                if(s.length()<x)
                {
					string buf = s.substr(j+1);
					//cout << buf << endl;
                    s = s + buf;
                    //cout << s << endl;
                }
                len_s = (((len_s - (j+1))*2)%MOD + (j+1))%MOD;
            }
            else if(s[j] == '3')
            {
                if(s.length()<x)
                {
                    string buf = s.substr(j+1);
                    //cout << buf << endl;
                    s = s + buf + buf;
                    //cout << s << endl;
                }
                len_s = (((len_s - (j+1))*3)%MOD + (j+1))%MOD;
            }
            if(len_s <= 0)
            {
                len_s = len_s + MOD;
            }
             //cout << "Length: " << len_s << endl;
        }
        //len_s = (len_s + x)%MOD;
        cout << len_s << endl;
    }
    return 0;
}
