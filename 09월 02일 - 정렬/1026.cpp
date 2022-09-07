//
// Created by KangMinji on 2022-09-07.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, result = 0;

    // 입력
    cin >> n;
    vector<int> a(n, 0);
    vector<int> b(n, 0);

    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    for (int i=0; i<n; i++) {
        cin >> b[i];
    }

    // 연산
    sort(a.begin(), a.end(), greater<>()); // 내림차순
    sort(b.begin(), b.end());

    for (int i=0; i<n; i++){
        result += a[i]*b[i];
    }

    // 출력
    cout << result;
}