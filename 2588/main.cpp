#include <iostream>

using namespace std;


int main() {
    int lhs{}, rhs{};
    cin >> lhs >> rhs;

    cout << lhs * (rhs % 10) << endl
         << lhs * (rhs % 100 / 10) << endl
         << lhs * (rhs % 1000 / 100) << endl
         << lhs * rhs << endl;

    return 0;
}
