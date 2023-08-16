#include <vector>
#include <iostream>

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
    TreeNode* copy(TreeNode* tree){
        if(tree->left == nullptr && tree->right == nullptr){
            return new TreeNode(0, nullptr, nullptr);
        }else if(tree->left == nullptr){
            return new TreeNode(0, nullptr, copy(tree->right));
        }else if(tree->right == nullptr){
            return new TreeNode(0, copy(tree->left), nullptr);
        }else{
            return new TreeNode(0, copy(tree->left), copy(tree->right));
        }
    }

    bool isEqual(TreeNode* t1, TreeNode* t2){
        if(t1->left == nullptr && t2->left == nullptr && t1->right == nullptr && t2->right == nullptr){
            return true;
        }else if(t1->left == nullptr || t2->left == nullptr){
            return t1->left == t2->left && isEqual(t1->right, t2->right);
        }else if(t1->right == nullptr || t2->right == nullptr){
            return t1->right == t2->right && isEqual(t1->left, t2->left);
        }else{
            return isEqual(t1->left, t2->left) && isEqual(t1->right, t2->right);
        }
    }

    bool contains(TreeNode* t, vector<TreeNode*> &trees){
        for(TreeNode* tree:trees){
            if(isEqual(t, tree)){
                return true;
            }
        }
        return false;
    }

    void addToAllLeaves(TreeNode *oldTree, TreeNode *root, vector<TreeNode *> &newTrees) {
        if(oldTree->left != nullptr){
            addToAllLeaves(oldTree->left, root, newTrees);
        }
        if(oldTree->right != nullptr){
            addToAllLeaves(oldTree->right, root, newTrees);
        }
        if(oldTree->right == nullptr && oldTree->left == nullptr){
            static TreeNode left;
            static TreeNode right;
            oldTree->left = &left;
            oldTree->right = &right;
            static TreeNode *newTree;
            newTree = copy(root);
            if(!contains(newTree, newTrees)) {
                newTrees.push_back(newTree);
            }
            oldTree->left = nullptr;
            oldTree->right = nullptr;
        }
    }

    void nextSolution(const vector<TreeNode *> &prev, vector<TreeNode *> &newSolutions) {
        vector<TreeNode*> newTrees;
        for(TreeNode* oldSolution:prev){
            addToAllLeaves(oldSolution, oldSolution, newTrees);
        }
        for(TreeNode *newTree:newTrees){
            newSolutions.push_back(newTree);
        }
    }



    vector<TreeNode*> allPossibleFBT(int n) {
        if(n % 2 == 0){
            return {};
        }

        vector<vector<TreeNode*>> solutions = vector<vector<TreeNode*>>(20);
        solutions[0] = {};
        static TreeNode start = TreeNode();
        solutions[1] = {&start};
        for(int i = 3; i <= n; i+=2){
            nextSolution(solutions[i-2], solutions[i]);
        }
        return solutions[n];
    }
};

int main(){
    vector<TreeNode*> test;
    Solution solver;
    test = solver.allPossibleFBT(19);
}