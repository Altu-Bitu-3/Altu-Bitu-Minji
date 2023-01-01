//
// Created by KangMinji on 2022-09-19.
//

#include <iostream>
using namespace std;

int findGCD(int a, int b){
    if (b == 0) {
        return a;
    }
    return findGCD(b, a%b);
}

int main() {
    string input;

    // 입력
    cin >> input;

    // 연산
    int idx = input.find(":");
    int a = stoi(input.substr(0, idx)); // 분모
    int b = stoi(input.substr(idx+1, -1)); // 분자

    int gcd = findGCD(max(a, b), min(a, b));
    cout << a/gcd << ":" << b/gcd << "\n";

}