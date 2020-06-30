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
    int sum;
public:
    void getCount(TreeNode* root, int L, int R) {
        if (root != nullptr) {
            if (root->val >= L && root->val <= R) {
                sum += root->val;
            }
            if (root->left != nullptr && root->val >= L) {
                getCount(root->left, L, R);
            }
            if (root->right != nullptr && root->val <= R) {
                getCount(root->right, L, R);
            }
        }
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        sum = 0;
        
        getCount(root, L, R);
        
        return sum;
    }
};
