// LeetCode 865 — Smallest Subtree with all the Deepest Nodes
// https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/
// Topic: trees | Tags: dfs, lca
// Complexity (yours): O(n) time, O(h) space
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
    int deepestlevel = 0;
    TreeNode* ans = nullptr;
    
    int dfs(TreeNode* root, int level){
        if(!root) return level - 1;

        auto left = dfs(root->left, level + 1);
        auto right = dfs(root->right, level + 1);

        int curlevel = max(left, right);
        deepestlevel = max(deepestlevel, curlevel);

        if(deepestlevel == left && deepestlevel == right) 
            ans = root;

        return curlevel;
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        dfs(root, 0);

        return ans;
    }
};


int main() {
    /*
        Tree structure for:
        [3,5,1,6,2,0,8,null,null,7,4]

                3
               / \
              5   1
             / \ / \
            6  2 0  8
              / \
             7   4
    */

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;
    TreeNode* result = sol.subtreeWithAllDeepest(root);

    cout << result->val << endl;
}

/*
💭 First Idea: Post-order DFS returning the max depth of each subtree; a node whose left and right max depths both equal the global deepest becomes the answer.
🧩 Key Property / Invariant: Post-order ⇒ the last node meeting left == right == deepest is the LCA of all deepest leaves.
✅ Key insight: Answer = LCA of the deepest leaves: a node qualifies when both sides reach the max depth (a deepest leaf counts).
🔁 Recognition cue for next time: "Smallest subtree containing all deepest nodes" (same as LC 1123) → DFS returning (depth, node).
⏱  Speed fix for next time: Return pair<int, TreeNode*> from dfs to avoid global state and the reset bug if the object is reused.
🛠  Review: correct (stress-tested vs brute force); O(n) time, O(h) stack — Already optimal.
*/
