//
// Created by KangMinji on 2022-10-05.
//

#include <iostream>
#include <queue>
using namespace std;

struct cmp {
    // 정렬과는 반대로 두 번째로 오는 인자가 우선순위!
    bool operator() (const int &x1, const int &x2) {
        // 1. 절댓값이 작으면 우선순위
        if (abs(x1) != abs(x2)) {
            return abs(x2) < abs(x1);
        }
        // 2. 값이 작으면 우선순위
        return x2 < x1;
    }
};

int main() {
    // 시간 초과
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;

    // 입력
    cin >> n;
    // x, container type = vector<int>
    priority_queue<int, vector<int>, cmp> pq;
    while(n--) {
        cin >> x;
        if (x != 0){
            pq.push(x);
        } else {
            if (pq.empty()){
                cout << "0\n";
            } else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }
}