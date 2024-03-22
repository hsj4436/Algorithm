#include <string>
#include <vector>
#include <set>

using namespace std;

int N;
string number;
string prime;
bool selected[8];
bool isPrime[10000000];
set<int> primes;

void combination(int primeIndex) {
    if (primeIndex > 0 && isPrime[stoi(prime)]) {
        primes.insert(stoi(prime));
    }
    
    if (primeIndex == N) {
        return;
    } 
    
    for (int i = 0; i < N; i++) {
        if (selected[i]) {
            continue;
        }
        selected[i] = true;
        prime.push_back(number[i]);
        combination(primeIndex + 1);
        prime.pop_back();
        selected[i] = false;
    }
}

int solution(string numbers) {
    int answer = 0;
    
    fill(isPrime + 2, isPrime + 10000000, true);
    N = numbers.size();
    for (int i = 2; i < 10000000; i++) {
        if (!isPrime[i]) {
            continue;
        }
        for (int j = i * 2; j < 10000000; j += i) {
            isPrime[j] = false;
        }
    }
    number = numbers;
    combination(0);
    answer = primes.size();
    return answer;
}