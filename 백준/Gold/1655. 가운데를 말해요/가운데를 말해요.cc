#include <iostream>
#include <queue>

std::priority_queue<int, std::vector<int>, std::greater<int>> minQ;
std::priority_queue<int> maxQ;

int main() {
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    int n = 0;
    std::cin >> n;

    int inp = 0;
    for(int i = 0; i < n; i++){
        std::cin >> inp;
        if(minQ.size() == maxQ.size()){
            maxQ.push(inp);
        }else{
            minQ.push(inp);
        }

        if(!minQ.empty() && !maxQ.empty() && minQ.top() < maxQ.top()){
            int min_tmp = minQ.top();
            int max_tmp = maxQ.top();
            minQ.pop();
            maxQ.pop();
            minQ.push(max_tmp);
            maxQ.push(min_tmp);
        }
        std::cout << maxQ.top() << "\n";
    }
    return 0;
}
