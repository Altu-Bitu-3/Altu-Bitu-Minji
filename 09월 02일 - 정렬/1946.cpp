//
// Created by KangMinji on 2022-09-07.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;

/*
 * 서류 1등은 무조건 합격
 * 나머지 사람들은 서류 1등의 면접 등수보다 낮아야 합격
 */
int findMaxEmployee(int n, vector<ci> &employee) {
    // 서류 등수 오름차순 정렬
    sort(employee.begin(), employee.end());

    // 서류 1등의 정보
    int max_grade = employee[0].second;
    int cnt = 1;

    // 나머지 사람들 중 합격자 추리기
    for (int i = 1; i < n; i++) {
        if (employee[i].second < max_grade) {
            cnt++;
            max_grade = employee[i].second; // 추가 비교
        }
    }
    return cnt;
}

int main() {
    int t, n;
    vector<ci> employee;

    // 입력
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        employee.assign(n, {0, 0});
        for (int j = 0; j < n; j++) {
            cin >> employee[j].first >> employee[j].second;
        }
        // 연산 & 출력
        cout << findMaxEmployee(n, employee) << "\n";
    }
}