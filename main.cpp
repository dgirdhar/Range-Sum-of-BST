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
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        vector<TreeNode *> temp;
        
        temp.push_back(root);
        
        while (temp.size() > 0) {
            TreeNode *node = temp.back();
            
            temp.pop_back();            
            
            if (node != nullptr) { 
                if (node->val >= L && node->val <= R) {
                    sum += node->val;
                }
                if (node->left != nullptr && node->val >= L) {
                    temp.push_back(node->left);
                }
                if (node->right != nullptr && node->val <= R) {
                    temp.push_back(node->right);
                }
            }            
        }
        
        return sum;
    }
};
