#include <iostream>
#include <vector>

using namespace std;

int main() {
    int testCase{};
    cin >> testCase;

    int path[4]{},
            numPlanet{},
            **planetInfo{},
            startDistSqr{},
            finishDistSqr{},
            rangeSqr{};

    vector<int> res{};

    for(int i = 0; i < testCase; i++) {
        for(int & j : path) {
            cin >> j;
        }

        cin >> numPlanet;
        planetInfo = new int*[numPlanet];
        for(int j = 0; j < numPlanet; j++) {
            planetInfo[j] = new int[3];
        }

        for(int j = 0; j < numPlanet; j++) {
            for(int k = 0; k < 3; k++) {
                cin >> planetInfo[j][k];
            }
        }

        int passCount{0};
        bool posStart{},
                posFinish{};

        for(int j = 0; j < numPlanet; j++) {
            startDistSqr = (path[0] - planetInfo[j][0]) * (path[0] - planetInfo[j][0]) +
                           (path[1] - planetInfo[j][1]) * (path[1] - planetInfo[j][1]);
            finishDistSqr = (path[2] - planetInfo[j][0]) * (path[2] - planetInfo[j][0]) +
                            (path[3] - planetInfo[j][1]) * (path[3] - planetInfo[j][1]);
            rangeSqr = planetInfo[j][2] * planetInfo[j][2];

            posStart = startDistSqr <= rangeSqr;
            posFinish = finishDistSqr <= rangeSqr;

            if(posStart != posFinish) {
                passCount++;
            }
        }

        for(int j = 0; j < numPlanet; j++) {
            delete[] planetInfo[j];
        }
        delete[] planetInfo;

        res.push_back(passCount);
    }

    for(int i = 0; i < res.size(); i++) {
        if(i != res.size() - 1) {
            cout << res[i] << endl;
        } else {
            cout << res[i];
        }
    }

    return 0;
}
