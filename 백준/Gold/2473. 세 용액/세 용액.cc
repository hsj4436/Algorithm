#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<long long> PHs;

int main() {
    std::cin >> N;

    long long PH = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> PH;
        PHs.push_back(PH);
    }

    std::sort(PHs.begin(), PHs.end());

    long long diff_with_zero = 3000000001;
    int PH_index[3];
    for (int i = 0; i < N - 2; i++) {
        int left = i + 1, right = N - 1;
        long long last_diff = 3000000001;
        int tmp_index[3];
        tmp_index[0] = i;
        while (left < right) {
            long long sum = PHs[i] + PHs[left] + PHs[right];

            if (std::abs(sum) < std::abs(last_diff)) {
                last_diff = sum;
                tmp_index[1] = left;
                tmp_index[2] = right;
            }
            if (sum > 0) {
                right--;
            } else {
                left++;
            }
        }

        long long diff = 0;
        for (int j = 0; j < 3; j++) {
            diff += PHs[tmp_index[j]];
        }
        if (std::abs(diff) < std::abs(diff_with_zero)) {
            diff_with_zero = diff;
            PH_index[0] = tmp_index[0];
            PH_index[1] = tmp_index[1];
            PH_index[2] = tmp_index[2];
        }

    }

    for (int i = 0; i < 3; i++) {
        std::cout << PHs[PH_index[i]] << " ";
    }
    std::cout << "\n";

    return 0;
}
