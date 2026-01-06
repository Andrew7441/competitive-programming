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
    int maxLevelSum(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr) return 1;

        queue<TreeNode*> qt;
        qt.push(root);

        int maxlevel = 1;
        int level = 1, maxsum = INT_MIN;

        while(!qt.empty()){
            int n = qt.size();
            int sum = 0;
            for(int i = 0; i < n; i++){
                TreeNode *curnode = qt.front();
                qt.pop();
                sum += curnode->val;

                if(curnode->left){
                    qt.push(curnode->left);
                }

                if(curnode->right){
                    qt.push(curnode->right);
                }
            }
            if(sum > maxsum){
                maxsum = sum;
                maxlevel = level;
            }
            level++;
        }
        return maxlevel;
    }
};

int main() {
    Solution Sol;

    // Construct the tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);

    cout << Sol.maxLevelSum(root) << endl;

    return 0;
}
