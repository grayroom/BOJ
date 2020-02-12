#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T{};
    cin >> T;

    vector<int> res{};

    int numData[10][12] = { // 각 a값의 1의자리를 보면, b에 따라 아래와 같은 규칙을 갖는것을 알 수 있다.
            {10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {2, 4, 8, 6, 2, 4, 8, 6, 2, 4, 8, 6},
            {3, 9, 7, 1, 3, 9, 7, 1, 3, 9, 7, 1},
            {4, 6, 4, 6, 4, 6, 4, 6, 4, 6, 4, 6},
            {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
            {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
            {7, 9, 3, 1, 7, 9, 3, 1, 7, 9, 3, 1},
            {8, 4, 2, 6, 8, 4, 2, 6, 8, 4, 2, 6},
            {9, 1, 9, 1, 9, 1, 9, 1, 9, 1, 9, 1},
    };

    for(int ct = 0; ct < T; ++ct) {
        int a{}, b{};

        cin >> a >> b;

        res.emplace_back(numData[(a % 10)][((b - 1) % 12)]);
    }

    for(int x : res) {
        cout << x << endl;
    }

    return 0;
}
