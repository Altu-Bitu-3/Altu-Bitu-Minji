//
// Created by KangMinji on 2022-11-28.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

//Find 연산
int findParent(int node) {
    // 루트노드인 경우 리턴
    if (parent[node] < 0) {
        return node;
    }
    // 부모 다시 탐색(더 올라가기)
    return parent[node] = findParent(parent[node]);
}

//Union 연산
void unionInput(int x, int y) {
    // 각 값의 부모 노드 찾기
    int xp = findParent(x);
    int yp = findParent(y);

    // 같은 파티라면 바로 리턴
    if (xp == yp) {
        return;
    }

    // xp가 상위 트리인 경우
    if (parent[xp] < parent[yp]) {
        parent[xp] += parent[yp]; // 연결하고
        parent[yp] = xp; // 위치 바꿔주기
    }

    // yp가 상위 트리인 경우
    else {
        parent[yp] += parent[xp]; // 연결하고
        parent[xp] = yp; // 위치 바꿔주기
    }
}

int liarParty(vector<int>& parties) {
    int cnt = 0; // 거짓말을 할 수 있는 파티의 수
    for (int i = 0; i < parties.size(); i++) {
        // 둘의 루트 노드가 다른 경우 파티 수 증가
        if (findParent(parties[i]) != findParent(0)) {
            cnt++; // 증가
        }
    }
    return cnt;
}

/**
 * [거짓말]
 *
 * 1. 각 사람들은 다양한 파티를 통해 연결됐다고 할 수 있음
 * 2. 연결된 사람들은 같은 집합에 속함
 * 3. 각 집합에 속한 사람들 중 한 명이라도 진실을 안다면 그 집합의 사람들이 속한 파티에는 거짓말을 할 수 없음
 * -> 유니온 파인드로 사람들을 집합으로 묶은 뒤, 파티마다 거짓말을 할 수 있는지 확인하기
 * -> 이때, 진실을 아는 사람들의 루트 정점을 0으로 설정해서 유니온 파인드를 통해 집합으로 묶고 시작
 * -> 0과 같은 집합이 아니어야 거짓말을 할 수 있음
 *
 * !주의! 파티 정보를 입력받으며 바로 거짓말 가능 여부를 판단할 수 없음 (예제 입력 4)
 *       각 파티에서 한 사람만 저장해둔 뒤, 마지막에 거짓말 가능 여부 한 번에 판단
 */

int main() {
    int n, m; // 사람의 수, 파티의 수

    //입력
    cin >> n >> m;
    parent.assign(n + 1, -1);

    int init, p; // 이야기의 진실을 아는 사람의 수, 번호
    cin >> init;
    while (init--) { //진실을 아는 사람들
        cin >> p;
        unionInput(0, p); // 정보 저장(진실 알면 root 0)
    }

    // 각 파티마다 오는 사람의 수, 번호
    int cnt, first_person, person;
    vector<int> parties;
    while (m--) {
        cin >> cnt >> first_person;

        //연산
        parties.push_back(first_person); //파티 정보로 각 파티의 첫번째 사람만 저장
        while (--cnt) { // 해당 파티의 사람 수만큼
            cin >> person; // 나머지 사람 입력받기
            unionInput(first_person, person); // 첫번째 사람 root로 노드 연결
        }
    }

    //연산 & 출력
    cout << liarParty(parties);
    return 0;
}