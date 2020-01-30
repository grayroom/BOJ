#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int fibo(int n, int* totZero, int* totOne);

int main() {
    double start, finish;
    start = clock();

    int testCase{};
    cin >> testCase;

    vector<int> res{};

    for(int i = 0; i < testCase; i++) {
        int 
            n{},
            totZero{},
            totOne{};

        cin >> n;

        fibo(n, &totZero, &totOne);

        res.push_back(totZero);
        res.push_back(totOne);
    }

    for(int i = 0; i < res.size() / 2; i++) {
        if(i != res.size() / 2 - 1) {
            cout << res[2 * i] << ' ' << res[2 * i + 1] << endl;
        } else {
            cout << res[2 * i] << ' ' << res[2 * i + 1];
        }
    }

    finish = clock();
    cout << "runtime: " << (finish - start) / CLK_TCK << "ms";
}

int fibo(int n, int* totZero, int* totOne) {
    if(n == 0) {
        (*totZero)++;
        return 0;
    } else if (n == 1) {
        (*totOne)++;
        return 1;
    } else {
        return fibo(n - 1, totZero, totOne) + fibo(n - 2, totZero, totOne);
    }
}