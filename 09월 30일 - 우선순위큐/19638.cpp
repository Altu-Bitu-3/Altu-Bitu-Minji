//
// Created by KangMinji on 2022-10-05.
//

#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int main() {
    int n, limit;
    long long centi_height, h;

    // 입력
    cin >> n >> centi_height >> limit;
    // 1) 내림차순 pq에 거인 키 저장
    priority_queue<long long> pq;
    while (n--) {
        cin >> h;
        pq.push(h);
    }

    // 연산
    // 2) 뿅망치 횟수 제한(limit)만큼 망치 적용
    int cnt_hammer = 0; // 뿅망치 사용 횟수
    while(limit--) {
        long long item = pq.top();

        // 망치를 최소로 '사용'한 횟수
        if (item < centi_height){
            break;
        }

        // 키가 1이면 영향을 받지 않는다
        if (item == 1){
            continue;
        }

        pq.pop();
        item = floor(item/2);
        pq.push(item);

        cnt_hammer++;
    }

    // 3) pq.top()과 센티의 키 비교
    if (pq.top() < centi_height){
        cout << "YES\n" << cnt_hammer << "\n";
    } else {
        cout << "NO\n" << pq.top() << "\n";
    }

}