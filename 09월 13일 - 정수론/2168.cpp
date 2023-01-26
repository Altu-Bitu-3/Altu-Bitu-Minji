//
// Created by KangMinji on 2022-09-19.
//

#include <iostream>

using namespace std;
typedef long long ll;

ll findGCD(ll x, ll y) {
    if (y == 0)
        return x;
    return findGCD(y, x % y);
}

int main() {
    ll x, y;

    // 입력
    cin >> x >> y;

    // 연산
    ll gcd = findGCD(x, y);
    if (gcd > 1) { // 교차점을 지남
        cout << x + y - gcd << "\n";
    } else {
        cout << x + y - 1 << "\n";
    }
}