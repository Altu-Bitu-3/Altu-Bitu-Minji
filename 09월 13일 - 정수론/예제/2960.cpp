//
// Created by KangMinji on 2022-09-14.
//

#include <iostream>
#include <vector>
using namespace std;

int findPrime(int n, int k){
    vector<bool> is_prime(n+1, true);
    // 0과 1은 소수가 아니므로 false
    is_prime[0] = is_prime[1] = false;

    // 몇 개의 수를 지웠는지 확인
    int cnt = 0;
    // 소수까지 지워야 하기 때문에 i<=n까지!
    for (int i=2; i<=n; i++){
        // i가 소수인지 판단
        if (!is_prime[i])
            continue;
        // 이 문제에서는 i도 지워야 하므로 j=i
        for (int j=i; j<=n; j+=i){
            if (!is_prime[j])
                continue;
            is_prime[j] = false;
            if (++cnt == k) {
                return j;
            }
         }
    }
    return -1; // 임의 지정
}

int main() {
    int n, k;

    // 입력
    cin >> n >> k;

    // 연산 & 출력
    cout << findPrime(n, k);
}