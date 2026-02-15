//a height of a balanced binary tree is balanced when the diffrence of height of left and the right side is 1 and less than 1
#include <iostream>
#include <cmath>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    int checkHeight(Node* root) {
        if(root == NULL) return 0;

        int lh = checkHeight(root->left);
        if(lh == -1) return -1;

        int rh = checkHeight(root->right);
        if(rh == -1) return -1;

        if(abs(lh - rh) > 1) return -1;

        return max(lh, rh) + 1;
    }

    bool isBalanced(Node* root) {
        return checkHeight(root) != -1;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    Solution sol;
    if(sol.isBalanced(root)) {
        cout << "Tree is balanced" << endl;
    } else {
        cout << "Tree is not balanced" << endl;
    }

    return 0;
}