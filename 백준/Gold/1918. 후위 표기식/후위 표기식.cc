#include <iostream>
#include <vector>
#include <stack>

std::stack<char> opr;
std::vector<char> ans;

int main() {
    std::string inp;
    std::cin >> inp;

    for(int i = 0; i < inp.length(); i++){
        if(inp[i] >= 'A' && inp[i] <= 'Z'){
            ans.emplace_back(inp[i]);
        }else if(inp[i] == '+' || inp[i] == '-'){
            if(!opr.empty()){
                if(opr.top() == '(') opr.push(inp[i]);
                else if(opr.top() == '*' || opr.top() == '/'){
                    while(!opr.empty()){
                        if(opr.top() == '(') break;
                        ans.emplace_back(opr.top());
                        opr.pop();
                    }
                    opr.push(inp[i]);
                }else{
                    ans.emplace_back(opr.top());
                    opr.pop();
                    opr.push(inp[i]);
                }
            }else{
                opr.push(inp[i]);
            }
        }else if(inp[i] == '*' || inp[i] == '/'){
            if(opr.empty()){
                opr.push(inp[i]);
            }else{
                if(opr.top() == '*' || opr.top() == '/'){
                    ans.emplace_back(opr.top());
                    opr.pop();
                    opr.push(inp[i]);
                }
                else{
                    opr.push(inp[i]);
                }
            }
        }else if(inp[i] == '(') {
            opr.push('(');
        }else if(inp[i] == ')'){
            while(opr.top() != '('){
                ans.emplace_back(opr.top());
                opr.pop();
            }
            opr.pop();
        }
    }
    while(!opr.empty()){
        ans.emplace_back(opr.top());
        opr.pop();
    }

    for(auto it : ans){
        std::cout << it;
    }


    return 0;
}
