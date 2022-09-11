//
// Created by KangMinji on 2022-09-12.
//

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;
typedef pair<int, ci> vi;

bool cmp(const vi &a, const vi &b) {
    // 1) 빈도순으로 정렬
    if (a.second.first != b.second.first)
        return a.second.first > b.second.first;

    // 2) 순서순으로 정렬
    return a.second.second < b.second.second;
}

int main() {
    int n, c, num;
    map<int, ci> m;    // 숫자 : (빈도, 순서)

    // 입력
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (m[num].first == 0)
            m[num] = {1, i};
        else
            m[num].first++;
    }

    // 연산
    // [참고] 정렬을 위해 map을 vector로 변환 : https://stackoverflow.com/questions/684475/c-how-to-copy-a-map-to-a-vector
    vector<vi> v(m.begin(), m.end());
//    for (auto iter: m) {
//        v.push_back({iter.first, {iter.second.first, iter.second.second}});
//    }
    sort(v.begin(), v.end(), cmp);

    // 출력
    for (auto iter: v) {
        int frequency = iter.second.first;
        for (int i = 0; i < frequency; i++)
            cout << iter.first << " ";
    }
}