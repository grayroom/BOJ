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

        // 1. 두 구역을 커버할 수 있다면, 그 조합을 저장한다.
        // 2. 저장한 조합 중에서 최대한 많이 사용할 수 있는 새로운 조합을 찾는다. (전수조사, 새로운방법)

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

    for(int x : result) {
        cout << x << endl;
    }
}
