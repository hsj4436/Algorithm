#include <iostream>
#include <vector>
#include <map>

int T, N;

int main() {
    std::cin >> T;

    for (int tc = 0; tc < T; tc++) {
        std::cin >> N;

        int answer = 9;
        std::map<std::string, int> MBTIs;
        std::vector<std::string> MBTI_vector;
        for (int i = 0; i < N; i++) {
            std::string MBTI;
            std::cin >> MBTI;
            if (MBTIs[MBTI] == 3) {
                answer = 0;
                continue;
            }
            MBTIs[MBTI]++;
        }

        if (answer == 0) {
            std::cout << answer << "\n";
            continue;
        }

        for (auto p : MBTIs) {
            for (int i = 0; i < p.second; i++) {
                MBTI_vector.push_back(p.first);
            }
        }

        for (int i = 0; i < MBTI_vector.size() - 2; i++) {
            for (int j = i + 1; j < MBTI_vector.size() - 1; j++) {
                for (int k = j + 1; k < MBTI_vector.size(); k++) {
                    int diff_ab = 0, diff_ac = 0, diff_bc = 0;
                    for (int index = 0; index < 4; index++) {
                        if (MBTI_vector[i][index] != MBTI_vector[j][index]) {
                            diff_ab++;
                        }
                    }
                    for (int index = 0; index < 4; index++) {
                        if (MBTI_vector[i][index] != MBTI_vector[k][index]) {
                            diff_ac++;
                        }
                    }
                    for (int index = 0; index < 4; index++) {
                        if (MBTI_vector[j][index] != MBTI_vector[k][index]) {
                            diff_bc++;
                        }
                    }
                    answer = std::min(answer, diff_ab + diff_ac + diff_bc);
                }
            }
        }

        std::cout << answer << "\n";
    }
    return 0;
}
