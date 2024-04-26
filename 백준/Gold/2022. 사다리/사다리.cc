#include <iostream>
#include <math.h>

double X, Y, C;

int main() {
    std::cin >> X >> Y >> C;

    double xPower = std::pow(X, 2);
    double yPower = std::pow(Y, 2);

    double answer = 0.0;
    double left = 1.0, right = std::min(X, Y);
    while (left <= right) {
        double mid = (left + right) / 2;
        double midPower = std::pow(mid, 2);
        double xHeight = std::sqrt(xPower - midPower);
        double yHeight = std::sqrt(yPower - midPower);
        double c = (xHeight * yHeight) / (xHeight + yHeight);
        if (std::abs(C - c) <= 0.0001) {
            answer = mid;
            break;
        }
        if (c <= C) {
            right = mid;
            answer = right;
        } else if (c > C) {
            left = mid;
        }
    }

    std::cout << answer << "\n";

    return 0;
}
