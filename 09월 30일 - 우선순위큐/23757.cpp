//
// Created by KangMinji on 2022-10-05.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int checkPresentAvailable(priority_queue<int, vector<int>, cmp> &present,
                        vector<int> &child){
    for (int i=0; i<child.size(); i++) {
        // 각자의 max를 비교
        // 1) 선물 가져갈 수 있는 경우
        int item = present.top();
        if (item >= child[i]){
            // 해당 노드의 값 변경
            present.pop();
            present.push(item - child[i]);
        }
        // 2) 선물 가져갈 수 없는 경우
        else {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n, m, x;

    // 입력
   cin >> n >> m;
   priority_queue<int, vector<int>, cmp> present;
   vector<int> child(m, 0);

   for (int i=0; i<n; i++){
       cin >> x;
       present.push(x);
   }

   // [!] 아이들은 순서대로 가져감 -> 내림차순 정렬하면 안 됨
   for (int i=0; i<m; i++){
       cin >> child[i];
   }

   // 연산
   cout << checkPresentAvailable(present, child);
}