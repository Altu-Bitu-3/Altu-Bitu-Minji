//
// Created by KangMinji on 2022-09-21.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_DIFF = 1000;
vector<vector<int>> power;

int sumPower(vector<int> &team){
    int sum = 0; // 능력치 합
    int size = team.size();

    // S[ii]는 항상 0임
    for (int i=0; i<size; i++){
        for (int j=i+1; j<size; j++){
            sum += power[team[i]][team[j]] + power[team[j]][team[i]];
        }
    }
    return sum;
}

/*
 * 입력 범위 : n(4<=n<=20)
 */
int calcDiff(int n, vector<bool> &is_teamA) {
    // 전달받은 임시배열을 이용해서 팀을 나누고, 팀 별 능력치를 계산해서 차이를 리턴
    vector<int> teamA; // A팀에 속한 사람들의 인덱스
    vector<int> teamB; // B팀에 속한 사람들의 인덱스

    for (int i = 0; i < n; i++) {
        if (is_teamA[i]) {
            teamA.push_back(i);
        } else {
            teamB.push_back(i);
        }
    }

    // 차이 구하기
    int diff = sumPower(teamA) - sumPower(teamB);
    return abs(diff);
}

int findMinDiff(int n) {
    // 1. 팀 나누기
    // 2. 각 팀마다 능력치 합 구하기
    // 3. 능력치 차이의 최소 기록하기

    // 조합을 구하기 위해 임시 배열 만들기
    vector<bool> is_teamA(n, true);
    for (int i = 0; i < n / 2; i++) {
        is_teamA[i] = false;
    }

    int answer = MAX_DIFF;

    do {
        // 팀이 결정된 상황
        // 팀 간 능력치 차이 구하고, 최솟값을 기록
        answer = min(answer, calcDiff(n, is_teamA));
    } while (next_permutation(is_teamA.begin() + 1, is_teamA.end()));
    // 중복 조합을 제거하기 위해 0번 인덱스는 teamA에 고정시키고 시작

    return answer;
}

int main() {
    int n;

    // 입력
    cin >> n;
    power.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> power[i][j];
        }
    }

    // 브루트포스로 팀을 나눠본 후, 나올 수 있는 차이의 최솟값을 기록
    cout << findMinDiff(n);

    return 0;
}