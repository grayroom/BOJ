#include <iostream>

using namespace std;

int main() {
    int A{}, B{}, C{};

    cin >> A >> B >> C;

    if((A - B) * (C - B) <= 0) {
        cout << B;
    } else if ((A - C) * (B - C) <= 0) {
        cout << C;
    } else {
        cout << A;
    }

    return 0;
}
