//
// Created by KangMinji on 2022-10-05.
//

#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int attack(priority_queue<int> &pq, int centi_height, int limit){
    // 2) 뿅망치 횟수 제한(limit)만큼 망치 적용
    int cnt_hammer = 0; // 뿅망치 사용 횟수
    while(limit--) {
        int item = pq.top();

        // 망치를 최소로 '사용'한 횟수
        if (item < centi_height || item == 1){
            break;
        }

        // 키가 1이면 영향을 받지 않는다
//        if (item == 1){
//            continue;
//        }

        pq.pop();
        pq.push(item/2); // c++에서 정수형 나누기는 소수점 이하 버림

        cnt_hammer++;
    }
    return cnt_hammer;
}

int main() {
    int n, limit, centi_height, h;
    priority_queue<int> pq;

    // 입력
    cin >> n >> centi_height >> limit;

    // 1) 최대힙에 거인 키 저장
    while (n--) {
        cin >> h;
        pq.push(h);
    }

    // 연산
    int cnt_hammer = attack(pq, centi_height, limit);

    // 3) pq.top()과 센티의 키 비교
    if (pq.top() < centi_height){
        cout << "YES\n" << cnt_hammer << "\n";
    } else {
        cout << "NO\n" << pq.top() << "\n";
    }

}