#include <iostream>

int N, M;
int arr[100001];
int tree[400004];

int init(int start, int end, int node) {
    if (start == end) {
        return tree[node] = arr[start];
    }

    int mid = (start + end) / 2;
    int leftNode = init(start, mid, node * 2);
    int rightNode = init(mid + 1, end, node * 2 + 1);
    return tree[node] = std::min(leftNode, rightNode);
}

int update(int start, int end, int node, int index, int number) {
    if (index < start || end < index) {
        return tree[node];
    }

    if (start == end) {
        return tree[node] = number;
    }

    int mid = (start + end) / 2;
    int leftNode = update(start, mid, node * 2, index, number);
    int rightNode = update(mid + 1, end, node * 2 + 1, index, number);
    return tree[node] = std::min(leftNode, rightNode);
}

int query(int start, int end, int node, int left, int right) {
    if (end < left || right < start) {
        return 1000000001;
    }

    if (left <= start && end <= right) {
        return tree[node];
    }

    if (start == end) {
        return tree[node];
    }

    int mid = (start + end) / 2;
    int leftNode = query(start, mid, node * 2, left, right);
    int rightNode = query(mid + 1, end, node * 2 + 1, left, right);
    return std::min(leftNode, rightNode);
}

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> N;

    for (int i = 1; i < N + 1; i++) {
        std::cin >> arr[i];
    }

    init(1, N, 1);

    std::cin >> M;
    for (int i = 0; i < M; i++) {
        int Q, I, J;
        std::cin >> Q;
        if (Q == 1) {
            std::cin >> I >> J;
            update(1, N, 1, I, J);
        } else {
            std::cin >> I >> J;
            std::cout << query(1, N, 1, I, J) << "\n";
        }
    }
    return 0;
}
