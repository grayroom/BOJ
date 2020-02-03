#include <iostream>
#include <map>
#include <vector>

using namespace std;

int findPath(multimap<int, int>& XY, map<int, int>& D, const int dstIdx);

int main() {
    int T{},
        N{},
        K{},
        Dtmp{},
        Xtmp{},
        Ytmp{},
        W{};
    map<int, int> D{};
    multimap<int, int> XY{};
    vector<int> res{};

    cin >> T;

    for(int i = 0; i < T; ++i) {
        cin >> N >> K;

        for(int j = 0; j < N; ++j) {
            cin >> Dtmp;
            D.insert(make_pair(j + 1, Dtmp));
        }

        for(int j = 0; j < K; ++j) {
            cin >> Xtmp >> Ytmp;
            XY.insert(make_pair(Ytmp, Xtmp));
        }

        cin >> W;

        res.push_back(findPath(XY, D, W));
    }

    for(int x : res) {
        cout << x << endl;
    }
}

int findPath(multimap<int, int>& XY, map<int, int>& D, const int dstIdx) {
    int minPath{},
        tempPath{};
    vector<int> prev{};

    auto it = XY.find(dstIdx);
    if(it != XY.end()) {
        for(it = XY.begin(); it != XY.end(); it++) {
            if(it->first == dstIdx) {
                prev.push_back(it->second);
            }
        }

        minPath = findPath(XY, D, prev[0]);

        for(int x : prev) {
            tempPath = findPath(XY, D, x);
            if(tempPath > minPath) {
                minPath = tempPath;
            }
        }
    }

    return D.find(dstIdx)->second + minPath;
}