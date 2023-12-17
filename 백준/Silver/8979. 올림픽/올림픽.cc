#include <iostream>
#include <queue>

struct country {
    int number;
    int gold;
    int silver;
    int bronze;
    country(int number, int gold, int silver, int bronze) {
        this->number = number;
        this->gold = gold;
        this->silver = silver;
        this->bronze = bronze;
    }
};

struct cmp {
    bool operator () (country c1, country c2) {
        if (c1.gold == c2.gold) {
            if (c1.silver == c2.silver) {
                if (c1.bronze == c2.bronze) {
                    return c1.number > c2.number;
                } else {
                    return c1.bronze < c2.bronze;
                }
            } else {
                return c1.silver < c2.silver;
            }
        } else {
            return c1.gold < c2.gold;
        }
    }
};

int N, K;

int main() {
    std::cin >> N >> K;

    std::priority_queue<country, std::vector<country>, cmp> pq;

    for (int i = 0; i < N; i++) {
        int number, gold, silver, bronze;
        std::cin >> number >> gold >> silver >> bronze;
        pq.push(country(number, gold, silver, bronze));
    }

    int rank = 0;
    country last = country(0, 0, 0, 0);
    int same_streak = 0;
    while (!pq.empty()) {
        country current = pq.top();
        pq.pop();
        if (!(last.gold == current.gold && last.silver == current.silver && last.bronze == current.bronze)) {
            if (same_streak == 0) {
                rank++;
            } else {
                rank += same_streak + 1;
                same_streak = 0;
            }
        } else {
            same_streak++;
        }
        last = current;
        if (current.number == K) {
            std::cout << rank << "\n";
            break;
        }
    }
    return 0;
}
