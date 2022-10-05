//
// Created by KangMinji on 2022-10-05.
//

#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

int main() {
    int t, n, m, importance;

    // 입력
    cin >> t;
    while (t--) {
        cin >> n >> m;

        priority_queue<int> pq; // 중요도 높은 순
        queue<ci> q;            // 프린터 문서 순서 {index, importance}

        for (int i = 0; i < n; i++) {
            cin >> importance;

            pq.push(importance);
            q.push({i, importance});
        }

        // 연산 : index m인 문서가 몇 번째로 인쇄되는지 확인
        int cnt = 0; // 인쇄 순서
        while (!q.empty()) {
            // 1) 현재 큐의 가장 앞에 있는 문서의 중요도 확인 : 일단 문서 pop
            int idx = q.front().first;
            int importance = q.front().second;
            q.pop();

            // 2) 다른 문서의 중요도 확인
            // 2-1) 현재 문서보다 중요도가 높은 문서가 있는 경우 : 큐의 가장 뒤에 재배치
            if (importance != pq.top()) {
                q.push({idx, importance});
            }
            // 2-2) 현재 문서가 가장 중요도가 높은 경우 : 인쇄
            else {
                pq.pop();
                cnt++;      // [!] 인쇄 순서이므로 인쇄하는 경우에만 cnt값 증가 https://artiper.tistory.com/72
                // 3) 궁금한 문서인 경우 cnt 출력
                if (idx == m) {
                    break;
                }
            }
//            cnt++;
        }

        // 출력
        cout << cnt << "\n";
    }
}