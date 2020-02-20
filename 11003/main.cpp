#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

inline int init(vector<int>& a, vector<int>& tree, int node, int start, int end);
inline int find(vector<int>& tree, int node, int start, int end, int left, int right);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N{}, L{};
    cin >> N >> L;

    vector<int> a(N + 1),
            tree((1 << ((int)ceil(log2(N)) + 1)));
    for(int i = 0; i < N; ++i) {
        cin >> a[i + 1];
    }
    init(a, tree, 1, 1, N);


    for(int i = 1; i <= N; ++i) {
        if(i-L+1 >= 1) {
            cout << find(tree, 1, 1, N, i-L+1, i) << ' ';
        } else {
            cout << find(tree, 1, 1, N, 1, i) << ' ';
        }
    }

    return 0;
}

// FIXME: 재귀함수 반복문으로 바꾸기
inline int init(vector<int>& a, vector<int>& tree, int node, int start, int end) {
    if(start == end) {
        return tree[node] = a[start];
    } else {
        int left{init(a, tree, node * 2, start, (start + end) / 2)},
            right{init(a, tree, node * 2 + 1, (start + end) / 2 + 1 , end)};

        return tree[node] = min(left, right);
    }
}

inline int find(vector<int>& tree, int node, int start, int end, int left, int right) {
    if(left > end || right < start) {
        return numeric_limits<int>::max();
    }
    if(left <= start && end <= right) {
        return tree[node];
    }
    return min(find(tree, node * 2, start, (start + end) / 2, left, right),
           find(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}