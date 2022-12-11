//
// Created by KangMinji on 2022-09-26.
//

#include <iostream>
#include <stack>
using namespace std;

string pwToString(stack<char> &left, stack<char> &right){
    string password = "";
    // left : reverse된 상태, right : 정상적으로 정렬
    // 1) left를 right로 옮겨줌(이 과정에서 reverse)
    while (!left.empty()){
        right.push(left.top());
        left.pop();
    }
    // 2) right에 있는 것을 password에 추가
    while (!right.empty()) {
        password += right.top();
        right.pop();
    }
    return password;
}

string findPassword(string s){

    stack<char> left;
    stack<char> right;

    for (int i=0; i<s.length(); i++){
        switch(s[i]) {
            case '-':
                if (!left.empty()){
                    left.pop();
                }
                break;
            case '<': // 커서 왼쪽으로 이동
                if (!left.empty()){
                    right.push(left.top());
                    left.pop();
                }
                break;
            case '>': // 커서 오른쪽으로 이동
                if (!right.empty()){
                    left.push(right.top());
                    right.pop();
                }
                break;
            default : // 문자의 경우 입력을 하면 커서보다 [왼쪽]에 위치
                left.push(s[i]);
        }
    }
    string password = pwToString(left, right);
    return password;
}

int main() {
    int n;
    string s;

    // 입력
    cin >> n;
    while(n--) {
        cin >> s;
        cout << findPassword(s) << "\n";
    }
}