//
// Created by KangMinji on 2022-09-07.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * 팁 : 원래 주려고 생각했던 돈 - (받은 둥수 - 1)
 * 팁이 음수라면 받을 수 없다.
 * => 원래 주려고 생각했던 돈이 클수록 우선순위
 */
int main() {
    long n, result = 0; // 100000 * 100000 -> int 범위 초과

    // 입력
    cin >> n;
    vector<int> tip_list(n, 0);
    for (int i = 0; i < n; i++)
        cin >> tip_list[i];

    // 연산
    sort(tip_list.begin(), tip_list.end(), greater<>());
    for (int i = 0; i < n; i++) { // i = (등수 -1)
        int tip = tip_list[i] - i;
        if (tip > 0)
            result += tip;
    }

    // 출력
    cout << result;
}