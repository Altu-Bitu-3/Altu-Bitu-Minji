//
// Created by KangMinji on 2022-09-14.
//

#include <iostream>
#include <vector>

using namespace std;

const int MAX = 5e6; // 5 * 10^6;

vector<int> isPrime() {
    // n 이하의 수를 소인수분해하는 경로를 리턴
    vector<int> prime(MAX + 1, 0);
    for (int i = 2; i * i <= MAX; i++) {
        // 소수가 아니면
        if (prime[i] != 0)
            continue;

        // i가 소수라면
        for (int j = i * i; j <= MAX; j += i) {
            if (prime[j] == 0) { // 아직 안 지워짐
                prime[j] = i;
            }
        }
    }
    return prime;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    // 입력
    cin >> n;

    // 연산(소수 경로 구하기)
    auto prime = isPrime();

    while (n--) {
        int k;
        cin >> k;

        // prime[k] != 0이면 소수가 아님 -> 소인수분해
        while (prime[k] != 0) {
            cout << prime[k] << ' ';
            k /= prime[k];
        }
        // k가 소수
        cout << k << '\n';
    }
}