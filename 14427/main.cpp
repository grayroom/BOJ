#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int init(vector<int>& a, vector<int>& tree, int node, int start, int end);
int getMin(vector<int>& tree, int node, int start, int end, int left, int right);
void update(vector<int>& tree, int node, int start, int end, int index, int newVal);

int main() {
    int N{};
    scanf("%d", &N);

    int h{(int)ceil(log2(N))};
    int tree_size = (1 << (h + 1));

    vector<int> a(N + 1),
            tree(tree_size);
    for(int i = 0; i < N; ++i) {
        scanf("%d", &a[i + 1]);
    }
    init(a, tree, 1, 1, N);

    int M{};
    scanf("%d", &M);

    while(M--) {
        int query{}, left{}, right{}, diff{};
        scanf("%d %d %d", &query, &left, &right);

        switch(query) {
            case 1: {
                update(tree, 1, 1, N, left, right);
            } break;
            case 2: {
                cout << getMin(tree, 1, 1, N, left, right);
            } break;
            default: break;
        }
    }

    return 0;
}

int init(vector<int>& a, vector<int>& tree, int node, int start, int end) {
    if(start == end) {
        return tree[node] = a[start] % 2;
    } else {
        return tree[node] = min(init(a, tree, node * 2, start, (start + end) / 2),
                            init(a, tree, node * 2 + 1, (start + end) / 2 + 1 , end));
    }
}

int getMin(vector<int>& tree, int node, int start, int end, int left, int right) {
    if(left > end || right < start) {
        return numeric_limits<int>::max();
    }
    if(left <= start && end <= right) {
        return tree[node];
    }
    return min(getMin(tree, node * 2, start, (start + end) / 2, left, right),
               getMin(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

void update(vector<int>& tree, int node, int start, int end, int index, int newVal) {
    if(index < start || index > end) {
        return;
    }

    if(newVal < tree[node]) {
        tree[node] = newVal;
    }

    if(start != end) {
        update(tree, node * 2, start, (start + end) / 2, index, newVal);
        update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, newVal);
    }
}