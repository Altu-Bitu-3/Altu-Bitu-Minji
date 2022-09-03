//
// Created by KangMinji on 2022-09-03.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

void bubbleSort(int n) {
    for (int i = 0; i < n - 1; i++) { // 전체 회전 수 : n-1번
        // advanced bubble sort
        int is_swap = false;

        // 0 ~ n-1 > 0 ~ n-2 > 0 ~ 1까지 정렬
        for (int j = 0; j < n - 1 - i; j++) { // 각 회전 당 비교 횟수 : n-1번, n-2번, ... 1번
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                is_swap = true;
            }
        }

        if (!is_swap)
            break;
    }
}

int main() {
    int n;

    // 입력
    cin >> n;
    arr.assign(n, 0);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // 연산
    bubbleSort(n);

    // 출력
    for (int i = 0; i < n; i++)
        cout << arr[i] << "\n";
}