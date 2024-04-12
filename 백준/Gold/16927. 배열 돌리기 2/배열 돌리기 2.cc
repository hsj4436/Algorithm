#include <iostream>
#include <vector>

int N, M, R;
int origin[301][301];

int GCD(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return GCD(b, a % b);
    }
}

int LCM(int a, int b) {
    return (a * b) / GCD(a, b);
}

int main() {
    std::cin >> N >> M >> R;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> origin[i][j];
        }
    }

    int layers = std::min(N, M) / 2 - 1;
    std::vector<int> rotateCycles;
    int layerZero = (N + M) * 2 - 4;
    rotateCycles.push_back(layerZero);
    int layerCopy = layers;
    while (layerCopy > 0) {
        layerZero -= 8;
        layerCopy--;
        rotateCycles.push_back(layerZero);
    }

//    int cycle = rotateCycles[0];
//    for (int i = 1; i < rotateCycles.size(); i++) {
//        cycle = LCM(cycle, rotateCycles[i]);
//    }
//
//    R %= cycle;

    for (int layer = 0; layer < layers + 1; layer++) {
        if (R % rotateCycles[layer] == 0) {
            continue;
        }
        int localR = R % rotateCycles[layer];
        for (int r = 0; r < localR; r++) {
            int temp = 0;
            for (int i = M - 1 - layer; i > layer - 1; i--) {
                std::swap(temp, origin[layer][i]);
            }
            for (int i = layer + 1; i < N - layer; i++) {
                std::swap(temp, origin[i][layer]);
            }
            for (int i = layer + 1; i < M - layer; i++) {
                std::swap(temp, origin[N - 1 - layer][i]);
            }
            for (int i = N - 1 - layer - 1; i > layer - 1; i--) {
                std::swap(temp, origin[i][M - 1 - layer]);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cout << origin[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
