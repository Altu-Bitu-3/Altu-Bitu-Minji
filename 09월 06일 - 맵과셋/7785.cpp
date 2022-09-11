//
// Created by KangMinji on 2022-09-12.
//

#include <iostream>
#include <set>
using namespace std;

int main() {
    long n;
    string name, state;
    set<string> s;

    // 입력
    cin >> n;
    while(n--){
        cin >> name >> state;
        if (state == "enter")
            s.insert(name);
        else if (state == "leave")
            s.erase(name);
    }

    // 출력(역순 출력)
    for (auto iter = s.rbegin(); iter!=s.rend(); iter++)
        cout << *iter << "\n";
}