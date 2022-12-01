//
// Created by KangMinji on 2022-11-29.
//

#include<iostream>
#include<vector>
using namespace std;
#define N 19

int board[20][20]; // 바둑판

bool check(int y, int x, int dy, int dx) {
    //가려는 반대 방향의 색깔이 같다면 이미 체크한 것이므로 패스
    int nx = x - dx; int ny = y - dy; // 다음 좌표

    // 다음 좌표가 보드 범위 내에 있는 경우
    if (0 < ny <= 20 && 0 < nx <= 20) {
        // 가려는 반대 방향의 색깔이 같은 경우 - 이미 체크한 것
        if (board[y][x] == board[ny][nx]) {
            return false; // 취소
        }
    }

    //5개 연속인지 확인
    nx = x; ny = y;
    // 해당 방향으로 4번 올라감
    for (int d = 0; d < 4; d++) {
        nx += dx;	ny += dy;
        // 좌표가 보드 범위 안에 있다면
        if (0 < ny <= 20 && 0 < nx <= 20) {
            // 색깔이 다른 경우 연속되지 않음 - 오목 아님
            if (board[y][x] != board[ny][nx]) {
                return false;
            }
        }
    }
    // 6개 이상 연속인 경우
    nx += dx; ny += dy;
    // 좌표가 보드 범위 안에 있다면
    if (0 < ny <= 20 && 0 < nx <= 20) {
        // 색깔이 같은 경우 -> 6개 이상 연속이라는 뜻 - 오목 아님
        if (board[y][x] == board[ny][nx]) {
            return false;
        }
    }
    // 오목인 경우만 남음
    return true;
}

// 오목인지 확인
bool checkFive(int idx1, int idx2) {
    //오른쪽
    if (check(idx1, idx2, 0, 1)) {
        return true;
    }
    //아래
    if (check(idx1, idx2, 1, 0)) {
        return true;
    }
    //오른쪽아래 대각선
    if (check(idx1, idx2, 1, 1)) {
        return true;
    }
    //오른쪽 위 대각선
    if (check(idx1, idx2, -1, 1)) {
        return true;
    }
    return false;
}

/*
 * 연속적으로 5알 -> 그 색이 이김
 * 연속적으로 6알 이상 -> 이긴 것이 아님
 */
int main() {
    bool res; // 오목 여부 체크

    //입력 : n*n의 board만큼 입력받음
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
        }
    }
    //오목 체크 - 왼쪽 위부터 체크한다 (출력조건 때문)
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            // board에 존재하면
            if (board[i][j]) {
                // 연속으로 5알인지 확인(오목인지 확인)
                res = checkFive(i, j);
                // 오목인 경우
                if (res) {
                    // 가장 왼쪽에 있는 바둑알의 가로, 세로줄 번호 출력
                    cout << board[i][j] << '\n';
                    cout << i << ' ' << j << '\n';
                    return 0;
                }
            }
        }
    }
    //승부가 결정되지 않은 경우
    cout << "0";
}