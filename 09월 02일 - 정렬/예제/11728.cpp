//
// Created by KangMinji on 2022-09-03.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> a, b, result;

void mergeSort(int n, int m) {
    int idx = 0, a_ptr = 0, b_ptr = 0;

    while (a_ptr < n && b_ptr < m) {
        if (a[a_ptr] <= b[b_ptr])
            result[idx++] = a[a_ptr++];
        else
            result[idx++] = b[b_ptr++];
    }

    while (a_ptr < n)
        result[idx++] = a[a_ptr++];

    while (b_ptr < m)
        result[idx++] = b[b_ptr++];
}

int main() {
    // 시간초과
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    // 입력
    cin >> n >> m;
    a.assign(n, 0);
    b.assign(m, 0);
    result.assign(n + m, 0);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < m; i++)
        cin >> b[i];

    // 연산
    mergeSort(n, m);

    // 출력
    for (int i = 0; i < n + m; i++)
        cout << result[i] << " ";
}
