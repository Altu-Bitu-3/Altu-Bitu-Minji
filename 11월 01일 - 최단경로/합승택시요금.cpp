//
// Created by KangMinji on 2022-11-12.
//

#include <string>
#include <vector>
const int INF = 1e7 * 2; // 최대 n-1개의 간선
using namespace std;

void floydWarShall(vector<vector<int>> &graph, int edge){
    // 정점 i, j 사이의 모든 경유지(k)를 탐색하여 최단 경로 찾아냄
    for (int k=1; k<=edge; k++){
        for (int i=1; i<=edge; i++){
            for (int j=1; j<=edge; j++){
                graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
            }
        }
    }
}

// 모든 정점 사이의 최단거리 : 플로이드 워샬
// dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j])
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;

    // 그래프 초기화
    vector<vector<int>> graph(n+1, vector<int>(n+1, INF)); // 양방향
    for (int i=1; i<=n; i++)
        graph[i][i] = 0;
    for (int i=0; i<fares.size(); i++){
        graph[fares[i][0]][fares[i][1]] = fares[i][2];
        graph[fares[i][1]][fares[i][0]] = fares[i][2];
    }

    floydWarShall(graph, n);
    for (int i=1; i<=n; i++){
        answer = min(answer, graph[s][i] + graph[i][a] + graph[i][b]);
    }

    return answer;
}