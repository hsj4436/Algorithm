#include <string>
#include <vector>
#include <set>

using namespace std;

set<int> dp[9];

int getNs(int N, int counts) {
    int result = 0;
    for (int i = 0; i < counts; i++) {
        result *= 10;
        result += N;
    }
    return result;
}

int solution(int N, int number) {
    int answer = 0;

    if (N == number) {
        return 1;
    }
    dp[1].insert(N);
    
    for (int i = 2; i < 9; i++) {
        int Ns = getNs(N, i);
        if (Ns == number) {
            return i;
        }
        dp[i].insert(Ns);
        for (int j = 1; j < i / 2 + 1; j++) {
            if (i - j < 1) {
                continue;
            }
            for (int a : dp[j]) {
                for (int b : dp[i - j]) {
                    if (a + b == number) {
                        return i;
                    }
                    dp[i].insert(a + b);
                    
                    if (a - b == number) {
                        return i;
                    }
                    dp[i].insert(a - b);
                    
                    if (b - a == number) {
                        return i;
                    }
                    dp[i].insert(b - a);
                    
                    if (a * b == number) {
                        return i;
                    }
                    dp[i].insert(a * b);
                    if (b > 0) {
                        if (a / b == number) {
                            return i;
                        }
                        dp[i].insert(a / b);
                    }
                    if (a > 0) {
                        if (b / a == number) {
                            return i;
                        }
                        dp[i].insert(b / a);
                    }
                }
            }
        }
        for (int j = 1; j < i; j++) {
            Ns = getNs(N, j);
            for (int n : dp[i - j]) {
                if (n + Ns == number) {
                    return i;
                }
                dp[i].insert(n + Ns);
                if (n * Ns == number) {
                    return i;
                }
                dp[i].insert(n * Ns);

                if (n - Ns == number) {
                    return i;
                }
                dp[i].insert(n - Ns);
                
                if (Ns - n == number) {
                    return i;
                }
                dp[i].insert(Ns - n);
                
                if (n > 0) {
                    if (Ns / n == number) {
                        return i;
                    }
                    dp[i].insert(Ns / n);
                }
                
                if (Ns > 0) {
                    if (n / Ns == number) {
                        return i;
                    }
                    dp[i].insert(n / Ns);
                }
            }
            
        }
    }
    
    return -1;
}