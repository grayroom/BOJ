#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

inline void build(vector<int>& tree, int N);
inline int getMin(vector<int>&tree, int N, int left, int right);


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N{}, L{};
    cin >> N >> L;

    vector<int> tree(2 * N);
    for(int i = 0; i < N; ++i) {
        cin >> tree[N + i];
    }
    build(tree, N);

    for(int i = 0; i < N; ++i) {
        if(i - L + 1 >= 0) {
            cout << getMin(tree, N, i - L + 1, i) << ' ';
        } else {
            cout << getMin(tree, N, 0, i) << ' ';
        }
    }
}

inline void build(vector<int>& tree, int N) {
    for(int i = N - 1; i > 0; --i) {
        tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
    }
}

inline int getMin(vector<int>& tree, int N, int left, int right) {
    int res = numeric_limits<int>::max();

    for(left += N, right += N; left <= right; left >>= 1, right >>= 1) {
        if(left == right) {
            return res = min(res, tree[left]);
        }
        if(left % 2 == 1) {
            res = min(res, tree[left++]);
        }
        if(right % 2 == 0) {
            res = min(res, tree[right--]);
        }
    }

    return res;
}