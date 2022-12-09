//
// Created by KangMinji on 2022-10-31.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    int n, m; // 입국 심사대 개수, 상근이와 친구들

    // 입력
    cin >> n >> m;
    vector<long long> times(n, 0); // 🔥int 범위 아님
    for (int i = 0; i < n; i++) {
        cin >> times[i];
    }

    sort(times.begin(), times.end());

    // 최대값 : 심사 시간이 가장 긴 데스크 * 상근이와 친구들
    // 최솟값 : 0
    ll high = times.back() * m;
    ll low = 1;
    ll result = times.back() * m;

    while (low <= high) {
        ll mid = (low + high) / 2;
        ll max_people = 0; // 최대로 처리 가능한 사람 수

        for (int i = 0; i < n; i++) {
            // mid 시간 동안 시간 times[i]가 걸리는 데스크 -> mid/times[i]만 처리가능
            max_people += (mid / times[i]);
        }

        // 분리 조건 : 심사할 수 있는 사람 > 상근이의 친구들?
        if (max_people >= m) { // 심사 충분히 가능 -> 시간 줄여도 됨
            result = min(result, mid);
            high = mid - 1;
        } else { // 심사 불가능 -> 시간 늘려야 함
            low = mid + 1;
        }
    }

    cout << result << "\n";
}