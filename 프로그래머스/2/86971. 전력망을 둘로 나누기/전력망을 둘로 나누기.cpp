#include <string>
#include <vector>

using namespace std;

int parent[101];

int findParent(int x) {
    if (parent[x] < 0) {
        return x;
    } else {
        return parent[x] = findParent(parent[x]);
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 101;
    for (int i = 0; i < wires.size(); i++) {
        fill(parent + 1, parent + n + 1, -1);
        for (int j = 0; j < wires.size(); j++) {
            if (i == j) {
                continue;
            }
            int p1 = findParent(wires[j][0]);
            int p2 = findParent(wires[j][1]);
            if (p1 < p2) {
                parent[p1] += parent[p2];
                parent[p2] = p1;
            } else {
                parent[p2] += parent[p1];
                parent[p1] = p2;
            }
        }
        int g1 = 0, g2 = 0;
        for (int i = 1; i < n + 1; i++) {
            if (parent[i] < 0) {
                if (g1 == 0) {
                    g1 = -parent[i];
                } else {
                    g2 = -parent[i];
                }
            }
        }
        answer = min(answer, abs(g1 - g2));
    }
    return answer;
}