//
// Created by KangMinji on 2022-09-07.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

// 추월을 한 차가 몇 개인지 구하는 함수
int jumpCar(int n, vector<string> &out_car, map<string, int> &m){
    int ans = 0;
    for (int i=0; i<n; i++){ // 나온 차를 순서대로 검사
        for (int j=i+1; j<n; j++){ // 나보다 늦게 나온 차가 인덱스 작으면 -> 추월
            if (m[out_car[i]] > m[out_car[j]]) {
                ans++;
                break;
            }
        }
    }
    return ans;
}


/*
 * A보다 터널에서 늦게 나온 차 중에서 A보다 인덱스가 작은 차가 하나라도 있다
 * => A는 추월을 했다!
 */
int main() {
    int n;
    string car;
    map<string, int> m;

    // 입력
    cin >> n;
    vector<string> out_car(n, "");
    for (int i = 1; i <= n; i++) { // 들어오는 차
        cin >> car;
        m[car] = i;
    }

    for (int i = 0; i < n; i++) {
        cin >> out_car[i];
    }

    // 연산 & 출력
    cout << jumpCar(n, out_car, m);

}