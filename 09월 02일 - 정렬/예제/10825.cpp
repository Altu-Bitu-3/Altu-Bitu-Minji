//
// Created by KangMinji on 2022-09-03.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct student {
    string name;
    int kor, eng, math;
};

// cmp가 true를 반환하면 왼쪽이 오른쪽보다 먼저 나오게 된다
// a가 b보다 먼저 나오는 것이 맞아?
// 다를 때를 먼저 처리해주자
bool cmp(const student &a, const student &b) {
    // 1) 국어 점수가 다르다면
    if (a.kor != b.kor)
        return a.kor > b.kor;

    // 2) 영어 점수가 다르다면
    if (a.eng != b.eng)
        return a.eng < b.eng;

    // 3) 수학 점수가 다르다면
    if (a.math != b.math)
        return a.math > b.math;

    // 4) 모든 점수가 같으면
    return a.name < b.name;
}

int main() {
    int n;

    // 입력
    cin >> n;
    vector<student> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i].name >> arr[i].kor >> arr[i].eng >> arr[i].math;

    // 연산
    sort(arr.begin(), arr.end(), cmp);

    // 출력
    for (int i = 0; i < n; i++)
        cout << arr[i].name << "\n";
}
