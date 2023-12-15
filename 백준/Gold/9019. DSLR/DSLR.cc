#include <iostream>
#include <vector>
#include <queue>

std::string dslr(int start, int dest){
    bool nums[10000] = {false, };

    std::queue<std::pair<int, std::string>> q;
    q.push(std::make_pair(start, ""));

    while(!q.empty()){
        int cur = q.front().first;
        std::string cmd = q.front().second;
        q.pop();

        // D
        if(2 * cur > 9999 && !nums[(2 * cur) % 10000]){
            if((2 * cur) % 10000 == dest){
                return cmd + 'D';
            }else{
                nums[(2 * cur) % 10000] = true;
                q.push(std::make_pair((2 * cur) % 10000, cmd + 'D'));
            }
        }else if(2 * cur < 10000 && !nums[2 * cur]){
            if(2 * cur == dest){
                return cmd + 'D';
            }else{
                nums[2 * cur] = true;
                q.push(std::make_pair(2 * cur, cmd + 'D'));
            }
        }

        // S
        if(cur == 0 && !nums[9999]){
            if(9999 == dest){
                return cmd + 'S';
            }else{
                nums[9999] = true;
                q.push(std::make_pair(9999, cmd + 'S'));
            }
        }else if(cur > 0 && !nums[cur - 1]){
            if(cur - 1 == dest){
                return cmd + 'S';
            }else{
                nums[cur - 1] = true;
                q.push(std::make_pair(cur - 1, cmd + 'S'));
            }
        }

        // L
        int tmp_l = (cur % 1000) * 10 + (cur / 1000);
        if(tmp_l == dest){
            return cmd + 'L';
        }else if(!nums[tmp_l]){
            nums[tmp_l] = true;
            q.push(std::make_pair(tmp_l, cmd + 'L'));
        }

        // R
        int tmp_r = (cur % 10) * 1000 + (cur / 10);
        if(tmp_r == dest){
            return cmd + 'R';
        }else if(!nums[tmp_r]){
            nums[tmp_r] = true;
            q.push(std::make_pair(tmp_r, cmd + 'R'));
        }
    }
}

int main() {
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    int tc = 0;
    std::cin >> tc;

    for(int i = 0; i < tc; i++){
        int a, b;
        std::cin >> a >> b;

        std::cout << dslr(a, b) << "\n";
    }

    return 0;
}
