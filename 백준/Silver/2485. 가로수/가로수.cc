#include <iostream>
#include <vector>

int N;
std::vector<int> trees;
std::vector<int> diffs;

int GCD(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return GCD(b, a % b);
    }
}

int main() {
    std::cin >> N;

    int tree = 0;
    std::cin >> tree;
    trees.push_back(tree);
    for (int i = 1; i < N; i++) {
        std::cin >> tree;
        trees.push_back(tree);
        diffs.push_back(trees[i] - trees[i - 1]);
    }

    int gcd = GCD(diffs[0], diffs[1]);
    for (int i = 2; i < diffs.size(); i++) {
        gcd = GCD(gcd, diffs[i]);
    }

    int cur = trees[0];
    int answer = 0;
    for (int i = 1; i < trees.size(); i++) {
        while (trees[i] - cur > gcd) {
            cur += gcd;
            answer++;
        }
        cur = trees[i];
    }

    std::cout << answer << "\n";
    return 0;
}