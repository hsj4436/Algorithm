#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int n;
int k;

struct jem {
    int weight;
    int value;

    jem(int weight, int value) {
        this->weight = weight;
        this->value = value;
    }
};

bool cmp(jem a, jem b) {
    if (a.value == b.value) {
        return a.weight < b.weight;
    } else {
        return a.value > b.value;
    }
}

std::multiset<int> bag;

int main() {
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> n >> k;

    std::vector<jem> vec;

    for (int i = 0; i < n; i++) {
        int w, v;
        std::cin >> w >> v;
        vec.push_back({w, v});
    }

    std::sort(vec.begin(), vec.end(), cmp);

    for (int i = 0; i < k; i++) {
        int capacity = 0;
        std::cin >> capacity;
        bag.insert(capacity);
    }

    unsigned long long sum = 0;
    for (int i = 0; i < n; i++) {
        jem cur = vec[i];
        auto it = bag.lower_bound(cur.weight);
        if (it == bag.end()) {
            continue;
        }

        sum += cur.value;
        bag.erase(it);

        if (bag.empty()) {
            break;
        }
    }

    std::cout << sum << "\n";

    return 0;
}
