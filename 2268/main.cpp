#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int init(int* a, int* tree, int node, int start, int end);
long long sum(int* tree, int node, int start, int end, int left, int right);
void update(int* tree, int node, int start, int end, int index, int diff);

int main() {
    int N{}, M{};
    scanf("%d %d", &N, &M);

    int h{(int)ceil(log2(N))};
    int tree_size = (1 << (h + 1));

    int* a = new int[N + 1]{};
    int* tree = new int[tree_size + 1]{};
    // for(int i = 0; i < N; ++i) {
    //     scanf("%lld", &a[i + 1]);
    // }
    init(a, tree, 1, 1, N);

    while(M--) {
        int query{};
        scanf("%d", &query);

        switch(query) {
            case 0: {
                int left{}, right{};
                scanf("%d %d", &left, &right);
                if(right < left) {
                    swap(left, right);
                }
                printf("%lld\n", sum(tree, 1, 1, N, left, right));
            } break;
            case 1: {
                int index{}, newVal{};
                scanf("%d %d", &index, &newVal);
                update(tree, 1, 1, N, index, newVal - a[index]);
                a[index] = newVal;
            } break;
            default: break;
        }
    }

    return 0;
}

int init(int* a, int* tree, int node, int start, int end) {
    if(start == end) {
        return tree[node] = a[start];
    } else {
        return tree[node] = init(a, tree, node * 2, start, (start + end) / 2) +
                            init(a, tree, node * 2 + 1, (start + end) / 2 + 1 , end);
    }
}

long long sum(int* tree, int node, int start, int end, int left, int right) {
    if(left > end || right < start) {
        return 0;
    }
    if(left <= start && end <= right) {
        return tree[node];
    }
    return sum(tree, node * 2, start, (start + end) / 2, left, right) +
           sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update(int* tree, int node, int start, int end, int index, int diff) {
    if(index < start || index > end) {
        return;
    }

    tree[node] += diff;

    if(start != end) {
        update(tree, node * 2, start, (start + end) / 2, index, diff);
        update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
    }
}