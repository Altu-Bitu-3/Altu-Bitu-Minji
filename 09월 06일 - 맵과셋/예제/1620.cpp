//
// Created by KangMinji on 2022-09-07.
//

#include <iostream>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    string input;
    map<string, int> pocket_name;
    map<int, string> pocket_num;

    // 입력
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> input;
        pocket_name[input] = i;
        pocket_num[i] = input;
    }

    // 출력
    while (m--) {
        cin >> input;
        if (isdigit(input[0]))
            cout << pocket_num[stoi(input)] << "\n";
        else
            cout << pocket_name[input] << "\n";
    }
}