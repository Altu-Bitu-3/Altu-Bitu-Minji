//
// Created by KangMinji on 2022-09-24.
//

#include <iostream>
#include <vector>
using namespace std;
const int SIZE = 15;

int n, ans;
vector<bool> check_col(15, false);
vector<bool> check_left(SIZE * 2, false);
vector<bool> check_right(SIZE * 2, false);

void backtracking(int row) {
    // 기저조건 : n개의 퀸 모두 배치 가능
    if (row == n){
        ans++;
        return;
    }

    for (int i=0; i<n; i++){ // i : 열
        // 세로, 좌하향, 우하향 대각선 모두에 퀸이 없을 경우 -> 퀸 배치
        if (!check_col[i] && !check_left[row+i] && !check_right[row-i+n]){
            // 풀이
            check_col[i] = true;
            check_left[row +i] = true;
            check_right[row-i+n] = true;

            // 탐색
            backtracking(row + 1);

            // 초기화
            check_col[i] = false;
            check_left[row +i] = false;
            check_right[row-i+n] = false;
        }
    }
}

int main() {
    // 입력
    cin >> n;

    // 연산
    backtracking(0);

    // 출력
    cout << ans;

    return 0;
}