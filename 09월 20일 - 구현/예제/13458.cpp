//
// Created by KangMinji on 2022-09-21.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, b, c;

    // 입력
    cin >> n;
    vector<int> participant(n, 0);
    for (int i=0; i<n; i++){
        cin >> participant[i];
    }
    cin >> b >> c;

    // 연산
    /* 0. 시험장의 수, 응시자의 수가 최대 / B, C 최소
     * 1. 총 감독관은 반드시 1명
     * 2. 부감독관이 필요없는 경우 발생
     * 3. 응시자 수가 c로 나누어떨어지지 않는 경우 확인
     */

    // 시험장이 최대 1,000,000 * 응시자 수 최대 1,000,000 = 1,000,000,000,000
    // b, c가 1이라면 -> 1,000,000,000,000 -> long long
    long long answer = n;
    for (int i=0; i<n; i++){
        int count = participant[i] - b;
        if (count <= 0){
            continue;
        }
        // 남은 인원수에 맞춰 부감독관 배치
        answer += count / c;
        if (count % c != 0) {
            answer++;
        }
    }

    // 출력
    cout << answer << "\n";
}