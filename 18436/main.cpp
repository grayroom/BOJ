#include <iostream>
#include <vector>

using namespace std;

int init(vector<int>& a, vector<int>& tree, int node, int start, int end);
int sum(vector<int>& tree, int node, int start, int end, int left, int right);
void update(vector<int>& tree, int node, int start, int end, int index, int diff);

int main() {
    int N{};
    scanf("%d", &N);

    vector<int> a(N + 1),
                tree(2 * N);
    for(int i = 1; i <= N; ++i) { // 배열 a를 tree 형태로 접근하기 위해 index가 0인 원소는 사용하지 않는다.
        scanf("%d", &a[i]);
    }
    init(a, tree, 1, 1, N);

    int M{};
    scanf("%d", &M);

    while(M--) {
        int query{}, left{}, right{};
        scanf("%d %d %d", &query, &left, &right);

        switch(query) {
            case 1: {
                update(tree, 1, 1, N + 1, left, right % 2 - tree[left] % 2);
            } break;
            case 2: {
                printf("%d\n", right - left + 1 - sum(tree, 1, 1, N, left, right));
            } break;
            case 3: {
                printf("%d\n", sum(tree, 1, 1, N, left, right));
            } break;
            default: break;
        }
    }

    return 0;
}

int init(vector<int>& a, vector<int>& tree, int node, int start, int end) {
    if(start == end) { // leaf node에는 해당원소가 짝수인지 여부를 저장한다.
        return tree[node] = a[start] % 2; // num % 2가 1이라면 홀수, 0이라면 짝수
    } else { // leaf node가 아닌 node에는 자식 node 중, "홀수인 node의 개수"가 저장된다.
        return tree[node] = init(a, tree, node * 2, start, (start + end) / 2) +
                            init(a, tree, node * 2 + 1, (start + end) / 2 + 1 , end);
    }
}

int sum(vector<int>& tree, int node, int start, int end, int left, int right) {
    if(left > end || right < start) {
        return 0;
    }
    if(left <= start && end <= right) {
        return tree[node];
    }
    return sum(tree, node * 2, start, (start + end) / 2, left, right) +
           sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update(vector<int>& tree, int node, int start, int end, int index, int diff) {
    if(index < start || index > end) {
        return;
    }

    tree[node] += diff;

    if(start != end) {
        update(tree, node * 2, start, (start + end) / 2, index, diff);
        update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
    }
}