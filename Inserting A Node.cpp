#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

// creates a new node with the given data
node* createNode(int data) {
    node* newNode = new node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// inserts a new node with the given data in the tree rooted at the given node
node* insertNode(node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// returns the node with the minimum data value in the tree rooted at the given node
node* getMinimumNode(node* root) {
    node* current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

// deletes the node with the given data from the tree rooted at the given node
node* deleteNode(node* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            node* temp = root->right;
            delete(root);
            return temp;
        } else if (root->right == NULL) {
            node* temp = root->left;
            delete(root);
            return temp;
        } else {
            node* temp = getMinimumNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

// traverses the tree in order and prints the data of each node
void traverseInOrder(node* root) {
    if (root == NULL) {
        return;
    }
    traverseInOrder(root->left);
    cout << root->data << " ";
    traverseInOrder(root->right);
}

// main function
int main() {
    node* root = NULL;
    int operation, operand;
    cin >> operation;

    while (operation != -1) {
        switch(operation) {
            case 1: // insert
                cin >> operand;
                root = insertNode(root, operand);
                break;
            case 2: // delete
                cin >> operand;
                root = deleteNode(root, operand);
                break;
            default:
                cout << "Invalid Operator!\n";
                return 0;
        }
        cin >> operation;
    }

    traverseInOrder(root);
    return 0;
}
