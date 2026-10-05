// LeetCode 1382 — Balance a Binary Search Tree
// https://leetcode.com/problems/balance-a-binary-search-tree/
// Topic: trees | Tags: binary-search, recursion
// Complexity (yours): n/a (stub) -> optimized O(n) time, O(n) space
// ⚠️ Review: empty stub, no solution written; see corrected version below.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
};

int main() {
    
}

// ===================== ⚡ Optimized =====================
// Your file was a stub; this is the standard approach: in-order -> sorted vector -> rebuild from the middle.
// To submit: paste the Solution body below (LeetCode already provides TreeNode).
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class SolutionOptimized {
public:
    vector<TreeNode*> nodes;

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        nodes.push_back(root);
        inorder(root->right);
    }

    TreeNode* build(int l, int r) {          // nodes[l..r] are sorted
        if (l > r) return nullptr;
        int mid = l + (r - l) / 2;
        TreeNode* root = nodes[mid];
        root->left = build(l, mid - 1);
        root->right = build(mid + 1, r);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        nodes.clear();
        inorder(root);
        return build(0, (int)nodes.size() - 1);
    }
};

/*
💭 First Idea: None yet (empty stub).
🧩 Key Property / Invariant: The in-order traversal of a BST is sorted; any sorted array rebuilt from its midpoint gives a height-balanced BST.
✅ Key insight: Flatten the tree in-order, then recursively make the middle element the root.
🔁 Recognition cue for next time: "rebalance / build a balanced BST" -> sorted array + pick the middle as root.
⏱  Speed fix for next time: Reuse the existing nodes (no new allocations); Day-Stout-Warren gets O(1) extra space if ever needed.
🛠  Review: unfinished (empty Solution); optimized O(n) time / O(n) space added.
*/
