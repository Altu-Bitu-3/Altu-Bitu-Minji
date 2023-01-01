//
// Created by KangMinji on 2022-09-19.
//

#include <iostream>

using namespace std;
#define IMPOSSIBLE_MESSAGE "I'm Sorry Hansoo"

/* 반복될 문자열 + 가운데 올 알파벳 + 반복될 알파벳
 * 1) 개수가 짝수면 반복 문자열에, 홀수면 가운데에 추가
 * 2) 만약 가운데 알파벳이 이미 존재한다면 팰린드롬 불가능함
 */
string toPelindrome(int alphabet[]) {
    string part1 = "", part2 = "", part3 = " ";

    for (int i = 0; i < 26; i++) {
        // 1-1) 개수가 홀수인 경우 -> 가운데에 추가
        if (alphabet[i] % 2 == 1) {
            // 2) 가운데 알파벳이 존재하는 경우
            if (part2.size() != 0) {
                return IMPOSSIBLE_MESSAGE;
            }
            part2 += (char) (i + 'A');
        }
        // 1-2) 개수가 짝수인 경우 or 홀수인데 가운데 문자열에 추가하고 짝수개 남은 경우
        for (int j = 0; j < alphabet[i] / 2; j++) {
            part1 += (char) (i + 'A');
            part3 = (char) (i + 'A') + part3;
        }
    }
    return part1 + part2 + part3;
}

int main() {
    string input;
    int alphabet[26] = {0,};

    // 입력
    cin >> input;

    // 연산
    // 1) 알파벳 종류별 개수 저장
    for (int i = 0; i < input.size(); i++) {
        alphabet[input[i] - 'A']++;
    }
    // 2) 팰린드롬으로 바꾸기
    cout << toPelindrome(alphabet);
}