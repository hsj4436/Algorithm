#include <iostream>
#include <queue>

int A, B, C;
bool visited[1501][1501];

struct stones {
    int A;
    int B;
    int C;
    stones(int A, int B, int C) {
        this->A = A;
        this->B = B;
        this->C = C;
    }
};

bool bfs() {
    std::queue<stones> trace;
    if (A < B) {
        visited[A][B] = true;
    } else {
        visited[B][A] = true;
    }
    if (B < C) {
        visited[B][C] = true;
    } else {
        visited[C][B] = true;
    }
    if (A < C) {
        visited[A][C] = true;
    } else {
        visited[C][A] = true;
    }
    trace.push(stones(A, B, C));

    while (!trace.empty()) {
        stones current = trace.front();
        trace.pop();

        if (current.A == current.B && current.A == current.C && current.B == current.C) {
            return true;
        }

        if (current.A != current.B) {
            if (current.A < current.B) {
                int new_A = current.A * 2;
                int new_B = current.B - current.A;
                if (new_A < new_B) {
                    if (!visited[new_A][new_B]) {
                        visited[new_A][new_B] = true;
                        trace.push(stones(new_A, new_B, current.C));
                    }
                } else {
                    if (!visited[new_B][new_A]) {
                        visited[new_B][new_A] = true;
                        trace.push(stones(new_A, new_B, current.C));
                    }
                }
            } else {
                int new_A = current.A - current.B;
                int new_B = current.B * 2;
                if (new_A < new_B) {
                    if (!visited[new_A][new_B]) {
                        visited[new_A][new_B] = true;
                        trace.push(stones(new_A, new_B, current.C));
                    }
                } else {
                    if (!visited[new_B][new_A]) {
                        visited[new_B][new_A] = true;
                        trace.push(stones(new_A, new_B, current.C));
                    }
                }
            }
        }
        if (current.A != current.C) {
            if (current.A < current.C) {
                int new_A = current.A * 2;
                int new_C = current.C - current.A;
                if (new_A < new_C) {
                    if (!visited[new_A][new_C]) {
                        visited[new_A][new_C] = true;
                        trace.push(stones(new_A, current.B, new_C));
                    }
                } else {
                    if (!visited[new_C][new_A]) {
                        visited[new_C][new_A] = true;
                        trace.push(stones(new_A, current.B, new_C));
                    }
                }
            } else {
                int new_A = current.A - current.C;
                int new_C = current.C * 2;
                if (new_A < new_C) {
                    if (!visited[new_A][new_C]) {
                        visited[new_A][new_C] = true;
                        trace.push(stones(new_A, current.B, new_C));
                    }
                } else {
                    if (!visited[new_C][new_A]) {
                        visited[new_C][new_A] = true;
                        trace.push(stones(new_A, current.B, new_C));
                    }
                }
            }
        }
        if (current.B != current.C) {
            if (current.B < current.C) {
                int new_B = current.B * 2;
                int new_C = current.C - current.B;
                if (new_B < new_C) {
                    if (!visited[new_B][new_C]) {
                        visited[new_B][new_C] = true;
                        trace.push(stones(current.A, new_B, new_C));
                    }
                } else {
                    if (!visited[new_C][new_B]) {
                        visited[new_C][new_B] = true;
                        trace.push(stones(current.A, new_B, new_C));
                    }
                }
            } else {
                int new_B = current.B - current.C;
                int new_C = current.C * 2;
                if (new_B < new_C) {
                    if (!visited[new_B][new_C]) {
                        visited[new_B][new_C] = true;
                        trace.push(stones(current.A, new_B, new_C));
                    }
                } else {
                    if (!visited[new_C][new_B]) {
                        visited[new_C][new_B] = true;
                        trace.push(stones(current.A, new_B, new_C));
                    }
                }
            }
        }
    }

    return false;
}

int main() {
    std::cin >> A >> B >> C;

    if ((A + B + C) % 3 != 0) {
        std::cout << "0\n";
        return 0;
    }

    if (bfs()) {
        std::cout << "1\n";
    } else {
        std::cout << "0\n";
    }

    return 0;
}
