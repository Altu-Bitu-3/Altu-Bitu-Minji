//
// Created by KangMinji on 2022-09-26.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * 1) 중복 없는 글자
 * 2) 바퀴는 시계방향 회전 -> 화살표는 반시계방향 회전
 * => 출력 시 방향을 바꿔서 출력해야 함
 * 3) 바퀴 k번 회전 시 글자가 변하는 횟수 s, 멈춘 글자 c
 */

bool checkWheel(vector<char> &arr, int idx, char c) {
    // 1) 해당 자리에 동일한 글자가 있는 경우
    if (arr[idx] == c){
        return true;
    }
    // 2) 해당 자리에 ?이 있는 경우
    if (arr[idx] == '?') {
        // 다른 자리에 동일한 글자가 있을 경우 false 리턴(중복)
        if (find(arr.begin(), arr.end(), c) != arr.end()){
            return false;
        }
        arr[idx] = c;
        return true;
    }
    // 3) 해당 자리에 ?이 아닌 다른 글자가 있는 경우
    return false;
}

int main() {
    int n, k, s;
    char c;

    // 입력
    cin >> n >> k;

    // 연산
    int idx = 0;
    vector<char> arr(n, '?');
    while (k--) {
        // 1) 바퀴의 모든 칸이 결정되지 않았으므로 ?로 채우기
        cin >> s >> c;
        // 2) 화살표의 인덱스 결정
        idx = (idx + s) % n;
        // 3) 글자 확인
        if (!checkWheel(arr, idx, c)){
            cout << "!";
            return 0;
        }
    }
    // 4) 출력 : 마지막 회전에서 화살표가 가리키는 문자부터 시계방향으로 출력
    // 시작 : idx, 방향 : 반시계방향(i--)
    for (int i=idx; i>=0; i--){
        cout << arr[i] << ' ';
    }
    for (int i=n-1; i>idx; i--){
        cout << arr[i] << ' ';
    }

}