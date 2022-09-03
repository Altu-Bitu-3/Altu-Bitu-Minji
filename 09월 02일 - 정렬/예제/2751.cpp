//
// Created by KangMinji on 2022-09-03.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> arr, sorted; // 수열, 임시배열

/*
 * 머지 소트의 과정
 * 1. 주어진 리스트를 두 개로 나눈다
 * 2. 나눈 리스트 두 개 각각을 정렬
 * 3. 정렬된 두 리스트를 하나로 합침
 */
void merge(int left, int mid, int right) {
    int p1 = left; // 왼쪽 배열 포인터
    int p2 = mid + 1; // 오른쪽 배열 포인터
    int k = left;

    // 1) 작은 순서대로 배열에 삽입
    while (p1 <= mid && p2 <= right) {
        if (arr[p1] < arr[p2])
            sorted[k++] = arr[p1++];
        else
            sorted[k++] = arr[p2++];
    }

    // 2) 남아있는 원소 삽입
    while (p1 <= mid) // 왼쪽 배열에 데이터 남은 경우
        sorted[k++] = arr[p1++];

    while (p2 <= right)
        sorted[k++] = arr[p2++];

    // 3) 원래 배열에 다시 복사
    for (int i = left; i <= right; i++)
        arr[i] = sorted[i];
}

void mergeSort(int left, int right) {
    if (left < right) { // 크기가 1보다 큰 경우만 고려
        int mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}

int main() {
    int n;

    // 입력
    cin >> n;
    arr.assign(n, 0);
    sorted.assign(n, 0);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // 연산
    mergeSort(0, n - 1);

    // 출력
    for (int i = 0; i < n; i++)
        cout << arr[i] << "\n";
}