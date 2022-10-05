//
// Created by KangMinji on 2022-10-05.
//

#include <iostream>
#include <queue>
using namespace std;

struct cmp {
    bool operator() (const long long &x1, const long long &x2){
        // 오름차순 정렬
        return x2 < x1;
    }
};

int main() {

    int n;
    long long x;

    // 입출력 시간
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    cin >> n;
    priority_queue<long long, vector<long long>, cmp> pq;

    // 1) 일단 n개 입력받기(오름차순) - root -> n번째로 큰 수가 됨
    for (int i=0; i<n; i++) {
        cin >> x;
        pq.push(x);
    }

    // 2) 새로 들어온 수가 root보다 크면 pop하고 삽입
    for (int i=0; i<n*(n-1); i++) {
        cin >> x;
        if (x > pq.top()) {
            pq.pop();
            pq.push(x);
        }
    }

    // 3) root 출력
    cout << pq.top() << "\n";
}