//
// Created by KangMinji on 2022-10-05.
//

#include <iostream>
#include <vector>

using namespace std;

bool isEmpty(vector<int> &heap) {
    // 사이즈가 1인 경우 empty
    return heap.size() == 1;
}

void push(vector<int> &heap, int x) {
    // heap에 x 삽입
    // 0. 현재 힙의 크기 = 새로 push할 데이터의 초기 인덱스
    int idx = heap.size();

    // 1. 힙의 마지막 자리에 x 삽입
    heap.push_back(x);

    // 부모 노드와 비교하면서 바꾸기 진행
    while (idx > 1 && heap[idx] > heap[idx / 2]) {
        swap(heap[idx], heap[idx / 2]);
        idx /= 2; // 현재 x가 위치한 인덱스
    }
    return;
}

int pop(vector<int> &heap) {
    // 1. root 노드 값을 복사
    int item = heap[1];

    // 2. 마지막 index를 root 노드에 넣어주기
    heap[1] = heap[heap.size() - 1];

    // 3. 맨 뒤의 자식 제거
    heap.pop_back();

    // 4. root 노드였던 것을 알맞은 위치에 배치
    int size = heap.size();
    int parent = 1, child = 2; // child = 왼쪽 자식

    // (왼쪽) 자식 노드가 존재하는 동안 비교 진행
    while (child < size) {
        // 오른쪽 자식 노드가 존재한다면, 둘 중에 큰 쪽을 선택
        if (child + 1 < size && heap[child + 1] > heap[child]) {
            child += 1; // 오른쪽 자식 선택
        }

        // 부모 노드가 자식 노드보다 값이 작은 경우 swap
        if (heap[parent] < heap[child]) {
            swap(heap[parent], heap[child]);
            parent = child;
            child = parent * 2;
        } else { // 한 번 못 바꾸면 계속 못 바꿈 -> break;
            break;
        }
    }

    return item;
}

int main() {
    int n, x;

    // 입력
    cin >> n;

    // heap 초기화
    vector<int> heap_vec;
    heap_vec.push_back(0);

    while (n--) {
        cin >> x;
        if (x == 0) {
            // 가장 큰 값 출력하고 제거
            // 비었다면 0 출력
            if (isEmpty(heap_vec)) {
                cout << "0\n";
            } else {
                cout << pop(heap_vec) << "\n";
            }
        } else {
            // 최대 힙에 x 삽입
            push(heap_vec, x);
        }
    }
}