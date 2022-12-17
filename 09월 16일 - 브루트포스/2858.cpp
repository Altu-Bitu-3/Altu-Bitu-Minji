//
// Created by KangMinji on 2022-09-22.
//

#include <iostream>

using namespace std;

int calcRoomSize(int r, int b) {
    // 빨간색 타일 개수 : (row-2)*(col-2)
    // 갈색 타일 개수 : 전체 - 빨간색 타일 개수 = 2(row+col)-4
    // 전체 타일 개수 : row * col

    // row가 col보다 같거나 커야 함 -> i >= j
    for (int i = 3;; i++) {
        for (int j = i; j >= 3; j--) {
            int brown = (i - 2) * (j - 2);
            int red = i * j - brown;
            if (r == red && b == brown) {
                cout << i << " " << j;
                return 0;
            }
        }
    }
}

int main() {
    int r, b;

    // 입력
    cin >> r >> b;

    // 연산 & 출력
    calcRoomSize(r, b);

}