//
// Created by KangMinji on 2022-10-31.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;

    // 입력
    cin >> n;
    vector<int> v(n, 0);
    for (int i=0; i<n; i++){
        cin >> v[i];
    }

    // 연산
    sort(v.begin(), v.end());

    // 출력
    int ans = 0;
    int cnt = 0;
    for (int i=0; i<n; i++){
        cnt += v[i];
        ans += cnt;
    }
    cout << ans << "\n";
}