//
// Created by KangMinji on 2022-10-31.
//

#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100000;

int findLen(vector<int> &arr, int n, int k) {
    vector<int> cnt(MAX + 1, 0); //각 원소 등장 횟수

    int ans = 0, left = 0, right = 0;

    while (left <= right && right < n) {
        // 현재 right가 가리키는 원소를 포함해도 등장 횟수가 k번 이하인 경우
        if (cnt[arr[right]] + 1 <= k) {
            cnt[arr[right]]++;
            ans = max(ans, (right - left) + 1);
            right++;
        }
        // 현재 right가 가리키는 원소를 포함하면 등장 횟수가 k번을 초과하는 경우
        else {
            cnt[arr[left]]--;
            left++;
        }
    }
    return ans;
}

int main() {
    int n, k;

    // 입력
    cin >> n >> k;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // 연산 & 출력
    cout << findLen(arr, n, k);
}