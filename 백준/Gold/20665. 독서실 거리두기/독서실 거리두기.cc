#include <iostream>
#include <algorithm>

#define PII std::pair<int, int>

int N, T, P;
PII users[501];
int seats[101];

void clear(int cur) {
    for (int i = 1; i < N + 1; i++) {
        if (seats[i] <= cur) {
            seats[i] = 0;
        }
    }
}

void get_seat(int index) {
    int last_seat = 0;
    int max_dist = 0;
    int seat_number = 0;
    for (int i = 1; i < N + 1; i++) {
        if (seats[i] != 0) {
            if (last_seat == 0) {
                if (i == 1) {
                    last_seat = i;
                } else {
                    last_seat = i;
                    int dist = i - 1;
                    if (dist > max_dist) {
                        max_dist = dist;
                        seat_number = 1;
                    }
                }
            } else {
                int dist = (i - last_seat) / 2;
                if (dist > max_dist) {
                    max_dist = dist;
                    seat_number = last_seat + dist;
                }
                last_seat = i;
            }
        } else if (i == N) {
            if (last_seat == 0) {
                seats[1] = users[index].second;
                return;
            } else {
                int dist = i - last_seat;
                if (dist > max_dist) {
                    max_dist = dist;
                    seat_number = last_seat + dist;
                }
                last_seat = i;
            }
        }
    }
    seats[seat_number] = users[index].second;
}

int main() {
    std::cin >> N >> T >> P;

    std::string in, out;
    for (int i = 0; i < T; i++) {
        std::cin >> in >> out;
        int in_number = ((in[0] - '0') * 10 + (in[1] - '0')) * 60 + (in[2] - '0') * 10 + (in[3] - '0');
        int out_number = ((out[0] - '0') * 10 + (out[1] - '0')) * 60 + (out[2] - '0') * 10 + (out[3] - '0');
        users[i] = {in_number, out_number};
    }

    std::sort(users, users + T, [&](PII a, PII b) {
        if (a.first == b.first) {
            return a.second < b.second;
        } else {
            return a.first < b.first;
        }
    });

    int answer = 0;
    int user_index = 0;
    for (int i = 9 * 60; i < 21 * 60; i++) {
        clear(i);
        while (true) {
            if (user_index == T) {
                break;
            }
            if (users[user_index].first > i) {
                break;
            }
            clear(i);
            get_seat(user_index);
            user_index++;
        }
        clear(i);
        if (seats[P] == 0) {
            answer++;
        }
    }

    std::cout << answer << "\n";

    return 0;
}
