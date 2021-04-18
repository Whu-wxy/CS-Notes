#ifndef ALGORITHMMOBAN_H
#define ALGORITHMMOBAN_H

#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

int binary_search(vector<int>& nums, int target)
{
    int left = 0, right = nums.size() - 1;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else if(nums[mid] == target)
        {
            // 直接返回
            return mid;
        }
    }
    // 直接返回
    return -1;
}

int left_bound(vector<int>&  nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else if (nums[mid] == target)
        {
            // 别返回，锁定左侧边界
            right = mid - 1;
        }
    }
    // 最后要检查 left 越界的情况
    if (left >= nums.size() || nums[left] != target)
        return -1;
    return left;
}


int right_bound(vector<int>&  nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else if (nums[mid] > target)
        {
            right = mid - 1;
        }
        else if (nums[mid] == target)
        {
            // 别返回，锁定右侧边界
            left = mid + 1;
        }
    }
    // 最后要检查 right 越界的情况
    if (right < 0 || nums[right] != target)
        return -1;
    return right;
}


void kmp(int* next, const string& s)
{
    next[0] = -1;
    int j = -1;
    for(int i = 1; i < s.size(); i++)
    {
        while (j >= 0 && s[i] != s[j + 1])
        {
            j = next[j];
        }
        if (s[i] == s[j + 1])
        {
            j++;
        }
        next[i] = j;
    }
}


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//前序遍历（中左右）
void traversal(TreeNode* cur, vector<int>& vec) {
    if (cur == NULL) return;

    vec.push_back(cur->val);    // 中 ，同时也是处理节点逻辑的地方
    traversal(cur->left, vec);  // 左
    traversal(cur->right, vec); // 右
}

//迭代法前序遍历
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;
    if (root != NULL) st.push(root);
    while (!st.empty())
    {
        TreeNode* node = st.top();
        if (node != NULL)
        {
            st.pop();
            if (node->right) st.push(node->right);  // 右
            if (node->left) st.push(node->left);    // 左
            st.push(node);                          // 中
            st.push(nullptr);
        }
        else
        {
            st.pop();
            node = st.top();
            st.pop();
            result.push_back(node->val);            // 节点处理逻辑
        }
    }
    return result;
}

//迭代法中序遍历
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result; // 存放中序遍历的元素
    stack<TreeNode*> st;
    if (root != NULL) st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top();
        if (node != NULL) {
            st.pop();
            if (node->right) st.push(node->right);  // 右
            st.push(node);                          // 中
            st.push(NULL);
            if (node->left) st.push(node->left);    // 左
        } else {
            st.pop();
            node = st.top();
            st.pop();
            result.push_back(node->val);            // 节点处理逻辑
        }
    }
    return result;
}

//迭代法后序遍历
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;
    if (root != NULL) st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top();
        if (node != NULL) {
            st.pop();
            st.push(node);                          // 中
            st.push(NULL);
            if (node->right) st.push(node->right);  // 右
            if (node->left) st.push(node->left);    // 左

        } else {
            st.pop();
            node = st.top();
            st.pop();
            result.push_back(node->val);            // 节点处理逻辑
        }
    }
    return result;
}

//层序遍历
vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode*> que;
    if (root != NULL) que.push(root);
    vector<vector<int>> result;
    while (!que.empty()) {
        int size = que.size();
        vector<int> vec;
        for (int i = 0; i < size; i++) {// 这里一定要使用固定大小size，不要使用que.size()
            TreeNode* node = que.front();
            que.pop();
            vec.push_back(node->val);   // 节点处理的逻辑
            if (node->left) que.push(node->left);
            if (node->right) que.push(node->right);
        }
        result.push_back(vec);
    }
    return result;
}


//回溯
//void backtracking(参数) {
//    if (终止条件) {
//        存放结果;
//        return;
//    }

//    for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
//        处理节点;
//        backtracking(路径，选择列表); // 递归
//        回溯，撤销处理结果
//    }
//}



// 滑动窗口算法框架
//void slidingWindow(string s, string t)
//{
//    unordered_map<char, int> need, window;
//    for (char c : t) need[c]++;

//    int left = 0, right = 0;
//    int valid = 0;
//    while (right < s.size()) {
//        // c 是将移入窗口的字符
//        char c = s[right];
//        // 右移窗口
//        right++;
//        // 进行窗口内数据的一系列更新
//        ...


//        // 判断左侧窗口是否要收缩
//        while (window needs shrink) {
//            // d 是将移出窗口的字符
//            char d = s[left];
//            // 左移窗口
//            left++;
//            // 进行窗口内数据的一系列更新
//            ...
//        }
//    }
//}

#endif // ALGORITHMMOBAN_H
