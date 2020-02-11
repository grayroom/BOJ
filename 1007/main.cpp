#include <iostream>
#include<cstdio>
#include <vector>
#include<math.h>
#include<algorithm>

using namespace std;

void getNextIndex(bool* select, const int* posX, const int* posY, int level, int index, int n, double* res);

int main() {
    int T{},
        N{};

    vector<double> res{};

    cin >> T;
    for(int i = 0; i < T; ++i) {
        int posX[21]{},
            posY[21]{};
        bool select[21]{};
        double result{numeric_limits<double>::max()};

        cin >> N;
        for(int j = 0; j < N; ++j) {
            cin >> posX[j] >> posY[j];
        }
        getNextIndex(select, posX, posY, 0, 0, N, &result);
        res.emplace_back(result);
    }

    for(double x : res) {
        printf("%.6lf\n", x);
    }

    return 0;
}
void getNextIndex(bool* select, const int* posX, const int* posY, int level, int index, int n, double* res) {
    if(level == n / 2) {
        double x{}, y{};
        for(int i = 0; i < n; ++i) {
            if(select[i]) {
                x -= posX[i];
                y -= posY[i];
            } else {
                x += posX[i];
                y += posY[i];
            }
        }
        *res = min(*res, sqrt(x*x + y*y));
        return;
    }
    if(index == n) {
        return;
    }

    getNextIndex(select, posX, posY, level, index + 1, n, res);
    select[index] = true;
    getNextIndex(select, posX, posY, level + 1, index + 1, n, res);
    select[index] = false;
}