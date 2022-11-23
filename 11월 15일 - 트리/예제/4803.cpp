//
// Created by KangMinji on 2022-11-22.
//

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph; // 인접 리스트
vector<bool> visited; // 방문 체크
bool is_tree; // 트리 여부

void printResult(int tc, int tree_cnt) {
    cout << "Case " << tc << ": ";
    switch (tree_cnt) {
        case 0:
            cout << "No trees.\n";
            break;
        case 1:
            cout << "There is one tree.\n";
            break;
        default:
            cout << "A forest of " << tree_cnt << " trees.\n";
            break;
    }
}

void dfs(int curr, int prev) {
    // 트리가 아니라 사이클임!
    if (visited[curr]){
        is_tree = false;
        return;
    }
    visited[curr] = true;
    for (int next: graph[curr]){
        // 사이클 체크
        if (next == prev){
            continue;
        }
        dfs(next, curr);
    }
    return;
}

int main() {
    int n, m, a, b, tc = 0;

    // 입력
    while(cin >> n >> m){
        if (n == 0 && m == 0){
            break;
        }
        // 초기화
        tc++;
        graph.assign(n+1, vector<int>(0));
        visited.assign(n+1, false);

        while(m--){
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        // 모든 노드 방문하면서 트리 개수 세기
        int tree_cnt = 0;

        for (int i=1; i<=n; i++){
            if (visited[i]){
                continue;
            }
            is_tree = true;
            dfs(i, 0);
            // tree인 경우
            if (is_tree){
                tree_cnt++;
            }
        }
        // 출력
        printResult(tc, tree_cnt);
    }
}