//
// Created by KangMinji on 2022-09-21.
//

#include <iostream>

using namespace std;

// 제한 사항 : 1<=n<=10,000
// 666부터 차례로 666이 수에 있는지 판단 -> 10,000번째 종말의 숫자는 6,666,999보다 작음
// 6,666,999 < 1억이므로 충분히 브루트 포스 가능
int getEndNumber(int n){
    // n번째 종말의 수를 찾는 함수
    int num = 666 - 1;

    while(n > 0) {
        string s = to_string(++num);
        if (s.find("666") != s.npos) {
            n--;
        }
    }
    return num;
}

int main() {
    int n;

    // 입력
    cin >> n;

    // 출력
    cout << getEndNumber(n);
}