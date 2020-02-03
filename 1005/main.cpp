#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int T{},
        N{},
        K{},
        *D{},
        Xtmp{},
        Ytmp{},
        W{};
    multimap<int, int> XY{};
    vector<int> res{};

    cin >> T;

    for(int i = 0; i < T; ++i) {
        cin >> N >> K;

        vector<vector<pair<int, int>>> graph{};
        for(int j = 0; j < N; j++) {
            auto* tmp = new vector<pair<int, int>>;
            graph.push_back(*tmp);
        }

        for(int j = 0; j < N; ++j) {
            cin >> D[j];
        }

        for(int j = 0; j < K; ++j) {
            cin >> Xtmp >> Ytmp;
            graph[Xtmp - 1].push_back(make_pair(Ytmp, D[Xtmp - 1]));
        }

        cin >> W;
    }

    for(int x : res) {
        cout << x << endl;
    }
}