//
// Created by KangMinji on 2022-09-26.
//

#include <iostream>
using namespace std;

int calcMoney(string start, int time){
    int answer = 0;
    int start_hour = stoi(start.substr(0, 2));
    int start_minute = stoi(start.substr(3, 2));
    int end_hour = (start_hour + (start_minute + time) / 60) % 24;
    int end_minute = (start_minute + time) % 60;

    // 2) zone2 : 19:00 ~ 23:59 && 00:00 ~ 06:59

    // 1) zone 2에서 시작
    if ((start_hour >= 19 && start_hour < 24) || (start_hour >= 0 && start_hour < 7)) {
        // 2-1) 같은 zone 안에서 해결
        if (end_hour >= 19 || end_hour < 7) {
            answer += 5 * time;
        }
        // 2-2) zone2 -> zone1
        else {
            answer += 5 * (60 - start_minute);
            answer += 10 * end_minute;
        }
    }

    // 2) zone 1에서 시작
    else if (start_hour >= 7 && start_hour < 19) {
        // 1-1) 같은 zone 안에서 해결
        if (end_hour < 19) {
            answer += 10 * time;
        }
        // 1-2) zone1 -> zone2
        else {
            answer += 10 * (60 - start_minute);
            answer += 5 * end_minute;
        }
    }
    return answer;

//    // 2) 다른 통화요금 적용되는 경우(통화시간 max 60분)
//    // 1) zone1 -> zone2
//    if (start_hour < 19 && end_hour >= 19){
//        answer += 10 * (60 - start_minute);
//        answer += 5 * end_minute;
//        return answer;
//    }
//    // 2) zone2 -> zone1
//    if (start_hour < 7 && end_hour >= 7) {
//        answer += 5 * (60 - start_minute);
//        answer += 10 * end_minute;
//        return answer;
//    }
//
//    // 1) 같은 통화요금 적용되는 경우
//    // 1-1) zone1 : 07:00 ~ 18:59
//    if (start_hour >= 7 && end_hour >= 7 && end_hour < 19){
//        answer += time * 10;
//    } else {
//        // 1-2) zone2 : 19:00 ~ 06:59
//        answer += time * 5;
//    }
//
}

int main() {
    int n, time;
    string start;

    int answer = 0;

    // 입력
    cin >> n;
    while (n--) {
        cin >> start >> time;
        // 연산
        answer += calcMoney(start, time);
    }
    // 출력
    cout << answer;
}