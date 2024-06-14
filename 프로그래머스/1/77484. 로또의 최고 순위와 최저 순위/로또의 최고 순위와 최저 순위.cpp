#include <string>
#include <vector>

using namespace std;

int count[46];

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    for (int num : win_nums) {
        count[num]++;
    }
    int zeroCount = 0;
    int minwoo = 0;
    for (int num : lottos) {
        count[num]++;
        if (num == 0) {
            zeroCount++;
        } else if (count[num] == 2) {
            minwoo++;
        }
    }
    
    if (minwoo + zeroCount == 6) {
        answer.push_back(1);
    } else if (minwoo + zeroCount == 5) {
        answer.push_back(2);
    } else if (minwoo + zeroCount == 4) {
        answer.push_back(3);
    } else if (minwoo + zeroCount == 3) {
        answer.push_back(4);
    } else if (minwoo + zeroCount == 2) {
        answer.push_back(5);
    } else {
        answer.push_back(6);
    }
    
    if (minwoo < 2) {
        answer.push_back(6);
    } else if (minwoo == 2) {
        answer.push_back(5);
    } else if (minwoo == 3) {
        answer.push_back(4);
    } else if (minwoo == 4) {
        answer.push_back(3);
    } else if (minwoo == 5) {
        answer.push_back(2);
    } else {
        answer.push_back(1);
    }
    
    return answer;
}