//
// Created by KangMinji on 2022-09-15.
//

#include <iostream>
#include <stack>

using namespace std;

int calcBalance(string &input) {
    stack<char> st;
    int cnt = 0;

    for (int i = 0; i < input.length(); i++) {
        char c = input[i];
        switch (c) {
            case '{':
                st.push(c);
                break;
            case '}':
                // 1) 불안정한 괄호 생성 -> 스택에 넣기
                if (st.empty() || st.top() != '{') {
                    st.push(c);
                    break;
                }
                // 2) 안정적인 괄호 생성 -> 스택에서 상대 괄호 제거
                st.pop();
                break;
        }
    }

    // 불안정한 괄호들 바꾸기(짝수로 생각)
    // 1) 괄호의 종료 다른 경우 }{ -> 2번 연산
    // 2) 괄호의 종류 같은 경우 {{ -> 1번 연산
    while (!st.empty()) {
        char first = st.top();
        st.pop();
        char second = st.top();
        st.pop();

        if (first == second) {
            cnt++;
        } else {
            cnt += 2;
        }
    }

    return cnt;
}

int main() {
    string input;
    int calc_num, test_no = 1;

    // 입력
    while (getline(cin, input)) {
//        if (input.find('-')) // 입력 종료 조건 -> 그냥 다 종료됨
//            break;
        if (input[0] == '-')
            break;

        calc_num = calcBalance(input);
        cout << test_no++ << ". " << calc_num << "\n";
    }
}