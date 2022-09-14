//
// Created by KangMinji on 2022-09-15.
//

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, num;
    string order;
    queue<int> q;

    // 입력
    cin >> n;
    while(n--){
        cin >> order;
        if (order == "push"){
            cin >> num;
            q.push(num);
            continue;
        } if (order == "pop") {
            if (q.empty())
                cout << -1 << "\n";
            else {
                cout << q.front() << "\n";
                q.pop();
            }
            continue;
        } if (order == "size") {
            cout << q.size() << "\n";
            continue;
        } if (order == "empty") {
            if (q.empty())
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
            continue;
        }
        if (order == "front") {
            if (q.empty())
                cout << -1 << "\n";
            else
                cout << q.front() << "\n";
            continue;
        } if (order == "back") {
            if (q.empty())
                cout << -1 << "\n";
            else
                cout << q.back() << "\n";
        }
    }
}