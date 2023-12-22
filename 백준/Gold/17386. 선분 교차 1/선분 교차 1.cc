#include <iostream>

long long CCW(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
   if (x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3) < 0) {
       return 1;
   } else {
       return -1;
   }
}

int main() {
    long long x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    
    long long x3, y3, x4, y4;
    std::cin >> x3 >> y3 >> x4 >> y4;

    long long L1_L2 = CCW(x1, y1, x2, y2, x3, y3) * CCW(x1, y1, x2, y2, x4, y4);
    long long L2_L1 = CCW(x3, y3, x4, y4, x1, y1) * CCW(x3, y3, x4, y4, x2, y2);
    if (L1_L2 <= 0 && L2_L1 <= 0) {
        std::cout << "1";
    } else {
        std::cout << "0";
    }

    return 0;
}
