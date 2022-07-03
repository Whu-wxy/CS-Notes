#ifndef TREETEST_H
#define TREETEST_H

#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//迭代法遍历模版----后序遍历
vector<int> postorderTraversal(TreeNode* root) {
    if(root == nullptr) return {};

    //迭代法-栈
    vector<int> res;
    stack<TreeNode*> st;
    st.push(root);

    // 后序遍历=中右左+反转
    // while(!st.empty())
    // {
    //     TreeNode* top = st.top();
    //     res.push_back(top->val);
    //     st.pop();
    //     if(top->left) st.push(top->left);
    //     if(top->right) st.push(top->right);
    // }
    // reverse(res.begin(), res.end());

    // 如果不能用反转
    while(!st.empty())
    {
        TreeNode* top = st.top();
        if(top != nullptr)
        {
            st.pop();           //防止重复处理
            st.push(top);       //压入中结点
            st.push(nullptr);   //中节点访问过，但是还没有处理，加入空节点做为标记。
            if(top->right) st.push(top->right);  //压入右结点
            if(top->left) st.push(top->left);    //压入左结点
        }
        else
        {
            st.pop();           //先把nullptr弹出
            top = st.top();
            st.pop();           //
            res.push_back(top->val);
        }
    }
    return res;
}

//广度优先层序遍历-队列
vector<vector<int>> levelOrder(TreeNode* root)
{
    queue<TreeNode*> que;
    if (root != NULL) que.push(root);
    vector<vector<int>> result;
    while (!que.empty()) {
        int size = que.size();
        vector<int> vec;
        // 这里一定要使用固定大小size，不要使用que.size()，因为que.size是不断变化的
        for (int i = 0; i < size; i++) {
            TreeNode* node = que.front();
            que.pop();
            vec.push_back(node->val);
            if (node->left) que.push(node->left);
            if (node->right) que.push(node->right);
        }
        result.push_back(vec);
    }
    return result;
}

//序列化
string findDuplicate(vector<TreeNode*>& duNode, unordered_map<string, int>& tree_map, TreeNode* node)
{
    if(node == nullptr) return "#";
    string ltree = findDuplicate(duNode, tree_map, node->left);
    string rtree = findDuplicate(duNode, tree_map, node->right);
    string tree = ltree + "," + to_string(node->val) + ","  + rtree;
    tree_map[tree]++;
    if(tree_map[tree]==2)   //>1
        duNode.push_back(node);
    return tree;
}

vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
{
    if(root == NULL) return {};
    vector<TreeNode*> duNode;
    unordered_map<string, int> tree_map;
    findDuplicate(duNode, tree_map, root);
    return duNode;
}

void tree_test()
{
    TreeNode *n1 = new TreeNode(4);
    TreeNode *n2 = new TreeNode(4);
    TreeNode *n3 = new TreeNode(4);
    TreeNode *n4 = new TreeNode(2, n2, nullptr);
    TreeNode *n5 = new TreeNode(2, n1, nullptr);
    TreeNode *n6 = new TreeNode(3, n4, n3);
    TreeNode *n7 = new TreeNode(1, n5, n6);
    vector<TreeNode*> res = findDuplicateSubtrees(n7);
}


//根据前序和中序构建二叉树
TreeNode* buildTree(const vector<int>& preorder, int preBegin, int preEnd, const vector<int>& inorder, int inBegin, int inEnd) {
    if(preBegin >= preEnd) return nullptr;

    int rootVal = preorder[preBegin];
    TreeNode* node = new TreeNode(rootVal);
    if(preBegin + 1 == preEnd) return node;

    int i=inBegin;
    for(; i<inEnd; i++)
    {
        if(inorder[i] == rootVal)
            break;
    }

    int lInBegin = inBegin;
    int lInEnd = i;
    int rInBegin = i+1;
    int rInEnd = inEnd;

    int lPreBegin = preBegin + 1;
    int lPreEnd = lPreBegin + lInEnd - lInBegin;
    int rPreBegin = lPreEnd;
    int rPreEnd = preEnd;

    node->left = buildTree(preorder, lPreBegin, lPreEnd, inorder, lInBegin, lInEnd);
    node->right = buildTree(preorder, rPreBegin, rPreEnd, inorder, rInBegin, rInEnd);
    return node;
}

TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
    if(preorder.empty()) return nullptr;

    return buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
}

#endif // TREETEST_H
