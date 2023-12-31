#include <iostream>
#include <algorithm>

std::string ADD(std::string &a, std::string &b) {
    std::string result(std::max(a.size(), b.size()), '0');
    bool carry = false;
    for (int i = 0; i < result.size(); i++) {
        int temp = carry;
        carry = false;

        if (i < a.size()) {
            temp += a[a.size() - i - 1] - '0';
        }
        if (i < b.size()) {
            temp += b[b.size() - i - 1] - '0';
        }
        if (temp >= 10) {
            carry = true;
            temp -= 10;
        }
        result[result.size() - i - 1] = temp + '0';
    }
    if (carry) {
        result.insert(result.begin(), '1');
    }
    return result;
}

std::string MULTIPLY(std::string &a, std::string &b) {
    std::string result = "0";
    for (int i = 0; i < b.size(); i++) {
        std::string line(a);
        int carry = 0;
        for (int j = a.size() - 1; j >= 0; j--) {
            int temp = carry;
            carry = 0;
            temp += (a[j] - '0') * (b[b.size() - i - 1] - '0');
            if (temp >= 10) {
                carry = temp / 10;
                temp %= 10;
            }
            line[j] = temp + '0';
        }
        if (carry > 0) {
            line.insert(line.begin(), carry + '0');
        }
        line += std::string(i, '0');
        result = ADD(result, line);
    }
    return result;
}

std::string POW(std::string &a, int b) {
    if (b == 1) {
        return a;
    }

    std::string result = POW(a, b - 1);
    result = MULTIPLY(result, a);
    return result;
}

int main() {
    std::string a;
    int b;
    std::cin >> a >> b;

    auto it = std::find(a.begin(), a.end(), '.');
    int idx = a.end() - it - 1;
    a.erase(it);
    idx *= b;

    std::string result = POW(a, b);
    if (idx > 0) {
        result.insert(result.end() - idx, '.');
    }
    std::cout << result << "\n";
    return 0;
}
