#include <iostream>
#include <vector>
#include <set>
#include <random>
#include <iomanip>


using namespace std;

int main() {
    int T{},
        N{},
        X{},
        Y{};

    vector<double> res{};

    cin >> T;
    for(int i = 0; i < T; ++i) {
        vector<pair<int, int>> P{};

        // N개의 정점 P를 입력합니다.
        cin >> N;
        for(int j = 0; j < N; ++j) {
            cin >> X >> Y;
            P.emplace_back(X, Y);
        }


        // 1.   set P에서 2개의 정점을 선택하여 하나의 벡터를 만든다
        // 1-1. 해당 벡터를 "사용한 벡터 set"에 포함시킨다.
    }

    return 0;
}

double findMinVectorSet(vector<pair<int, int>>& P) {
    vector<pair<int, int>> V{};


}

void selectLoop(vector<pair<int, int>>& P, set<int>& usedP, vector<pair<int, int>>& V, set<pair<int, int>>& usedV, double& minDist, const int level = 0) {
    int posX{},
        posY{};

    minDist = 400000;

    if(level != P.size() / 2) {
        random_device rd;
        mt19937 mersenne(rd());
        uniform_int_distribution<> rg(0, 19);

        for (int i = 0; i < (P.size() - level) * (P.size() - level - 1) / 2;) {
            if(level == 0) {
                usedP.clear();
            }

            do {
                posX = rg(mersenne);
                posY = rg(mersenne);
            } while (posX == posY &&
                     usedP.find(posX) != usedP.end() &&
                     usedP.find(posY) != usedP.end() &&
                     usedV.find(make_pair(posX, posY)) != usedV.end());

            usedP.emplace(posX);
            usedP.emplace(posY);
            usedV.emplace(make_pair(posX, posY));

            V.emplace_back(make_pair(posX, posY));


            selectLoop(P, usedP, V, usedV, minDist, ++i);
        }
    } else {
        pair<int, int> firstP{},
                       secondP{};

        for(pair<int, int> currV : V) {
            firstP = P[currV.first];
            secondP = P[currV.second];

            posX -= firstP.first;
            posX += secondP.first;
            posY -= firstP.second;
            posY += secondP.second;
        }

        if (sqrt(pow(posX, 2) + pow(posY, 2)) < minDist) {
            minDist = sqrt(pow(posX, 2) + pow(posY, 2));
        }

        V.clear();
    }
}