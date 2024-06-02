#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(int n, int k) {
    int answer = 0;
    
    string baseK;
    while (n != 0) {
        baseK.push_back((n % k) + '0');
        n /= k;
    }
    reverse(baseK.begin(), baseK.end());
    
    int index = 0;
    while (index != baseK.size()) {
        string stringNumber;
        while (baseK[index] != '0') {
            stringNumber.push_back(baseK[index]);
            index++;
            if (index == baseK.size()) {
                break;
            }
        }
        if (index != baseK.size()) {
            index++;
        }
        if (stringNumber.empty() || stoll(stringNumber) < 2) {
            continue;
        }
        long long number = stoll(stringNumber);
        bool isPrime = true;
        for (long long i = 2; i * i <= number; i++) {
            if (number % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            answer++;
        }
    }
    
    return answer;
}