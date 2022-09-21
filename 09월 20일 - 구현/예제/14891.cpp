//
// Created by KangMinji on 2022-09-21.
//

/*
 * 문제에 나와있는대로 구현
 * -> 선 결정 후 회전
 *
 * 1. 톱니바퀴가 회전할 방향을 결정
 * 2. 결정된 방향으로 회전
 */

#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
using namespace std;

const int R = 2; // 오른쪽 톱니가 2번 인덱스
const int L = 6; // 왼쪽 톱니가 6번 인덱스

deque<int> wheel[5]; // 톱니바퀴 상태 저장
vector<int> rotation(5, 0); // 회전 방향 저장 1 : 시계, -1 : 반시계, 0 : 회전 없음

int calcScore() {
    int answer = 0;
    for (int i=1; i<=4; i++){
        // N극이면 0점, S극이면 1점
        answer += pow(2, i-1) * wheel[i][0];
    }
    return answer;
}

void rotate() {
    // 결정된 회전 정보로 회전
    for (int i=1; i<=4; i++){
        // 시계방향으로 회전하는 경우
        // ex) 10101111 -> 11010111
        if (rotation[i] == 1) {
            int temp = wheel[i].back();
            wheel[i].pop_back();
            wheel[i].push_front(temp);
        }
        // 반시계방향으로 회전하는 경우
        if (rotation[i] == -1) {
            int temp = wheel[i].front();
            wheel[i].pop_front();
            wheel[i].push_back(temp);
        }
    }
}

void decideRotation(int num, int rot) { // 몇 번 바퀴를 어느 방향으로
    // 탈출 조건
    if (rotation[num] != 0) { // 이미 회전을 거친 경우
        return;
    }

    // 회전방향 결정 : num 톱니바퀴를 rot 방향으로 회전
    rotation[num] = rot;

    // 오른쪽 바퀴
    if (num < 4 && wheel[num][R] != wheel[num + 1][L]) {
        decideRotation(num + 1, -rot);
    }

    // 왼쪽 바퀴
    if (num > 1 && wheel[num][L] != wheel[num-1][R]) {
        decideRotation(num-1, -rot);
    }
}

int main() {
    string temp;
    for (int i = 1; i <= 4; i++) {
        cin >> temp;
        for (int j = 0; j < 8; j++) {
            wheel[i].push_back(temp[j] - '0'); // 정수형으로 처리
        }
    }

    int n, num, rot;
    cin >> n;

    while (n--) {
        cin >> num >> rot;
        rotation.assign(5, 0);
        // 회전 방향 결정
        decideRotation(num, rot);
        // 회전하기
        rotate();
    }

    // 점수 계산하기
    cout << calcScore();

}