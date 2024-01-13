#include <iostream>
#include <vector>

int N, taesu, P;
std::vector<int> scores;

int main() {
    std::cin >> N >> taesu >> P;
    int score;
    bool inserted = false;
    for (int i = 0; i < N; i++) {
        std::cin >> score;
        if (!inserted && score < taesu) {
            scores.push_back(taesu);
            inserted = true;
        }
        scores.push_back(score);
    }
    if (N == 0) {
        std::cout << "1\n";
        return 0;
    }
    if (N < P && !inserted) {
        scores.push_back(taesu);
        inserted = true;
    }
    if (!inserted) {
        std::cout << "-1\n";
        return 0;
    }

    int last = 2000000001;
    int rank = 0;
    int streak = 0;
    for (int i = 0; i < P; i++) {
        if (scores[i] < last) {
            last = scores[i];
            if (streak != 0) {
                rank += streak + 1;
                streak = 0;
            } else {
                rank += 1;
            }
            if (scores[i] == taesu) {
                break;
            }
        } else if (scores[i] == last) {
            streak++;
        }
    }

    if (rank != 0) {
        std::cout << rank << "\n";
    } else {
        std::cout << "-1\n";
    }

    return 0;
}
