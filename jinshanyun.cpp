#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;
//最近的公共祖先
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

void creat(TreeNode **root){
    int val;
    cin >> val;
    if(val == -1) root = nullptr;
    else{
        *root = new TreeNode(val);
        creat(&((*root)->left));
        creat(&((*root)->right));
    }
}

TreeNode *lowc(TreeNode* root, int p, int q){
    if(root == nullptr) return 0;
    if(root->val == p || root->val == q) return root;

    TreeNode *rleft = lowc(root->left,p,q);
    TreeNode *rright = lowc(root->right,p,q);
    if(rleft != nullptr && rright != nullptr) return root;
    else if(rright != nullptr) return rright;
    else return rleft;
    return nullptr;
}

int main(){
    TreeNode *root;
    creat(&root);
    
    int p, q;
    cin >> p >> q;
    TreeNode *t = lowc(root, p, q);
    cout << t->val << endl;

    return 0;
}