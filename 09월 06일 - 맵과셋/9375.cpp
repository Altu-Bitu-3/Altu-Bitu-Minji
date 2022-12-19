//
// Created by KangMinji on 2022-09-12.
//

#include <iostream>
#include <map>

using namespace std;

int main() {
    int t, n, result;
    string name, type;

    // 입력
    cin >> t;
    while (t--) {
        map<string, int> m; // 초기화
        result = 1; // 곱셈을 위해 1로 초기화

        cin >> n;
        while (n--) {
            cin >> name >> type;
            m[type]++;
        }
        // 해당 종류의 옷을 입거나 입지 않는 경우
        for (auto iter: m) {
            result *= (iter.second + 1);
        }
        result -= 1; // 알몸이 되는 경우
        cout << result << "\n";
    }

}