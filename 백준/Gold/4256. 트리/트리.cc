#include <iostream>
#include <vector>

int preOrder[1001];
int inOrder[1001];
int inOrderIndex[1001];

void postOrder(int inStart, int inEnd, int preStart, int preEnd) {

    if (inStart > inEnd || preStart > preEnd) {
        return;
    }

    int rootIndex = inOrderIndex[preOrder[preStart]];
    int leftSize = rootIndex - inStart;
    int rightSize = inEnd - rootIndex;

    postOrder(inStart, rootIndex - 1, preStart + 1, preStart + leftSize);
    postOrder(rootIndex + 1, inEnd, preStart + leftSize + 1, preEnd);

    std::cout << inOrder[rootIndex] << " ";

}

int main()
{
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    int tc = 0;
    std::cin >> tc;

    for (int i = 0; i < tc; i++) {
        int n = 0;
        std::cin >> n;

        for (int j = 0; j < n; j++) {
            std::cin >> preOrder[j];
        }
        for (int j = 0; j < n; j++) {
            std::cin >> inOrder[j];
            inOrderIndex[inOrder[j]] = j;
        }

        postOrder(0, n - 1, 0, n - 1);
        std::cout << "\n";

    }
    return 0;
}
