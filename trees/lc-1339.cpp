// LeetCode 1339 — Maximum Product of Splitted Binary Tree
// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
// Topic: trees | Tags: dfs, prefix-sum
// Complexity (yours): O(n) time, O(h) recursion space
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    long long total = 0;
    long long mod = 1e9 + 7;

    void findtotalsum(TreeNode* root){
        if(!root) return;

        findtotalsum(root->left);
        findtotalsum(root->right);

        total += root->val;
    }

    long long solve(TreeNode *root, long long &maxprod){
        if(!root) return 0;

        long long left = solve(root->left, maxprod);
        long long right = solve(root->right, maxprod);

        long long subtreesum = root->val + left + right;
        long long prod = (subtreesum * (total - subtreesum));

        maxprod = max(maxprod, prod);

        return subtreesum; 
    }

    int maxProduct(TreeNode* root) {
        findtotalsum(root);

        long long maxprod = 1;

        solve(root, maxprod);

        return maxprod % mod;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    Solution Sol;
    cout << Sol.maxProduct(root) << endl; 

    return 0;
}

/*
💭 First Idea: Pass 1 gets the total sum; pass 2 (post-order) tries removing each edge: sub * (total - sub).
🧩 Key Property / Invariant: Cutting the edge above a node splits the tree into its subtree sum and total - subtree sum.
✅ Key insight: Maximise on the exact long long value and apply % only at the end; taking the max after modding is wrong.
🔁 Recognition cue for next time: "remove one edge / split a tree" -> subtree sums from a post-order DFS.
⏱  Speed fix for next time: Product is up to ~6e16, so use long long from the start.
🛠  Review: correct; O(n) -> Already optimal.
*/
