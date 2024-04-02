#include <iostream>

#define PII std::pair<int, int>

int N, M;
int arr[100001];
PII tree[400004];

PII init(int start, int end, int node) {
    if (start == end) {
        return tree[node] = {arr[start], start};
    }

    int mid = (start + end) / 2;
    PII leftTree = init(start, mid, node * 2);
    PII rightTree = init(mid + 1, end, node * 2 + 1);
    return tree[node] = std::min(leftTree, rightTree);
}

PII update(int start, int end, int node, int index, int target) {
    if (start == end) {
        tree[node].first = target;
        return tree[node];
    }

    if (start != end) {
        int mid = (start + end) / 2;
        PII leftTree = tree[node * 2];
        if (start <= index && index <= mid) {
            leftTree = update(start, mid, node * 2, index, target);
        }
        PII rightTree = tree[node * 2 + 1];
        if (mid + 1 <= index && index <= end) {
            rightTree = update(mid + 1, end, node * 2 + 1, index, target);
        }
        return tree[node] = std::min(leftTree, rightTree);
    }
}

PII query(int start, int end, int node, int left, int right) {
    if (end < left || right < start) {
        return {1000000001, 1000000001};
    }

    if (left <= start && end <= right) {
        return tree[node];
    }

    int mid = (start + end) / 2;
    PII leftTree = query(start, mid, node * 2, left, right);
    PII rightTree = query(mid + 1, end, node * 2 + 1, left, right);
    return std::min(leftTree, rightTree);
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
    int command, leftHand, rightHand;
    for (int i = 0; i < M; i++) {
        std::cin >> command >> leftHand >> rightHand;
        if (command == 1) {
            update(1, N, 1, leftHand, rightHand);
        } else {
            std::cout << query(1, N, 1, leftHand, rightHand).second << "\n";
        }
    }

    return 0;
}
