//
// Created by KangMinji on 2022-09-19.
//

#include <iostream>
#include <vector>

#define SIZE 1000000
using namespace std;

vector<bool> makePrime() {
    vector<bool> is_prime(SIZE + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= SIZE; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= SIZE; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

void checkGoldbach(int n, vector<bool> &is_prime) {
    bool flag = false;

    // is_prime = 0, 1, 2, 3(홀수 시작), 4, 5 -> 인덱스 3부터 시작
    for (int i = 3; i <= n; i++) {
        if (is_prime[i] && is_prime[n - i]) {
            flag = true;
            cout << n << " = " << i << " + " << n - i << "\n";
            break;
        }
    }
    if (!flag) {
        cout << "Goldbach's conjecture is wrong.\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    vector<bool> is_prime = makePrime();
    // 입력
    while (cin >> n) {
        if (n == 0)
            break;
        checkGoldbach(n, is_prime);
    }
}