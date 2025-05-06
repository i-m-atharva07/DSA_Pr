#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node* buildBST(int arr[], int n) {
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
    return root;
}

int longestPathFromRoot(Node* root) {
    if (root == NULL) return 0;
    int leftPath = longestPathFromRoot(root->left);
    int rightPath = longestPathFromRoot(root->right);
    return 1 + max(leftPath, rightPath);
}

int findMinimum(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL) return root->data;
    return findMinimum(root->left);
}

void mirror(Node* root) {
    if (root == NULL) return;
    mirror(root->left);
    mirror(root->right);
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

bool searchValue(Node* root, int val) {
    if (root == NULL) return false;
    if (root->data == val) return true;
    if (val < root->data)
        return searchValue(root->left, val);
    else
        return searchValue(root->right, val);
}

int main() {
    int arr[6] = {5, 1, 3, 4, 2, 7};
    Node* root = buildBST(arr, 6);
    insert(root, 9);

    int searchVal = 4;

    if (searchValue(root, searchVal)) {
        cout << searchVal << " found in the tree." << endl;
    } else {
        cout << searchVal << " not found in the tree." << endl;
    }

    cout << "Longest path from root: " << longestPathFromRoot(root) << endl;
    cout << "Minimum value in the tree: " << findMinimum(root) << endl;

    cout << "Inorder after mirroring: ";
    mirror(root);
    inorder(root);
    cout << endl;

    return 0;
}
