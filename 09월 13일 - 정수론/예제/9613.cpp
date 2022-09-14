//
// Created by KangMinji on 2022-09-14.
//

#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

long long getSum(int n, vector<int> &v) {
    // 최대 100개의 숫자 -> C(100, 2) = 4950
    // 입력 범위 1,000,000 -> gcd 최대 1,000,000
    // sum = 4,950,000,000 -> int 범위 초과
    long long sum = 0;

    // 10, 20, 30, 40
    // (10, 20) (10, 30) (10, 40)
    // (20, 30) (20, 40)
    // (30, 40)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            sum += gcd(max(v[i], v[j]), min(v[i], v[j]));
        }
    }
    return sum;
}

int main() {
    int t, n;

    // 입력
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        // 연산 & 출력
        cout << getSum(n, v) << "\n";
    }
}