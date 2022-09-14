//
// Created by KangMinji on 2022-09-15.
//

#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, k;
    queue<int> q;

    // 입력
    cin >> n >> k;

    // 연산
    // 1) 큐 초기화
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    cout << "<";
    // 2) k번째 사람 삭제
    while (!q.empty()) {
        // 2-1) k번째 사람 나올 때까지 큐 돌리기
        for (int i = 0; i < k - 1; i++) {
            int people = q.front();
            q.pop();
            q.push(people);
        }
        // 2-2) k번째 사람 삭제
        cout << q.front();
        if (q.size() != 1) // 출력 조건 맞추기
            cout << ", ";
        q.pop();
    }
    cout << ">";
}