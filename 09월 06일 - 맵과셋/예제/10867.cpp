//
// Created by KangMinji on 2022-09-07.
//

#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, input;
    set<int> s;

    // 입력
    cin >> n;
    while(n--){
        cin >> input;
        s.insert(input);
    }

    // 출력
    for (auto iter : s)
        cout << iter << ' ';
}