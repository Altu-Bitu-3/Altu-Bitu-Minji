//
// Created by KangMinji on 2022-10-31.
//

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
const int MAX = 51;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
bool ground[MAX][MAX];
bool visited[MAX][MAX];

int m, n;

void dfs(int y, int x) {
    visited[y][x] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 밭 범위 제한
        if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
            continue;
        }

        // 탐색 지속 : 방문 X & 배추 존재
        if (ground[ny][nx] && !visited[ny][nx]){
            dfs(ny, nx);
        }
    }
}

// 인접 그래프 개수 찾기
int main() {
    int t, k, x, y;

    cin >> t;
    while (t--) {
        cin >> m >> n >> k;

        // 🔥 초기화 : https://code-kh-studio.tistory.com/5
        memset(ground, 0, sizeof(ground));
        memset(visited, 0, sizeof(visited));

        while (k--) {
            cin >> x >> y;
            ground[y][x] = 1;
        }

        int ans = 0; // 배추흰지렁이 수
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (ground[i][j] && !visited[i][j]) {
                    ans++;
                    dfs(i, j);
                }
            }
        }
        cout << ans << "\n";
    }
}