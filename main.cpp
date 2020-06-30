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
        TreeNode *temp[20001] = {0};
        int currentCounter = 0;
        int totalCount = 1;
        
        temp[0] = root;
        
        while (currentCounter < totalCount) {
            TreeNode *node = temp[currentCounter];
            
            currentCounter++;
            
            if (node != nullptr) { 
                if (node->val >= L && node->val <= R) {
                    sum += node->val;
                }
                if (node->left != nullptr && node->val >= L) {
                    temp[totalCount++] = node->left;
                }
                if (node->right != nullptr && node->val <= R) {
                    temp[totalCount++] = node->right;
                }
            }            
        }
        
        return sum;
    }
};
