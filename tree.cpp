#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
//树节点定义（此处与leetcode定义保持一致）
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}//初值列
};
//先序创建一棵树
void creatpre(TreeNode** root)
{
    /*
  如序列：{1 2 -1 -1 3 -1 -1}表示1结点有2,3两个孩子，2,3结点没有孩子。
  如序列：{3 5 6 -1 -1 2 7 -1 -1 4 -1 -1 1 9 -1 -1 8 -1 -1}
  */
    int val;
    cin >> val;
    if (val == -1)
        root = nullptr;
    else {
        *root = new TreeNode(val);
        creatpre(&((*root)->left));
        creatpre(&((*root)->right));
    }
}
//后序创建一棵树
void creatpost(TreeNode** root, vector<int>& t, bool flag)
{
    /*
  如序列：{-1 -1 2 -1 -1 3 1}表示1结点有2,3两个孩子，2,3结点没有孩子。
  如序列：{-1 -1 6 -1 -1 7 -1 -1 4 2 5 -1 -1 9 -1 -1 8 1 3}
  */
    int val;
    char ch;
    if (flag) {                                     //flag标记第一次获取二叉树序列
        while (cin >> val) {
            t.push_back(val);
            if ((ch = getchar()) == '\n')
                break;
        }
        flag = false;
    }
    static int count = t.size();
    val = t[--count];
    if (val == -1)
        root = nullptr;
    else {
        *root = new TreeNode(val);
        creatpost(&((*root)->right), t, flag);
        creatpost(&((*root)->left), t, flag);
    }
}
//先中后三种递归遍历方式
class traversal_rec {
public:
    vector<int> ans;
    vector<int> preorder(TreeNode* root)
    {
        if (root == NULL)
            return ans;
        ans.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
        return ans;
    }
    vector<int> inorder(TreeNode* root)
    {
        if (root == NULL)
            return ans;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
        return ans;
    }
    vector<int> posorder(TreeNode* root)
    {
        if (root == NULL)
            return ans;
        posorder(root->left);
        posorder(root->right);
        ans.push_back(root->val);
        return ans;
    }
};
//先中后三种迭代遍历二叉树
class traversal_ite {
public:
    vector<int> res;                                //保存结果
    vector<int> preorder(TreeNode* root)
    {
        stack<TreeNode*> call;                      //调用栈
        if (root != nullptr)
            call.push(root);                        //首先介入root节点
        while (!call.empty()) {
            TreeNode* t = call.top();
            call.pop();                             //访问过的节点弹出
            if (t != nullptr) {
                if (t->right)
                    call.push(t->right);            //右节点先压栈，最后处理
                if (t->left)
                    call.push(t->left);
                call.push(t);                       //当前节点重新压栈（留着以后处理），因为先序遍历所以最后压栈
                call.push(nullptr);                 //在当前节点之前加入一个空节点表示已经访问过了
            } else {                                //空节点表示之前已经访问过了，现在需要处理除了递归之外的内容
                res.push_back(call.top()->val);     // call.top()是nullptr之前压栈的一个节点，也就是上面call.push(t)中的那个t
                call.pop();                         //处理完了，第二次弹出节点（彻底从栈中移除）
            }
        }
        return res;
    }

    vector<int> inorder(TreeNode* root)
    {
        stack<TreeNode*> call;
        if (root != nullptr)
            call.push(root);
        while (!call.empty()) {
            TreeNode* t = call.top();
            call.pop();
            if (t != nullptr) {
                if (t->right)
                    call.push(t->right);
                call.push(t);                       //在左节点之前重新插入该节点，以便在左节点之后处理（访问值）
                call.push(nullptr);                 //nullptr跟随t插入，标识已经访问过，还没有被处理
                if (t->left)
                    call.push(t->left);
            } else {
                res.push_back(call.top()->val);
                call.pop();
            }
        }
        return res;
    }

    vector<int> postorder(TreeNode* root)
    {
        stack<TreeNode*> call;
        if (root != nullptr)
            call.push(root);
        while (!call.empty()) {
            TreeNode* t = call.top();
            call.pop();
            if (t != nullptr) {
                call.push(t);                       //在右节点之前重新插入该节点，以便在最后处理（访问值）
                call.push(nullptr);                 //nullptr跟随t插入，标识已经访问过，还没有被处理
                if (t->right)
                    call.push(t->right);
                if (t->left)
                    call.push(t->left);
            } else {
                res.push_back(call.top()->val);
                call.pop();
            }
        }
        return res;
    }
};

class level_order {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        queue<TreeNode*> que;
        if (root != NULL)
            que.push(root);
        vector<vector<int>> result;
        while (!que.empty()) {
            int size = que.size();
            vector<int> vec;
            for (int i = 0; i < size; i++) {        // 这里一定要使用固定大小size，不要使用que.size()，因为que.size是不断变化的
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
            result.push_back(vec);
        }
        return result;
    }
};

// p结点与q结点的最近公共祖先
TreeNode* lowc(TreeNode* root, int p, int q)
{
    if (root == nullptr)
        return 0;
    if (root->val == p || root->val == q)
        return root;

    TreeNode* rleft = lowc(root->left, p, q);
    TreeNode* rright = lowc(root->right, p, q);
    if (rleft != nullptr && rright != nullptr)
        return root;
    else if (rright != nullptr)
        return rright;
    else
        return rleft;
    return nullptr;
}

int main()
{
    TreeNode* root;
    //先序创建二叉树
    creatpre(&root);
    //后序创建二叉树
    // vector<int> tree;
    // creatpost(&root, tree, true);

    traversal_rec rec;
    // vector<int> res = rec.preorder(root);
    // vector<int> res = rec.inorder(root);
    // vector<int> res = rec.posorder(root);

    traversal_ite ite;
    // vector<int> res = ite.preorder(root);
    // vector<int> res = ite.inorder(root);
    // vector<int> res = ite.postorder(root);
    // for (int i = 0; i < (int)res.size(); i++) {
    //     cout << res[i] << " ";
    // }

    // level_order level;
    // vector<vector<int>> res = level.levelOrder(root);
    // for(int i = 0;i < (int)res.size();i++){
    //     for(int j = 0;j < (int)res[i].size();j++){
    //         cout << res[i][j] << " ";
    //     }
    // }

    //求二叉树结点p，q最近的公共祖先
    // int p, q;
    // cin >> p >> q;
    // TreeNode *t = lowc(root, p, q);
    // cout << t->val << endl;
    return 0;
}