//
// Created by KangMinji on 2022-09-15.
//

#include <iostream>
#include <map>
#include <stack>

using namespace std;

string toPostfix(string &input) {
    stack<char> st;
    string result = "";

    // 우선 순위 초기화
    map<char, int> m;
    m['+'] = m['-'] = 2;
    m['*'] = m['/'] = 1;

    for (int i = 0; i < input.length(); i++) {
        char s = input[i];
        // 1) 피연산자가 들어오면 바로 출력
        if (isupper(s)) {
            result += s;
            continue;
        }

        switch (s) {
            // 01. '('인 경우 : 스택에 넣기
            case '(':
                st.push(s);
                break;
                // 02. ')'인 경우 : '(' 나올 때까지 pop + '('도 pop
            case ')':
                while (!st.empty() && st.top() != '(') {
                    result += st.top();
                    st.pop();
                }
                st.pop(); // '(' 제거
                break;
            default : // 연산자
                // 1) 자신보다 우선 순위 높거나 같은 경우 pop
                while (!st.empty() && m[st.top()] <= m[s]) {
                    result += st.top();
                    st.pop();
                }
                // 2) 자신을 스택에 push
                st.push(s);
                break;
        }
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

int main() {
    string input;

    // 입력
    cin >> input;

    // 연산
    cout << toPostfix(input);
}