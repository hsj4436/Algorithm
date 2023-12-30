#include <iostream>

#define LL long long

struct line {
    std::pair<LL, LL> p1;
    std::pair<LL, LL> p2;
    line() {
        p1 = {0, 0};
        p2 = {0, 0};
    }
    line(std::pair<LL, LL> p1, std::pair<LL, LL> p2) : p1(p1), p2(p2) {}
};

int N;
int parent[3001];
line lines[3001];

LL CCW(LL x1, LL y1, LL x2, LL y2, LL x3, LL y3) {
    long long ccw = x1 * y2 + x2 * y3 + x3 * y1 - y1 * x2 - y2 * x3 - y3 * x1;
    if (ccw > 0) {
        return 1;
    } else if (ccw == 0) {
        return 0;
    } else {
        return -1;
    }
}

int find_parent(int target) {
    if (parent[target] < 0) {
        return target;
    } else {
        return parent[target] = find_parent(parent[target]);
    }
}

int main() {
    std::cin >> N;

    for (int i = 1; i < N + 1; i++) {
        LL x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        parent[i] = -1;
        lines[i] = line({x1, y1}, {x2, y2});
    }

    for (int i = 1; i < N; i++) {
        for (int j = i + 1; j < N + 1; j++) {
            std::pair<LL, LL> p1 = lines[i].p1;
            std::pair<LL, LL> p2 = lines[i].p2;
            std::pair<LL, LL> p3 = lines[j].p1;
            std::pair<LL, LL> p4 = lines[j].p2;

            long long L1_L2 = CCW(p1.first, p1.second, p2.first, p2.second, p3.first, p3.second) * CCW(p1.first, p1.second, p2.first, p2.second, p4.first, p4.second);
            long long L2_L1 = CCW(p3.first, p3.second, p4.first, p4.second, p1.first, p1.second) * CCW(p3.first, p3.second, p4.first, p4.second, p2.first, p2.second);

            if (L1_L2 == 0 && L2_L1 == 0) {
                if (p1 > p2) {
                    std::swap(p1, p2);
                }
                if (p3 > p4) {
                    std::swap(p3, p4);
                }
                if (p1 <= p4 && p3 <= p2) {
                    // 겹침
                    int parent_i = find_parent(i);
                    int parent_j = find_parent(j);
                    if (parent_i != parent_j) {
                        if (parent[parent_i] < parent[parent_j]) {
                            parent[parent_i] += parent[parent_j];
                            parent[parent_j] = parent_i;
                        } else {
                            parent[parent_j] += parent[parent_i];
                            parent[parent_i] = parent_j;
                        }
                    }
                }
            } else if (L1_L2 <= 0 && L2_L1 <= 0) {
                // 겹침
                int parent_i = find_parent(i);
                int parent_j = find_parent(j);
                if (parent_i != parent_j) {
                    if (parent[parent_i] < parent[parent_j]) {
                        parent[parent_i] += parent[parent_j];
                        parent[parent_j] = parent_i;
                    } else {
                        parent[parent_j] += parent[parent_i];
                        parent[parent_i] = parent_j;
                    }
                }
            }
        }
    }

    int size = 0, max = 0;
    for (int i = 1; i < N + 1; i++) {
        if (parent[i] < 0) {
            size++;
            max = std::max(max, std::abs(parent[i]));
        }
    }

    std::cout << size << "\n" << max << "\n";

    return 0;
}
