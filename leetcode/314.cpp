#include <bits/stdc++.h>
using namespace std;


/*
https://leetcode.com/problems/binary-tree-vertical-order-traversal
*/

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<pair<int,TreeNode*>> q;
        unordered_map<int,vector<int>> mp;

        q.push({0, root});

        while(!q.empty()){
            auto [col, node] = q.front();
            q.pop();

            mp[col].push_back(node->val);

            if(node->left) q.push({col - 1, node->left});
            if(node->right) q.push({col + 1, node->right});
        }

        for(auto& [col, v] : mp){
            res.push_back(v);
        }

        return res;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<vector<int>> ans = sol.verticalOrder(root);

    for (auto& col : ans) {
        cout << "[";
        for (size_t i = 0; i < col.size(); i++) {
            cout << col[i];
            if (i + 1 < col.size()) cout << ",";
        }
        cout << "] ";
    }

    return 0;
}

/*
💭 first idea
🧩 key property / invariant
✅ key insight
🔁 recognition cue for next time
⏱ speed fix for next time
*/