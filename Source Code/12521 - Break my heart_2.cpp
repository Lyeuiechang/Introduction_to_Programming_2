#include<iostream>
#include<set>
using namespace std;
set<int> S;
int main(void)
{
    int i,n,ai,l,r;
    set<int>::iterator t;
    char ins[12];
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> ins;
        if(ins[0] == 'i')
        {
            cin >> ai;
            S.insert(ai);
        }
        else if(ins[0] == 'p')
        {
            if(S.size() != 0)
            {
                t = S.begin();
                cout << *t;
                t++;
                for(;t!=S.end();t++)
                {
                    cout << " " << *t;
                }
                cout << endl;
            }
        }
        else if(ins[0] == 'm')
        {
            if(S.size() != 0)
            {
               cout << *(S.begin()) << endl;
            }
        }
        else if(ins[0] == 'r')
        {
            cin >> l;
            cin >> r;
            if(S.size() != 0)
            {
                S.erase(S.lower_bound(l),S.upper_bound(r));
            }
        }
    }
    return 0;
}
