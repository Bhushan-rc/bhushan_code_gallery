#include <iostream>
#include <vector>

struct Node {

    int data = 0;
    Node *left = 0, *right = 0;
    Node(int val) : data(val) {}
};

class BST {

    private:
    Node *root = 0;

    Node * insert(Node *node, int &val) {

        if(node == NULL) return new Node(val);
        
        (val > node->data)
            ? node->right = insert(node->right, val)
            : node->left = insert(node->left, val);

        return node;
    }

    bool search(Node *node, int &val) {

        if(node == NULL) return false;
        
        if(val == node->data) return true;

        if(val > node->data)
            return search(node->right, val);
        else
            return search(node->left, val);
    }

    static int countLevel(Node *node) {

        if(node == NULL) return 0;

        auto lcount = countLevel(node->left);
        auto rcount = countLevel(node->right);

        return std::max(lcount, rcount) + 1;
    }

    static void showTree(Node* node, std::ostream &out, int space = 0)
    {
        if (node == nullptr) return;

        const int tab = 4;
        space += tab;

        // Print right subtree first
        showTree(node->right, out, space);

        for (int i = tab; i < space; ++i)
            out << " ";

        out << node->data << "\n";

        // Print left subtree
        showTree(node->left, out, space);
    }
    
    public:
    void insert(std::vector<int> &datalist) {

        for(auto &val : datalist) {
        
            root = insert(root, val);
        }
    }

    bool search(int val) {

        return search(root, val);
    }

    friend std::ostream & operator << (std::ostream &out, BST &tree) {

        int level = countLevel(tree.root);
        showTree(tree.root, out);
        return out;
    }
};

int main() { 

    system("cls");

    std::vector<int> datalist = {50, 30, 70, 20, 40, 60, 80};

    BST tree;
    tree.insert(datalist);
    std::cout << tree;

    int findVal = 40;
    std::string res = tree.search(findVal) ? "contains " : "not contains ";
    std::cout << "\n BST " << res << findVal;

    findVal = 45;
    res = tree.search(findVal) ? "contains " : "not contains ";
    std::cout << "\n BST " << res << findVal;
}