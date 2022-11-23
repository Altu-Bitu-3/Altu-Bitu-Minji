//
// Created by KangMinji on 2022-11-22.
//

#include <iostream>
#include <vector>
using namespace std;

/*
    !주의! 당장 쌓을 블록이 없더라도 언젠가 다른 곳의 블록을 제거해서 쌓을 수 있음.
    시간을 최소로 하는 것이 우선되고, 소요 시간이 같을 경우 높이가 높은 것이 정답임
    => 소요 시간을 최소로 해야 하기 때문에, 완성된 땅의 높이는 입력받은 땅의 높이의 최솟값 ~ 최댓값 사이로 결정된다.
 */

const int INF = 1e9; // 최댓값으로 지정

int minimumTime(int height, int block, int n, int m, vector<vector<int>> &ground) {
    int time = 0; // height 높이로 땅 고르는데 걸리는 시간
    for (int i = 0; i < n; i++) { // n행
        for (int j = 0; j < m; j++) { // m열
            // 1) 땅이 height보다 높은 경우 -> 블록 제거 필요(인벤에 블록 추가)
            if (height < ground[i][j]) {
                block += (ground[i][j] - height); // 땅 높이 - height만큼 인벤에 블록 추가
                time += 2 * (ground[i][j] - height); // 제거 작업은 2초가 걸림
            }
            // 2) 땅이 height보다 낮은 경우 -> 블록 쌓기(인벤에서 블록 제거)
            else if (height > ground[i][j]) {
                block -= (height - ground[i][j]); // height - 땅 높이만큼 인벤에서 블록 제거
                time += (height - ground[i][j]); // 추가 작업은 1초가 걸림
            }
        }
    }

    if (block < 0) { //다 계산을 했는데 block이 음수이면 불가능한 경우
        return INF; // 최대 시간 리턴
    }
    return time; // 정상적인 경우라면 구한 time 리턴
}

pair<int, int> solution(int min_h, int max_h, int b, int n, int m, vector<vector<int>> &ground) {
    pair<int, int> result = {INF, 0}; //최소 시간, 최대 높이

    for (int height = min_h; height <= max_h; height++) { // 최소 높이 ~ 최대 높이까지 돌면서
        int time = minimumTime(height, b, n, m, ground); // 해당 높이로 땅 고르는데 걸리는 시간 계산
        if (time <= result.first) { // 최소 시간이 같을 경우, 최대 높이를 출력해야 하기 때문에 등호 필요
            result = {time, height}; // {최소 시간, 최대 높이}로 업데이트
        }
    }

    return result; // 결과 리턴
}

int main() {
    int n, m, b; // 세로 n, 가로 m, 인벤에 있는 블록의 개수 b

    // 입력
    cin >> n >> m >> b;
    vector<vector<int>> ground(n, vector<int>(m, 0)); // 집터 초기화

    int max_h = 0, min_h = INF; // 제일 높은 곳의 높이, 제일 낮은 곳의 높이
   for (int i = 0; i < n; i++) { // n행
        for (int j = 0; j < m; j++) { // m열
            cin >> ground[i][j]; // (i, j)칸 블록의 높이
            max_h = max(max_h, ground[i][j]); // 제일 높은 곳의 높이
            min_h = min(min_h, ground[i][j]); // 제일 낮은 곳의 높이
        }
    }

    // 연산
    pair<int, int> result = solution(min_h, max_h, b, n, m, ground);

    // 땅을 고르는 데 걸리는 시간, 땅의 높이
    cout << result.first << " " << result.second;
}