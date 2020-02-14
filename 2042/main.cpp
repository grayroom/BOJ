#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

long long init(vector<long long>& a, vector<long long>& tree, int node, int start, int end);
long long sum(vector<long long>& tree, int node, int start, int end, int left, int right);
void update(vector<long long>& tree, int node, int start, int end, int index, long long diff);

int main() {
    int N{}, M{}, K{};
    scanf("%d %d %d", &N, &M, &K);
    M += K;

    int h{(int)ceil(log2(N))};
    int tree_size = (1 << (h + 1));

    vector<long long> a(N + 1),
                      tree(tree_size + 1);
    for(int i = 0; i < N; ++i) {
        scanf("%lld", &a[i + 1]);
    }
    init(a, tree, 1, 1, N);

    while(M--) {
        int query{};
        scanf("%d", &query);

        switch(query) {
            case 1: {
                int index{};
                long long newVal{};
                scanf("%d %lld", &index, &newVal);
                update(tree, 1, 1, N, index, newVal - a[index]);
                a[index] = newVal;
            } break;
            case 2: {
                int left{}, right{};
                scanf("%d %d", &left, &right);
                printf("%lld\n", sum(tree, 1, 1, N, left, right));
            } break;
            default: break;
        }
    }

    return 0;
}

long long init(vector<long long>& a, vector<long long>& tree, int node, int start, int end) {
    if(start == end) {
        return tree[node] = a[start];
    } else {
        return tree[node] = init(a, tree, node * 2, start, (start + end) / 2) +
                            init(a, tree, node * 2 + 1, (start + end) / 2 + 1 , end);
    }
}

long long sum(vector<long long>& tree, int node, int start, int end, int left, int right) {
    if(left > end || right < start) {
        return 0;
    }
    if(left <= start && end <= right) {
        return tree[node];
    }
    return sum(tree, node * 2, start, (start + end) / 2, left, right) +
           sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update(vector<long long>& tree, int node, int start, int end, int index, long long diff) {
    if(index < start || index > end) {
        return;
    }

    tree[node] += diff;

    if(start != end) {
        update(tree, node * 2, start, (start + end) / 2, index, diff);
        update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
    }
}