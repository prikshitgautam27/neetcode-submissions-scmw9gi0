
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        // We start with nullptr for both boundaries because 
        // the root has no minimum or maximum limits yet.
        return validate(root, nullptr, nullptr);
    }

private:
    bool validate(TreeNode* node, TreeNode* minNode, TreeNode* maxNode) {
        // Base case: An empty tree/branch is a valid BST
        if (node == nullptr) {
            return true;
        }

        // Check the lower bound: 
        // If minNode exists, current value MUST be strictly greater than minNode->val
        if (minNode != nullptr && node->val <= minNode->val) {
            return false;
        }

        // Check the upper bound: 
        // If maxNode exists, current value MUST be strictly smaller than maxNode->val
        if (maxNode != nullptr && node->val >= maxNode->val) {
            return false;
        }

        // Recursive Calls:
        // 1. For Left: The current node becomes the NEW upper limit (maxNode).
        // 2. For Right: The current node becomes the NEW lower limit (minNode).
        return validate(node->left, minNode, node) && 
               validate(node->right, node, maxNode);
    }
};
