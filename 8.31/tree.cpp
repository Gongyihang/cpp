#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr){}
};

class Solution {
public:
    vector<int> ans;
    void preorder(TreeNode* root)
    {
        if (root == nullptr)
            return;
        ans.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }

    vector<int> preorderTraversal(TreeNode* root)
    {
        preorder(root);
        return ans;
    }
};

class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> res;
        stack<TreeNode*> call;
        if (root != nullptr)
            call.push(root);
        while (!call.empty()) {
            TreeNode* t = call.top();
            call.pop();
            if (t != nullptr) {
                if (t->right)
                    call.push(t->right);
                if (t->left)
                    call.push(t->left);
                call.push(t);
                call.push(nullptr);
            } else {
                res.push_back(call.top()->val);
                call.pop();
            }
        }
        return res;
    }
};


class Solution{
    public:
    vector<int> preorder(TreeNode *root){
        vector<int> res;
        stack<TreeNode*> call;
        if(root != nullptr){
            call.push(root);
        }
        while (!call.empty())
        {
            TreeNode *t = call.top();
            call.pop();
            if(t != nullptr){
                if(t->right != nullptr) call.push(t->right);
                if(t->left != nullptr) call.push(t->right);
                call.push(t);
                call.push(nullptr);
            }else{
                res.push_back(call.top()->val);
                call.pop();
            }
        }
        return res;
    }
};

int main()
{
    system("pause");
    return 0;
}