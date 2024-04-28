#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int index;
    int x;
    int y;
    node* left;
    node* right;
    node () {}
    node (int index, int x, int y) : index(index), x(x), y(y), left(NULL), right(NULL) {}
};

node* insert(node* cur, int index, int x, int y) {
    if (cur == NULL) {
        return new node(index, x, y);
    }
    
    if (x < cur->x) {
        cur->left = insert(cur->left, index, x, y);
    } else {
        cur->right = insert(cur->right, index, x, y);
    }
    
    return cur;
}

vector<int> preOrder;
vector<int> postOrder;

void makeOrder(node* cur) {
    if (cur == NULL) {
        return;
    }
    preOrder.push_back(cur->index);
    makeOrder(cur->left);
    makeOrder(cur->right);
    postOrder.push_back(cur->index);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    
    for (int i = 0; i < nodeinfo.size(); i++) {
        nodeinfo[i].push_back(i + 1);
    }
    sort(nodeinfo.begin(), nodeinfo.end(), [&](vector<int> a, vector<int> b) {
       if (a[1] == b[1]) {
           return a[0] < b[0];
       } else {
           return a[1] > b[1];
       }
    });
    
    node* root = new node(nodeinfo[0][2], nodeinfo[0][0], nodeinfo[0][1]);
    for (int i = 1; i < nodeinfo.size(); i++) {
        if (nodeinfo[i][0] < root->x) {
            root->left = insert(root->left, nodeinfo[i][2], nodeinfo[i][0], nodeinfo[i][1]);
        } else {
            root->right = insert(root->right, nodeinfo[i][2], nodeinfo[i][0], nodeinfo[i][1]);
        }
    }
    
    makeOrder(root);
    
    answer.push_back(preOrder);
    answer.push_back(postOrder);
    
    return answer;
}