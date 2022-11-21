//
// Created by KangMinji on 2022-11-21.
//

#include <iostream>
#include <vector>
using namespace std;

string checkQuest(int t, int k, vector<vector<int>> &tree){
    // 1) k번 정점이 단절점인가?
    // -> 말단 노드 아니면 단절점 가능
    if (t == 1 && tree[k].size() >= 2){
        return "yes";
    }
    // 2) k번째 간선이 단절선인가?
    // -> 주어지는 그래프는 무조건 트리이므로 모든 간선은 단절선 가능
    if (t == 2){
        return "yes";
    }
    return "no";
}

int main() {
    // 시간 초과
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b, q, t, k;

    // 입력
    cin >> n;
    vector<vector<int>> tree(n+1, vector<int>(0));
    for (int i=0; i<n-1; i++){
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    cin >> q;
    while(q--){
        cin >> t >> k;
        cout << checkQuest(t, k, tree) << "\n";
    }
}