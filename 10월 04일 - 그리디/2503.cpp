//
// Created by KangMinji on 2022-10-31.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 * 스트라이크 : 동일한 숫자, 동일한 위치
 * 볼 : 동일한 숫자, 다른 위치
 * -> 3 스트라이크가 되면 게임 오버
 *
 * 서로 다른 3자리 수 중 최소 : 123
 * 서로 다른 3자리 수 중 최대 : 987
 * https://moongsilismine.tistory.com/13 : 너무 연산량이 많은 것 같아서 방법 확인차 참고했습니다
 */
vector<bool> init() {
    vector<bool> v(1000, true);
    string str;
    for (int i=123; i<=987; i++){
        str = to_string(i);

        // 1) 0이 포함되어 있다면 제외
        if (str[0] - '0' == 0 || str[1] - '0' == 0 || str[2] - '0' == 0){
            v[i] = false;
        }
        // 2) 서로 다른 숫자가 아니라면 제외
        if (str[0] == str[1] || str[1] == str[2] || str[2] == str[0]){
            v[i] = false;
        }
    }
    return v;
}

int main() {
    int n, strike, ball;
    string num;

    cin >> n;
    vector<bool> v = init();

    while(n--){
        cin >> num >> strike >> ball;
        for (int i=123; i<=987; i++) {
            // 각 자리의 숫자가 서로 다른 경우
            if (v[i]) {
                // 각 숫자별 strike, ball 개수 판단
                int strike_cnt = 0;
                int ball_cnt = 0;

                // 비교 대상 숫자 변환
                string compare_num = to_string(i);

                // 숫자와 num을 비교하며 strike, ball 개수 비교
                for (int x=0; x<3; x++){
                    for (int y=0; y<3; y++){
                        // 1) 동일한 숫자, 동일한 위치 -> 스트라이크
                        if (x == y && num[x] == compare_num[y]){
                            strike_cnt++;
                        }
                        // 2) 동일한 숫자, 다른 위치 -> 볼
                        if (x != y && num[x] == compare_num[y]){
                            ball_cnt++;
                        }
                    }
                }
                // strike, ball이 일치하지 않으면 후보 탈락
                if (strike_cnt != strike || ball_cnt != ball){
                    v[i] = false;
                }
            }
        }
    }

    // 남은 후보 개수 계산
    int ans = 0;
    for (int i=123; i<=987; i++){
        if (v[i]){
            ans++;
        }
    }

    // 출력
    cout << ans << "\n";
}