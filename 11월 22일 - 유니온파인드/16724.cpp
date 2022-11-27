//
// Created by KangMinji on 2022-11-28.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

int findParent(int node) {
    if (parent[node] < 0) // 루트 정점
        return node;
    // 루트 정점이 아닌 경우 -> 루트 정점 찾기
    return parent[node] = findParent(parent[node]);
}

bool unionInput(int x, int y) {
    int xp = findParent(x);
    int yp = findParent(y);

    // 1) 같은 집합에 있는 경우 유니온할 수 없음
    if (xp == yp) {
        return false;
    }

    // 2) 새로운 루트 xp가 있는 경우
    if (parent[xp] < parent[yp]) {
        parent[xp] += parent[yp];
        parent[yp] = xp;
    }

    // 3) 새로운 루트 yp가 있는 경우
    else {
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }

    // 1) 빼고는 유니온 가능함
    return true;
}

/*
 * 사이클이 언제 생겼는지 알기 위해서는 매번 사이클 발생 여부를 확인해야 한다!
 * -> 입력 받으면서 하나씩 확인
 */
int main() {
    int n, m, x, y;

    // 입력
    cin >> n >> m;
    parent.assign(n, -1);

    for (int i = 0; i < m; i++) {
        cin >> x >> y;

        // 연산 & 출력
        if (!unionInput(x, y)) { // 유니온할 수 없는 경우(사이클 생성)
            cout << i + 1;
            return 0;
        }
    }
    cout << 0;
}