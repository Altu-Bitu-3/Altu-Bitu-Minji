//
// Created by KangMinji on 2022-09-14.
//

#include <iostream>
using namespace std;

// 유클리드 호제법으로 최대공약수 구하기
int gcdRecursion(int a, int b) {
    // a > b일 때, a와 b의 최대공약수를 리턴
    if (b == 0) {
        return a;
    }
    return gcdRecursion(b, (a % b));
}

int main() {
    int a, b;

    // 입력
    cin >> a >> b;

    // 연산
    // 최대공약수
    int g = gcdRecursion(max(a, b), min(a, b));
    // 최소공배수
    int l = a * b / g;

    // 출력
    cout << g << "\n" << l << "\n";

    return 0;
}