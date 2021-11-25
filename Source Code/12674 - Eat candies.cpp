#include<iostream>
#include <algorithm>
using namespace std;
int main(void)
{
    int t;
    int candy[3];
    cin >> t;
    for(int i=0;i<t;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin >> candy[j];
        }
        sort(candy,candy+3);
        if(candy[0]+candy[1] >= candy[2])
        {
            cout << (candy[0]+candy[1]+candy[2])/2 << endl;
        }
        else
        {
            cout << candy[0]+candy[1] << endl;
        }
    }
    return 0;
}
