//
// Created by KangMinji on 2022-10-31.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

/*
 * I : 정수 n을 Q에 삽입
 * D : 삭제(Q가 비어있는 경우는 무시)
 * D 1 : Q에서 최댓값 삭제(둘 이상이면 하나만 삭제)
 * D -1 : Q에서 최솟갑 삭제(둘 이상이면 하나만 삭제)
 */

vector<bool> is_valid;

void deleteMax(priority_queue<ci, vector<ci>> &heap) {
    while (!heap.empty() && !is_valid[heap.top().second]) {
        heap.pop();
    }
}

void deleteMin(priority_queue<ci, vector<ci>, greater<>> &heap) {
    while (!heap.empty() && !is_valid[heap.top().second]) {
        heap.pop();
    }
}

int main() {
    int t, k, n;
    char op;

    cin >> t;

    while (t--) {
        cin >> k;

        // {값, valid 여부}
        priority_queue<ci, vector<ci>> max_heap;
        priority_queue<ci, vector<ci>, greater<>> min_heap;
        int idx = 0; // 순위

        while (k--) {
            cin >> op >> n;
            if (op == 'I') {
                min_heap.push({n, idx});
                max_heap.push({n, idx});
                is_valid.push_back(true);
                idx++;
            } else if (op == 'D') {
                // 최댓값 삭제
                if (n == 1) {
                    deleteMax(max_heap);
                    if (!max_heap.empty()) {
                        is_valid[max_heap.top().second] = false;
                        max_heap.pop();
                    }
                }
                    // 최솟값 삭제
                else if (n == -1) {
                    deleteMin(min_heap);
                    if (!min_heap.empty()) {
                        is_valid[min_heap.top().second] = false;
                        min_heap.pop();
                    }
                }
            }
        }
        deleteMax(max_heap);
        deleteMin(min_heap);

        // 출력
        if (max_heap.empty()) {
            cout << "EMPTY\n";
        } else {
            cout << max_heap.top().first << " " << min_heap.top().first << "\n";
        }
        is_valid.clear(); // 벡터 초기화
    }
}