#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int T{}, N{}, W{};
    vector<int> result{};

    cin >> T;
    for(int i = 0; i < T; ++i) {
        cin >> N >> W;

        // 변수선언
        int res{}, duoCount{};
        auto** room = new int*[2];
        for(int j = 0; j < 2; ++j) {
            room[j] = new int[N];
        }
        auto** roomCnt = new int*[2];
        for(int j = 0; j < 2; ++j) {
            roomCnt[j] = new int[N];
        }

        // 각 구역에 적의 수를 입력합니다.
        for(int j = 0; j < N * 2; ++j) {
            cin >> room[j / N][j % N];
            roomCnt[j / N][j % N] = 0;
        }

        // 인접한 두 구역을 하나의 소대로 커버할 수 있다면 해당 지역에 카운트합니다.
        for(int j = 0; j < N * 2; ++j) {
            if(j < N && W >= room[j / N][j % N] + room[j / N + 1][j % N]) { // 어떤 구역과 그 바깥쪽 구역이 인접한경우
                roomCnt[j / N][j % N]++;
                roomCnt[j / N + 1][j % N]++;
            }
            if(W >= room[j / N][j % N] + room[j / N][(j + 1) % N]) { // 어떤 구역과 그 옆의 구역이 인접한 경우
                roomCnt[j / N][j % N]++;
                roomCnt[j / N][(j + 1) % N]++;
            }
        }

        /*
        cout << endl << "----------------------" << endl;
        for(int j = 0; j < N * 2; ++j) {
            if(j == N) {
                cout << endl;
            }

            cout << room[j / N][j % N] << ' ';
        }
        cout << endl << "----------------------" << endl;
        cout << endl << "----------------------" << endl;
        for(int j = 0; j < N * 2; ++j) {
            if(j == N) {
                cout << endl;
            }

            cout << roomCnt[j / N][j % N] << ' ';
        }
        cout << endl << "----------------------" << endl;
        */

        int left{}, right{}, up{}, min{};
        // 카운트 결과를 보고, 인접한 두 구역의 합이 작은 순서대로 두 구역을 커버하고, 해당 구역의 카운트를 모두 제거합니다.
        for(int j = 1; j <= 3; ++j) { // 카운트 횟수가 작은 구역부터 탐색
            for(int k = 0; k < N * 2; ++k) { // 모든 구역을 탐색
                if(roomCnt[k / N][k % N] == j) { // 현재 탐색중인 카운트 횟수와 일치하는 구역을 찾은 경우
                    // 인접한 3개의 구역의 카운트를 확인(카운트가 0인 경우, 해당 구역은 카운트 4를 가졌던것으로 취급)
                    up = roomCnt[(k / N + 1) % 2][k % N];
                    if(up == 0) {
                        up = 4;
                    }
                    right = roomCnt[k / N][(k + 1) % N];
                    if(right == 0) {
                        right = 4;
                    }
                    left = roomCnt[k / N][(k + N - 1) % N];
                    if(left == 0) {
                        left = 4;
                    }

                    if(up == right && up == left && up == 4) { // 인접한 모든 구역의 카운트가 0인 경우, 해당 구역은 하나의 소대로 커버해야함 따라서 카운트를 삭제하지 않음
                        continue;
                    } else { // 인접한 구역중 적어도 하나의 구역의 카운트가 0이 아닌경우, 0이 아닌 가장작은 카운트를 갖는 구역과 현재 탐색중인 구역을 하나의 소대로 커버한다.
                        min = std::min(left, right);
                        min = std::min(min, up);

                        // 카운트를 제거
                        if(min == up && W >= room[k / N][k % N] + room[((k + N) / N) % 2][k % N]) {
                            roomCnt[k / N][k % N] = 0;
                            roomCnt[(k / N + 1) % 2][k % N] = 0;
                            res++;
                            duoCount++;

                            continue;
                        } else if (std::min(left, right) == right && W >= room[k / N][k % N] + room[k / N][(k + 1) % N]) {
                            roomCnt[k / N][k % N] = 0;
                            roomCnt[k / N][(k + 1) % N] = 0;
                            res++;
                            duoCount++;

                            continue;
                        } else if (W >= room[k / N][k % N] + room[k / N][(k + N - 1) % N]) {
                            roomCnt[k / N][k % N] = 0;
                            roomCnt[k / N][(k + N - 1) % N] = 0;
                            res++;
                            duoCount++;

                            continue;
                        } else {
                            continue;
                        }
                    }
                }
            }
        }

        res += N * 2 - duoCount * 2;
        result.emplace_back(res);

        for(int j = 0; j < 2; ++j) {
            delete[] roomCnt[j];
        }
        delete[] roomCnt;
        for(int j = 0; j < 2; ++j) {
            delete[] room[j];
        }
        delete[] room;
    }

    cout << endl << "----------------------" << endl;
    for(int x : result) {
        cout << x << endl;
    }
}
