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
    unordered_map<int, vector<TreeNode *>> memorization;
    
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode *> answer;
        if (n < 1 || n % 2 == 0) {
            return answer;
        }
        if (memorization.find(n) != memorization.end()) {
            return memorization[n];
        }
        if (n == 1) {
            answer.push_back(new TreeNode(0));
            memorization[1] = answer;
            return answer;
        }
         for (int i = 1; i < n; i += 2){
            vector<TreeNode *> left = allPossibleFBT(i);
            vector<TreeNode *> right = allPossibleFBT(n - 1 - i);
             
        for (int j = 0; j < left.size(); j++) {
            for (int k = 0; k < right.size(); k++) {
                TreeNode *root = new TreeNode(0);
                root->left = left[j];
                root->right = right[k];
                answer.push_back(root);
                }
            }
        }
        memorization[n] = answer;
        return answer;
        }
        
};
