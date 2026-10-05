// LeetCode 314 — Binary Tree Vertical Order Traversal
// https://leetcode.com/problems/binary-tree-vertical-order-traversal/
// Topic: trees | Tags: hashing, queue, bfs
// Complexity (yours): O(n) time, O(n) space
// ⚠️ Review: columns come out in unordered_map order (sample prints [20] [7] [9] [3,15]) and root == nullptr crashes; see corrected version below.
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

// ===================== ⚡ Corrected =====================
// Same BFS, but output columns left -> right (track minCol..maxCol) and handle an empty tree.
class SolutionOptimized {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) return {};
        unordered_map<int, vector<int>> cols;
        int minCol = 0, maxCol = 0;
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});
        while (!q.empty()) {
            auto [col, node] = q.front(); q.pop();
            cols[col].push_back(node->val);   // BFS => top-to-bottom, left-to-right inside a column
            minCol = min(minCol, col); maxCol = max(maxCol, col);
            if (node->left)  q.push({col - 1, node->left});
            if (node->right) q.push({col + 1, node->right});
        }
        vector<vector<int>> res;
        for (int c = minCol; c <= maxCol; c++) res.push_back(move(cols[c]));
        return res;
    }
};

/*
💭 first idea: BFS with (column, node) pairs, collecting values per column in an unordered_map.
🧩 key property / invariant: BFS visits top-to-bottom and left-to-right, so each column's vector is already in the required order.
✅ key insight: columns must be output left → right, but unordered_map iteration order is arbitrary — use map or loop minCol..maxCol.
🔁 recognition cue for next time: "vertical order / columns of a tree" → BFS + column index, offset by minCol.
⏱ speed fix for next time: run the sample — [20] [7] [9] [3,15] instead of [9] [3,15] [20] [7] shows the bug instantly; also guard root == nullptr.
🛠  Review: wrong — unordered column order + null-root crash; yours O(n) → corrected O(n).
*/