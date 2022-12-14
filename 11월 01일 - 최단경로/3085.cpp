//
// Created by KangMinji on 2022-11-12.
//

#include <iostream>
#include <vector>

using namespace std;

// π₯ {-1, 1}μ΄ μλλΌ {0, 1} https://velog.io/@yoonah-dev/3085%EB%B2%88-%EC%82%AC%ED%83%95-%EA%B2%8C%EC%9E%84c
int dx[2] = {0, 1};
int dy[2] = {1, 0};
vector<vector<char>> board;
int n;

int countMaxCandy(int row, int col, int direction) {
    int max_cnt = 0, sum = 1; // κΈ°λ³Έμ μΌλ‘ ν λΈλ‘μ κ°μ§κ³  μμΌλ―λ‘ 1λΆν° μμ
    char color = board[row][col];
//    int direction = row == 0 ? col : row; -> λ λ€ 0μΌλ‘ μμν  μ μμΌλ κ° λ°λ‘ μ§μ ν΄μ λκΈ°κΈ°
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
        // νμ μ΅λ μ¬ν κ°μ
        max_cnt = max(max_cnt, countMaxCandy(i, 0, 1));
        // μ΄μ μ΅λ μ¬ν κ°μ
        max_cnt = max(max_cnt, countMaxCandy(0, i, 0));
    }
    return max_cnt;
}

int swapCandy(int row, int col, char candy) {
    int max_eat = 0;

    // μΈμ ν λ μΉΈ
    for (int i = 0; i < 2; i++) {
        int nx = row + dx[i];
        int ny = col + dy[i];

        // μΈμ ν λ μΉΈμ μ¬ν μμ΄ λ€λ₯Έ κ²½μ°
        if (board[nx][ny] != candy && nx < n && ny < n) {
            // 1) λ°κΎΈκ³ 
            swap(board[row][col], board[nx][ny]);
            // 2) μ΅λ μ°μ ν λλ μ΄ νμΈ
            max_eat = max(max_eat, countRowColCandy());
            // 3) μμ λ³΅κ·
            swap(board[row][col], board[nx][ny]);
        }
        cout << max_eat << "\n";
    }
    return max_eat;
}

int main() {
    int max_eat = 0;

    // μλ ₯
    cin >> n;
    board.assign(n, vector<char>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    // μ°μ°
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // μ¬νμ λ°κΏκ°λ©΄μ μ΅λ μ°μ ν/μ΄μ μ¬ν κ°μ κ΅¬νκΈ°
            max_eat = max(max_eat, swapCandy(i, j, board[i][j]));
        }
    }

    // μΆλ ₯
    cout << max_eat << "\n";
}