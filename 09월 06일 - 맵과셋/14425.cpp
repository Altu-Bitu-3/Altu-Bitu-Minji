//
// Created by KangMinji on 2022-09-12.
//

#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, m, cnt = 0;
    string input;
    set<string> s;

    // 입력
    cin >> n >> m;
    while (n--) {
        cin >> input;
        s.insert(input);
    }
    while (m--) {
        cin >> input;
        cnt += s.count(input);
    }

    // 출력
    cout << cnt;
}