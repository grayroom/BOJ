#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    int T{};
    cin >> T;

    vector<unsigned long long> res{};

    for(int ct = 0; ct < T; ++ct) {
        int N{}, M{}, reducer{};
        unsigned long long result{};

        cin >> N >> M;
        result = 1;

        if(N < M - N) {
            N = M - N;
        }

        for (int i = M; i > N; --i) {
            result *= i;
            while(result % 2 == 0) {
                reducer++;
                result /= 2;
            }
        }

        for(int i = 1; i <= M - N; ++i) {
            while(result < numeric_limits<unsigned long long>::max() / 2 && reducer > 0) {
                reducer--;
                result *= 2;
            }
            result /= i;
        }

        for(int i = 0; i < reducer; ++i) {
            result *= 2;
        }

        res.emplace_back(result);
    }

    for(int x : res) {
        cout << x << endl;
    }

    return 0;
}
