#include <iostream>

using namespace std;

int main() {
    int H{}, M{}, time{};
    cin >> H >> M;
    time = 60 * H + M - 45;

    if (time < 0) {
        time += 60 * 24;
    }

    H = time / 60;
    M = time - H * 60;

    cout << H << ' ' << M << endl;

    return 0;
}
