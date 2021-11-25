#include <iostream>
#include <set>

using namespace std;

int main() {
    set <pair<int, string>> people;
    int time;
    cin >> time;
    while(time--) {
        string cmd;
        cin >> cmd;
        if(cmd == "born") {
            pair<int, string> temp;
            cin >> temp.second >> temp.first;
            people.insert(temp);
        }
        else if(cmd == "find") {
            pair<int, string> temp;
            cin >> temp.second >> temp.first;
            auto i = people.find(temp);
            if(i != people.end()) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else if(cmd == "kill") {
            pair<int, string> temp;
            cin >> temp.second >> temp.first;
            auto i = people.find(temp);
            if(i != people.end())
                people.erase(i);
        }
        else if(cmd == "young") {
            if(!people.empty()) {
                auto temp = *people.begin();
                cout << temp.second << " " << temp.first << endl;
            }
        }
    }
    return 0;
}
