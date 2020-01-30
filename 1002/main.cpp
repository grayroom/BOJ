#include <iostream>
#include <vector>

using namespace std;

int main() {
    int testCase{};
    int* positArray{};
    cin >> testCase;
    vector<int> res{};

    for(int i = 0; i < testCase; i++) {
        positArray = new int[6];

        for(int j = 0; j < 6; j++) {
            cin >> positArray[j];
        }

        int distSqr {
                (positArray[3] - positArray[0]) * (positArray[3] - positArray[0]) +
                (positArray[4] - positArray[1]) * (positArray[4] - positArray[1])
                },
            range1Sqr {
                positArray[2] * positArray[2]
                },
            range2Sqr {
                positArray[5] * positArray[5]
                },
            rangeAddSqr {
                (positArray[2] + positArray[5]) * (positArray[2] + positArray[5])
                },
            rangeSubSqr {
                (positArray[2] - positArray[5]) * (positArray[2] - positArray[5])
                };

        if(distSqr == 0) {
            if(positArray[2] == positArray[5]) {
                res.push_back(-1);
            } else {
                res.push_back(0);
            }
        } else {
            if (distSqr > rangeAddSqr) {
                res.push_back(0);
            } else if (distSqr == rangeAddSqr) {
                res.push_back(1);
            } else if (distSqr < rangeAddSqr && distSqr > rangeSubSqr) {
                res.push_back(2);
            } else if (distSqr == rangeSubSqr) {
                res.push_back(1);
            } else {
                res.push_back(0);
            }
        }
    }

    for(int i = 0; i < res.size(); i++) {
        if(i != res.size() - 1) {
            cout << res[i] << endl;
        } else {
            cout << res[i];
        }
    }
}
