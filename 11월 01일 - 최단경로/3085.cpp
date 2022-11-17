//
// Created by KangMinji on 2022-11-12.
//

#include <iostream>
#include <vector>

using namespace std;

// 🔥 {-1, 1}이 아니라 {0, 1} https://velog.io/@yoonah-dev/3085%EB%B2%88-%EC%82%AC%ED%83%95-%EA%B2%8C%EC%9E%84c
int dx[2] = {0, 1};
int dy[2] = {1, 0};
vector<vector<char>> board;
int n;

int countMaxCandy(int row, int col, int direction) {
    int max_cnt = 0, sum = 1; // 기본적으로 한 블록은 가지고 있으므로 1부터 시작
    char color = board[row][col];
//    int direction = row == 0 ? col : row; -> 둘 다 0으로 시작할 수 있으니 값 따로 지정해서 넘기기
    for (int i = 0; i < n; i++) {
        if (color == board[row][col]) {
            sum++;
        } else {
            max_cnt = max(max_cnt, sum);
            sum = 1;
            color = board[row][col];
        }
        row += dx[direction];
        col += dy[direction];
    }
    return max_cnt;
}

int countRowColCandy() {
    int max_cnt = 0;
    for (int i = 0; i < n; i++) {
        // 행의 최대 사탕 개수
        max_cnt = max(max_cnt, countMaxCandy(i, 0, 1));
        // 열의 최대 사탕 개수
        max_cnt = max(max_cnt, countMaxCandy(0, i, 0));
    }
    return max_cnt;
}

int swapCandy(int row, int col, char candy) {
    int max_eat = 0;

    // 인접한 두 칸
    for (int i = 0; i < 2; i++) {
        int nx = row + dx[i];
        int ny = col + dy[i];

        // 인접한 두 칸의 사탕 색이 다른 경우
        if (board[nx][ny] != candy && nx < n && ny < n) {
            // 1) 바꾸고
            swap(board[row][col], board[nx][ny]);
            // 2) 최대 연속 행 또는 열 확인
            max_eat = max(max_eat, countRowColCandy());
            // 3) 원상 복귀
            swap(board[row][col], board[nx][ny]);
        }
        cout << max_eat << "\n";
    }
    return max_eat;
}

int main() {
    int max_eat = 0;

    // 입력
    cin >> n;
    board.assign(n, vector<char>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    // 연산
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 사탕을 바꿔가면서 최대 연속 행/열의 사탕 개수 구하기
            max_eat = max(max_eat, swapCandy(i, j, board[i][j]));
        }
    }

    // 출력
    cout << max_eat << "\n";
}