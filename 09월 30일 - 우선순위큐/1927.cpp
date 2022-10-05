//
// Created by KangMinji on 2022-10-05.
//

#include <iostream>
#include <queue>
using namespace std;

struct cmp {
    bool operator() (const long long &x1, const long long &x2) {
        return x2 < x1;
    }
};

int main() {
    int n;
    long long x; // 0 ~ 2^31

    // 입출력 속도
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    cin >> n;
    priority_queue<long long, vector<long long>, cmp> pq;
    while (n--) {
        cin >> x;
        if (x > 0){
            pq.push(x);
        } else if (x == 0){
            if (pq.empty()) {
                cout << "0\n";
            }
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }

}