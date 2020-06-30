/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void getCount(TreeNode* root, int L, int R, int &count) {
        if (root != nullptr) {
            if (root->val >= L && root->val <= R) {
                count += root->val;
            }
            getCount(root->left, L, R, count);
            getCount(root->right, L, R, count);
        }
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        int count = 0;
        
        getCount(root, L, R, count);
        
        return count;
    }
};
