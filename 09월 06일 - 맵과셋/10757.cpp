//
// Created by KangMinji on 2022-09-12.
//

#include <iostream>
#include <algorithm>

using namespace std;

string calc(string &a, string &b) {
    // 1) A를 더 긴 문자열로 지정
    if (a.length() < b.length())
        swap(a, b);

    // 2) A와 B의 문자열 길이 맞추기 : 1234 0093
    string tmp = "";
    for (int i = b.length(); i < a.length(); i++)
        tmp += "0";
    b = tmp + b;

    // 3) 끝에서부터 하나씩 더해주기
    bool carry = false; // 반올림 여부
    string ans = "";    // 정답
    int a_digit, b_digit, digit;    // a 자릿수, b 자릿수, 총합 자릿수

    // 3-1) 끝자리부터 더해주기
    for (int j = a.length() - 1; j >= 0; j--) {
        a_digit = a[j] - '0'; // char -> int
        b_digit = b[j] - '0';
        digit = a_digit + b_digit;
        // 3-2) 이전 단계에서 반올림 발생 : 자릿수 1만큼 더해주기
        if (carry) {
            digit += 1;
            carry = false;
        }
        // 3-3) 이번 단계에서 반올림 발생 : 총합 자릿수 % 10
        if (digit > 9) {
            carry = true;
            ans += to_string(digit % 10);
        }
        // 3-4) 이번 단계에서 반올림 발생 X : 총합 자릿수 그대로 반영
        else
            ans += to_string(digit);
    }
    // 4) 마지막 자리
    if (carry)
        ans += "1";

    // 5) reverse
    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {
    string a, b;

    // 입력
    cin >> a >> b;

    // 연산 & 출력
    cout << calc(a, b);
}