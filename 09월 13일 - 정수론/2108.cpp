//
// Created by KangMinji on 2022-09-19.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;

bool cmp(const ci &a, const ci &b) {
    // 1) 개수 내림차순 정렬
    if (a.second != b.second)
        return a.second > b.second;
    // 2) 값 오름차순 정렬
    return a.first < b.first;
}

int findMode(int n, vector<int> &num) {
    vector<ci> count; // first : 값, second : 개수

    // 인덱스 오류 해결
    int idx = 0;
    count.push_back({num[0], 1});

    // num은 이미 오름차순으로 정렬된 배열
    // 이전 수와 다른 경우 -> 새로운 수 시작
    for (int i = 1; i < n; i++) {
        if (num[i] == num[i - 1]) {
            count[idx].second++;
        } else {
            count.push_back({num[i], 1});
            idx++;
        }
    }

    // 최빈값 정렬
    sort(count.begin(), count.end(), cmp);

    // 값의 개수가 여러 개인 경우, 두 번째로 작은 값 리턴
    if (count[0].second == count[1].second)
        return count[1].first;
    return count[0].first;
}

int main() {
    int n;
    int sum = 0;

    // 입력
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        sum += num[i];
    }

    // 연산
    sort(num.begin(), num.end());
    // 1) 산술평균
    if (round((double) sum / n) == -0){
        cout << "0\n";
    } else {
        cout << round((double) sum / n) << "\n";
    }
    // 2) 중앙값
    cout << num[n / 2] << "\n";
    // 3) 최빈값
    cout << findMode(n, num) << "\n";
    // 4) 범위
    cout << num[n - 1] - num[0];

}