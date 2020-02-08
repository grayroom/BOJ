#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <cmath>
#include <iomanip>

using namespace std;

pair<int, int>& findClosest(vector<pair<int, int>>& P, set<pair<int, int>>& V, const pair<int, int> src);
double getDist(pair<int, int> from, pair<int, int> to);


int main() {
    int T{},
        N{},
        X{},
        Y{};

    vector<double> res{};

    cin >> T;
    for(int i = 0; i < T; ++i) {
        vector<pair<int, int>> P{};
        set<pair<int, int>> V{};
        pair<int, int> fromNode{},
                       toNode{};

        double resTemp{};

        cin >> N;
        for(int j = 0; j < N; ++j) {
            cin >> X >> Y;
            P.emplace_back(X, Y);
        }

        for(auto iter = P.begin(); iter != P.end() || P.size() != V.size(); iter++) {
            if(V.find(*iter) == V.end()) {
                fromNode = *iter;
                V.emplace(fromNode);
                toNode = findClosest(P, V, *iter);
                V.emplace(toNode);

                resTemp += getDist(fromNode, toNode);
            } else {
                continue;
            }
        }

        res.push_back(resTemp);
    }

    cout << fixed << setprecision(12);
    for(double x : res) {
        cout << x << endl;
    }

    return 0;
}

pair<int, int>& findClosest(vector<pair<int, int>>& P, set<pair<int, int>>& V, const pair<int, int> src) {
    auto iter = P.begin();

    double distMin{},
           distTemp{};

    pair<int, int>& closest {*iter};

    for(pair<int ,int> x : P) {
        if(V.find(x) == V.end()) {
            distTemp = pow((x.first - src.first), 2) + pow((x.second - src.second), 2);

            if (distTemp < distMin || (distMin == 0 && distTemp != 0)) {
                distMin = distTemp;
                closest = x;
            }
        } else {
            continue;
        }
    }

    return closest;
}

double getDist(pair<int, int> from, pair<int, int> to) {
    return sqrt(pow((from.first - to.first), 2) + pow((from.second - to.second), 2));
}