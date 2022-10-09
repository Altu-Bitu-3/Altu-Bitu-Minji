//
// Created by KangMinji on 2022-10-05.
//

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    long long x; // 0 ~ 2^31

    // 입출력 속도
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    cin >> n;
    priority_queue<long long, vector<long long>, greater<>> pq;
    while (n--) {
        cin >> x;
        if (x > 0){
            pq.push(x);
            continue;
        }

        if (!pq.empty()){
            cout << pq.top() << "\n";
            pq.pop();
        } else {
            cout << "0\n";
        }
    }

}