#include <iostream>
#include <queue>
#include <map>

long long s, t;
std::map<long long, bool> used;

struct cmp {
    bool operator() (std::pair<long long, std::string> p1, std::pair<long long, std::string> p2) {
        if (p1.second.size() == p2.second.size()) {
            return p1.second > p2.second;
        } else {
            return p1.second.size() > p2.second.size();
        }
    }
};

int main() {
    std::cin >> s >> t;

    if (s == t) {
        std::cout << "0\n";
        return 0;
    }

    if (t == 1) {
        std::cout << "/\n";
        return 0;
    }

    std::priority_queue<std::pair<long long, std::string>, std::vector<std::pair<long long, std::string>>, cmp> trace;
    used[s] = true;
    trace.push({s, ""});

    while (!trace.empty()) {
        long long current_s = trace.top().first;
        std::string command = trace.top().second;
        trace.pop();

        if (current_s > 1000000000) {
            continue;
        }

        if (current_s == t) {
            std::cout << command << "\n";
            return 0;
        }

        if (!used[current_s * current_s]) {
            std::string multiply = command;
            multiply.push_back('*');
            used[current_s * current_s] = true;
            trace.push({current_s * current_s, multiply});
        }

        if (!used[2 * current_s]) {
            std::string plus = command;
            plus.push_back('+');
            used[2 * current_s] = true;
            trace.push({current_s + current_s, plus});
        }

        if (!used[current_s - current_s]) {
            std::string minus = command;
            minus.push_back('-');
            used[current_s - current_s] = true;
            trace.push({current_s - current_s, minus});
        }

        if (current_s != 0) {
            std::string divide = command;
            divide.push_back('/');
            if (!used[current_s / current_s]) {
                used[current_s / current_s] = true;
                trace.push({current_s / current_s, divide});
            }
        }
    }
    
    std::cout << "-1\n";
    return 0;
}
