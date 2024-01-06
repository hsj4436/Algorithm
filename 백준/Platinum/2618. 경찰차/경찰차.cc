#include <iostream>
#include <vector>
#include <cstring>

int N, W;

std::pair<int, int> cases[1001];
int dp[1001][1001];

int get_max_distance(int A, int B) {
    if (A == W || B == W) {
        return 0;
    }

    if (dp[A][B] != -1) {
        return dp[A][B];
    }

    int next_case = std::max(A, B) + 1;
    int distance_A, distance_B;
    if (A == 0) {
        distance_A = std::abs(cases[next_case].first - 1) + std::abs(cases[next_case].second - 1);         
    } else {
        distance_A = std::abs(cases[next_case].first - cases[A].first) + std::abs(cases[next_case].second - cases[A].second);
    }
    
    if (B == 0) {
        distance_B = std::abs(cases[next_case].first - N) + std::abs(cases[next_case].second - N);
    } else {
        distance_B = std::abs(cases[next_case].first - cases[B].first) + std::abs(cases[next_case].second - cases[B].second);
    }

    int ret_A = get_max_distance(next_case, B) + distance_A;
    int ret_B = get_max_distance(A, next_case) + distance_B;
    dp[A][B] = std::min(ret_A, ret_B);
    return dp[A][B];
}

void get_route(int A, int B) {
    if (A == W || B == W) {
        return;
    }

    int next_case = std::max(A, B) + 1;
    int distance_A, distance_B;
    if (A == 0) {
        distance_A = std::abs(cases[next_case].first - 1) + std::abs(cases[next_case].second - 1);
    } else {
        distance_A = std::abs(cases[next_case].first - cases[A].first) + std::abs(cases[next_case].second - cases[A].second);
    }

    if (B == 0) {
        distance_B = std::abs(cases[next_case].first - N) + std::abs(cases[next_case].second - N);
    } else {
        distance_B = std::abs(cases[next_case].first - cases[B].first) + std::abs(cases[next_case].second - cases[B].second);
    }
    
    int ret_A = get_max_distance(next_case, B) + distance_A;
    int ret_B = get_max_distance(A, next_case) + distance_B;

    if (ret_A > ret_B) {
        std::cout << 2 << "\n";
        get_route(A, next_case);
    } else {
        std::cout << 1 << "\n";
        get_route(next_case, B);
    }
}

int main() {
    std::cin >> N >> W;

    std::memset(dp,-1, sizeof(dp));
    
    for (int i = 1; i < W + 1; i++) {
        std::cin >> cases[i].first >> cases[i].second;
    }

    std::cout << get_max_distance(0, 0) << "\n";
    get_route(0, 0);

    return 0;
}
