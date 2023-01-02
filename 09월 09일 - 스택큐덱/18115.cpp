//
// Created by KangMinji on 2022-09-15.
//

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

// 제일 위에 있는 카드를
// 1) front에 push
// 2) 위에서 두 번째에 push
// 3) back에 push -> deque 사용
deque<int> playCard(int n, vector<int> &technique, vector<int> &order){
    deque<int> d;

    for (int i=0; i<n; i++){
        switch (technique[i]){
            case 1: {
                d.push_front(order[i]);
                break;
            }
            case 2: {
                int card = d.front();
                d.pop_front();
                d.push_front(order[i]);
                d.push_front(card);
                break;
            }
            case 3: {
                d.push_back(order[i]);
                break;
            }
        }
    }
    return d;
}

int main() {
    int n;
    vector<int> technique;
    vector<int> order;

    // 입력
    cin >> n;
    technique.assign(n, 0);
    order.assign(n, 0);
    for (int i=n-1; i>=0; i--){ // 기술 역순으로 입력받기
        cin >> technique[i];
    }

    for (int j=0; j<n; j++){ // 순서 초기화(1~N)
        order[j] = j+1;
    }

    // 연산
    deque<int> d = playCard(n, technique, order);

    // 출력
    while (!d.empty()) {
        cout << d.front() << " ";
        d.pop_front();
    }
}