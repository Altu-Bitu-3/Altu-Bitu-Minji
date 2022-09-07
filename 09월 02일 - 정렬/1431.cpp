//
// Created by KangMinji on 2022-09-07.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countSum(const string &a) {
    int sum = 0;
    for (int i = 0; i < a.length(); i++) {
        if (isdigit(a[i]))
            sum += a[i] - '0'; // char -> int로 변환 필요
    }
    return sum;
}

bool cmp(const string &a, const string &b) {
    // 1) A와 B의 길이가 다르면
    if (a.length() != b.length())
        return a.length() < b.length();

    // 2) 자리수의 합이 다르면(숫자인 경우만)
    if (countSum(a) != countSum(b))
        return countSum(a) < countSum(b);

    // 3) 조건 비교가 불가능하면
    return a < b;
}

int main() {
    int n;
    vector<string> serial;

    // 입력
    cin >> n;
    serial.assign(n, "");

    for (int i = 0; i < n; i++)
        cin >> serial[i];

    // 연산
    sort(serial.begin(), serial.end(), cmp);

    // 출력
    for (int i = 0; i < n; i++)
        cout << serial[i] << "\n";
}