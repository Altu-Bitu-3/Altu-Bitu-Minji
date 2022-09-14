//
// Created by KangMinji on 2022-09-15.
//

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    queue<int> q;

    // 입력
    cin >> n;
    for (int i=1; i<=n; i++){
        q.push(i);
    }

    // 연산
    while(q.size() != 1){
        q.pop();
        int card = q.front();
        q.pop();
        q.push(card);
    }
    cout << q.front();
}