//
// Created by KangMinji on 2022-11-22.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
//행과 열을 바꿔줄 것이므로 ROW를 6으로 설정
const int ROW = 6; // 행
const int COL = 12; // 열

bool bfs(int r, int c, vector<vector<char>> &board) {
    // {상, 하, 좌, 우}
    int dr[4] = {-1, 1, 0, 0}; // row
    int dc[4] = {0, 0, -1, 1}; // col

    queue<ci> q; // bfs를 위한 큐
    queue<ci> puyo; // 포함된 좌표 저장할 큐
    vector<vector<bool>> visited(ROW, vector<bool>(COL, false)); // 방문 체크

    //시작 초기화
    q.push({r, c}); // bfs 큐에 시작 지점 넣기
    puyo.push({r, c}); // 좌표 큐에 시작 지점 넣기
    visited[r][c] = true; // 시작 지점 방문 체크

    int cnt = 1; // 모여있는 뿌요의 개수
    while (!q.empty()) { // bfs 탐색 시작
        int cr = q.front().first; // bfs 내 좌표의 row
        int cc = q.front().second; // bfs 내 좌표의 col
        q.pop(); // 좌표 제거

        // 상하좌우 돌기
        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i]; // row 업데이트
            int nc = cc + dc[i]; // col 업데이트
            // 새로운 좌표가 필드를 벗어나는 경우
            if (nr < 0 || nr >= ROW || nc < 0 || nc >= COL || visited[nr][nc]) {
                continue; // 패스
            }
            // 새로운 좌표의 뿌요가 기존 뿌요의 색깔과 같은 경우 -> 영역 확장
            if (board[nr][nc] == board[cr][cc]) {
                q.push({nr, nc}); // bfs 큐에 해당 좌표 넣기(다음 탐색을 위함)
                puyo.push({nr, nc}); // 좌표 큐에 해당 좌표 넣기(다음 탐색을 위함)
                visited[nr][nc] = true; // 해당 좌표 방문처리
                cnt++; // 모여있는 뿌요 개수 update
            }
        }
    }
    // 뿌요가 터지지 않는 경우(4개 이상이어야 터짐)
    if (cnt < 4) {
        return false; // 뿌요 안 터짐....
    }
    // 뿌요가 터지는 경우 -> 해당 뿌요들의 좌표값을 .으로 초기화
    while (!puyo.empty()) {
        int cr = puyo.front().first; // 해당 뿌요의 row값
        int cc = puyo.front().second; // 해당 뿌요의 col값
        puyo.pop(); // 좌표 큐에서 제거

        board[cr][cc] = '.'; // 좌표값 .으로 초기화
    }
    return true; // 터뜨릴 수 있으니까 true 반환
}

//뿌요를 터뜨린 이후의 새 필드를 작성하는 함수
vector<vector<char>> makeNewBoard(vector<vector<char>> &board) {
    // 필드 초기화
    vector<vector<char>> new_board(ROW, vector<char>(COL, '.'));

    // 필드 돌면서 남아있는 뿌요들 밑으로 떨어뜨림
    // row별 temp 만들어서 쌓기
    for (int i = 0; i < ROW; i++) {
        queue<char> temp; // 남아있는 뿌요 모으는 큐
        for (int j = 0; j < COL; j++) { // col 돌면서
            if (board[i][j] != '.') { // 뿌요가 남아있는 경우
                temp.push(board[i][j]); // 남은 뿌요 큐에 넣는다
            }
        }
        int index = 0; // 뿌요 높이값 저장용
        while (!temp.empty()) { // 뿌요가 남아있으면
            new_board[i][index++] = temp.front(); // 새로운 필드에 넣어주고
            temp.pop(); // 큐에서는 제거해준다
        }
    }
    return new_board; // 정돈된 뿌요 필드 리턴턴
}

int imulation(vector<vector<char>> &board) {
    int answer = 0; // 연쇄 수
    while (true) { // 더 이상 터뜨릴 수 없을 때까지 반복하기 때문에 while문 사용
        bool flag = false; //뿌요가 터졌는지 확인
        for (int i = 0; i < ROW; i++) { // 보드 행 돌기
            for (int j = 0; j < COL; j++) { // 보드 열 돌기
                // 1) 빈 칸인 경우 -> 패스한다
                if (board[i][j] == '.') {
                    continue;
                }
                // 2) 한 번이라도 뿌요가 터진 경우
                if (bfs(i, j, board)) {
                    flag = true; // 터뜨릴 수 있음을 표시
                }
            }
        }
        // 더 이상 터뜨릴 수 없는 경우 -> 종료하
        if (!flag) {
            break;
        }
        // 뿌요 터뜨리고 나서 위에 있는 뿌요 떨어뜨리기
        board = makeNewBoard(board);
        // 연쇄 수 증가
        answer++;
    }
    return answer; // 연쇄 수 리턴
}

/**
 * [Puyo Puyo] - bfs, 시뮬레이션 문제
 *
 * 1. bfs 탐색을 통해 4개 이상의 뿌요가 모였는지 확인
 * 2. 4개 이상의 뿌요가 모였다면, 해당되는 영역을 '.'으로 바꾸어 비워줌
 * 3. 전체 필드에 대해 1~2를 다 수행한 후, 뿌요를 떨어뜨림
 *    - 바닥부터 시작해서 남아있는 뿌요들을 모으고, 남은 부분은 '.'으로 채우는 방식
 * 4. 터뜨릴 수 없을 때까지 반복
 *
 * 여기서, 3번 과정을 편하게 하기 위해 12*6으로 들어오는 입력을 6*12로 바꾸어준다.
 * 같은 열에 있는 데이터를 다루는 것보다 같은 행에 있는 데이터를 다루는 것이 편하기 때문이다.
 */

int main() {
    //입력
    char input;
    vector<vector<char>> board(ROW, vector<char>(COL)); // 뿌요가 들어갈 필드
    for (int i = 0; i < COL; i++) { // [행, 열 바뀜] column 입력
        for (int j = 0; j < ROW; j++) { // [행, 열 바뀜] row 입력
            cin >> input; // 각 칸의 문자 입력
            board[j][COL - i - 1] = input; // 필드에 문자 넣기
        }
    }

    //연산 & 출력
    cout << simulation(board);
    return 0;
}