//
// Created by KangMinji on 2022-10-05.
//

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, x;

    // 시간 초과
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    cin >> n;
    priority_queue<int> q;
    while(n--) {
        cin >> x;
        if (x == 0){
            // 가장 큰 값 출력하고 제거
            // 비었다면 0 출력
            if (!q.empty()){
                cout << q.top() << "\n";
                q.pop();
            } else {
                cout << "0\n";
            }
        } else {
            // 최대 힙에 x 삽입
            q.push(x);
        }
    }
}