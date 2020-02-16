#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int init(vector<int>& a, vector<int>& tree, int node, int start, int end);
void update(vector<int>& tree, vector<int>& a, int node, int start, int end, int index, int val);

int main() {
    int N{};
    scanf("%d", &N);

    int h{(int)ceil(log2(N))};
    int tree_size = (1 << (h + 1));

    vector<int> a(N + 1),
            tree(tree_size);
    for(int i = 0; i < N; ++i) { // 배열 a를 tree 형태로 접근하기 위해 index가 0인 원소는 사용하지 않는다.
        scanf("%d", &a[i + 1]);
    }
    init(a, tree, 1, 1, N);

    int M{};
    scanf("%d", &M);

    while(M--) {
        int query{};
        scanf("%d", &query);

        switch(query) {
            case 1: {
                int index{}, newVal{};
                scanf("%d %d", &index, &newVal);
                a[index] = newVal;
                update(tree, a, 1, 1, N, index, newVal);
            } break;
            case 2: {
                printf("%d\n", tree[1]);
            } break;
            default: break;
        }
    }

    return 0;
}

int init(vector<int>& a, vector<int>& tree, int node, int start, int end) {
    if(start == end) { // leaf node에는 해당원소가 짝수인지 여부를 저장한다.
        return tree[node] = start;
    } else { // leaf node가 아닌 node에는 자식 node 중, "홀수인 node의 개수"가 저장된다.
        int left{init(a, tree, node * 2, start, (start + end) / 2)},
            right{init(a, tree, node * 2 + 1, (start + end) / 2 + 1 , end)};

        if(a[left] > a[right]) {
            return tree[node] = right;
        } else if(a[right] > a[left]) {
            return tree[node] = left;
        } else {
            return tree[node] = min(left, right);
        }
    }
}

void update(vector<int>& tree, vector<int>& a, int node, int start, int end, int index, int val) {
    if(index < start || index > end) {
        return;
    }

    if(val < a[node]) {
        tree[node] = index;
    }

    if(start != end) {
        update(tree, a, node * 2, start, (start + end) / 2, index, val);
        update(tree, a, node * 2 + 1, (start + end) / 2 + 1, end, index, val);
    }
}