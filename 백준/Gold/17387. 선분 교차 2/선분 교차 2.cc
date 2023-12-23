#include <iostream>

long long CCW(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
    long long ccw = x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3);
    if (ccw > 0) {
        return 1;
    } else if (ccw == 0) {
        return 0;
    } else {
        return -1;
    }
}

int main() {
    std::pair<long long, long long> p1, p2;
    std::cin >> p1.first >> p1.second >> p2.first >> p2.second;

    std::pair<long long, long long> p3, p4;
    std::cin >> p3.first >> p3.second >> p4.first >> p4.second;

    long long L1_L2 = CCW(p1.first, p1.second, p2.first, p2.second, p3.first, p3.second) * CCW(p1.first, p1.second, p2.first, p2.second, p4.first, p4.second);
    long long L2_L1 = CCW(p3.first, p3.second, p4.first, p4.second, p1.first, p1.second) * CCW(p3.first, p3.second, p4.first, p4.second, p2.first, p2.second);

    if (L1_L2 == 0 && L2_L1 == 0) {
        if (p1 > p2) {
            std::swap(p1, p2);
        }
        if (p3 > p4) {
            std::swap(p3, p4);
        }
        if (p1 <= p4 && p3 <= p2) {
            std::cout << "1";
        } else {
            std::cout << "0";
        }
        return 0;
    }

    if (L1_L2 <= 0 && L2_L1 <= 0) {
        std::cout << "1";
    } else {
        std::cout << "0";
    }
    return 0;
}
