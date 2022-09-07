//
// Created by KangMinji on 2022-09-07.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;

bool cmp(const ci &a, const ci &b) {
    // 1) y좌표가 증가하는 순으로
    if (a.second != b.second)
        return a.second < b.second;
    // 2) x 좌표가 증가하는 순으로
    return a.first < b.first;
}

int main() {
    int n;
    vector<ci> grid;

    // 입력
    cin >> n;
    grid.assign(n, {0, 0});
    for (int i = 0; i < n; i++)
        cin >> grid[i].first >> grid[i].second;

    // 연산
    sort(grid.begin(), grid.end(), cmp);

    // 출력
    for (int i = 0; i < n; i++)
        cout << grid[i].first << " " << grid[i].second << "\n";
}