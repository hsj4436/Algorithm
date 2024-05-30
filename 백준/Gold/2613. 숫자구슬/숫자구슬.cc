#include <iostream>
#include <vector>

int N, M;
int arr[301];
int maxValue = 30001;
std::vector<int> answer;
std::vector<int> tempGroupSIze;
std::vector<int> temp;

void init() {
    temp.clear();
    temp.resize(M);
    for (int &i : temp) {
        i = 0;
    }

    tempGroupSIze.clear();
    tempGroupSIze.resize(M);
    for (int &i : tempGroupSIze) {
        i = 0;
    }
}

void makeSeparate(int max) {
    init();

    int groupIndex = 0;
    for (int i = 0; i < N; i++) {
        if (groupIndex == M - 1) {
            temp[groupIndex] += arr[i];
            tempGroupSIze[groupIndex]++;
            continue;
        }
        if (N - i == M - groupIndex - 1) {
            groupIndex++;
            temp[groupIndex] = arr[i];
            tempGroupSIze[groupIndex]++;
            continue;
        }
        if (temp[groupIndex] + arr[i] > max) {
            groupIndex++;
            temp[groupIndex] = arr[i];
            tempGroupSIze[groupIndex]++;
        } else {
            temp[groupIndex] += arr[i];
            tempGroupSIze[groupIndex]++;
        }
    }
}


int main() {
    std::cin >> N >> M;

    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    int left = 1, right = 60000;
    while (left <= right) {
        int mid = (left + right) / 2;
        makeSeparate(mid);

        int maxTempValue = 0;
        for (int i : temp) {
            maxTempValue = std::max(maxTempValue, i);
        }
        if (maxTempValue <= mid) {
            if (maxTempValue < maxValue) {
                answer = tempGroupSIze;
                maxValue = maxTempValue;
            }
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    std::cout << maxValue << "\n";
    for (int i : answer) {
        std::cout << i << " ";
    }

    return 0;
}
