//
// Created by KangMinji on 2022-09-24.
//

#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 8;

int n, m;
vector<int> num(SIZE, 0);

// cnt : 수열 인덱스, start : 현재 탐색 시작하는 원소의 값
void backtracking(int cnt, int start) {
    if (cnt == m) { // m개 수 고름(기저 조건)
        for (int i = 0; i < cnt; i++) {
            cout << num[i] << ' ';
        }
        cout << '\n';
        return;
    }
    // start : 가지치기의 역할
    for (int i = start; i <= n; i++) { // i : 고르려는 수
        num[cnt] = i;
        backtracking(cnt + 1, i + 1);
    }
}

int main() {
    // 입력
    cin >> n >> m;

    // 연산 & 출력
    backtracking(0, 1);
}