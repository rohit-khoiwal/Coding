#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // if((root->left == nullptr) && (root->right == nullptr))
        //     return {root->val};
            
        vector<int> inorderData;
        recurSiveFunction(root, inorderData);
        return inorderData;
    }

private:
    void recurSiveFunction(TreeNode* root, vector<int>&inorderData)
    {
        if(nullptr == root)
            return;
        
        recurSiveFunction(root->left, inorderData);
        inorderData.push_back(root->val);
        recurSiveFunction(root->right, inorderData);
    }
};


int main()
{
    TreeNode* root = new TreeNode(1);
    TreeNode* root1 = new TreeNode(2);
    root->right = root1;
    TreeNode* root2 = new TreeNode(3);
    root1->left = root2;
    Solution s;
    vector<int>relativeSortedArr = s.inorderTraversal(root);
    for(auto num : relativeSortedArr)
        cout<<num<<' ';
}