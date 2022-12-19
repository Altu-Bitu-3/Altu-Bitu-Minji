//
// Created by KangMinji on 2022-09-12.
//

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> ci;

int main() {
    vector<int> v;
    int num, sum, cnt = 0;

    // 입력
    // 일단 getline 처리하기 번거로워서 cin >> num으로 했는데 둘 중 뭐가 더 좋은 방법인지 궁금합니다!
    while(cin >> num){
        v.push_back(num);
    }
    sum = v.back();
    v.pop_back();

    // 연산
    sort(v.begin(), v.end()); // 사전순 정렬

    map<ci, bool> m;
    for (int i=0; i<v.size(); i++){
        for (int j=i+1; j<v.size(); j++){
            if ((v[i] + v[j] == sum) && m.find({v[i], v[j]})==m.end()){
                cout << v[i] << " " << v[j] <<"\n";
                // (i, j), (j, i)는 쌍 하나로 한다 -> 출력은 a<=b인 쌍을 출력
                m[{v[i], v[j]}] = true;
                m[{v[j], v[i]}] = true;
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
}