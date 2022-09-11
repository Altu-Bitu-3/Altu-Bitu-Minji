//
// Created by KangMinji on 2022-09-11.
//

#include <iostream>
#include <set>
using namespace std;

bool check(int num, set<int> &s) {
    return s.find(num) != s.end();
}

void toggle(int num, set<int> &s) {
    if (check(num, s))
        s.erase(num);
    else
        s.insert(num);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, num;
    string op;
    set<int> s, full_s;

    for (int i = 1; i <= 20; i++)
        full_s.insert(i);

    // 입력
    cin >> m;
    while (m--) {
        cin >> op;
        if (op == "add") {
            cin >> num;
            s.insert(num);
        } else if (op == "remove") {
            cin >> num;
            s.erase(num);
        } else if (op == "check") {
            cin >> num;
            cout << check(num, s) << "\n";
        } else if (op == "toggle") {
            cin >> num;
            toggle(num, s);
        } else if (op == "all")
            s = full_s;
        else if (op == "empty")
            s.clear();
    }
}