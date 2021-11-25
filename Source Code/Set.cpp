#include<iostream>
#include<set>
using namespace std;

set<int> Happy;

int main(void)
{
    Happy.insert(5);
    Happy.insert(2);
    Happy.insert(8);
    cout << *(Happy.begin()) << endl;
    cout << *(Happy.end()) << endl;
    for(set<int>::iterator i=Happy.begin();i!=Happy.end();i++)
    {
        cout << *i << " ";
    }
    cout << endl;
    return 0;


}
