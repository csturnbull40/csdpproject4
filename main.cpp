//
//  main.cpp
//  csdp250p4
//
//  Created by Chris Turnbull on 11/6/23.
//
#include <iostream>
#include <cstdlib>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

struct ListNode {
    int data;
    ListNode* next;

    ListNode(int val) : data(val), next(nullptr) {}
};

void insertIntoLinkedList(ListNode*& head, int val) {
    ListNode* newNode = new ListNode(val);
    newNode->next = head;
    head = newNode;
}

void displayLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void insertIntoBST(TreeNode*& root, int val) {
    if (root == nullptr) {
        root = new TreeNode(val);
        return;
    }
    if (val < root->data) {
        insertIntoBST(root->left, val);
    } else {
        insertIntoBST(root->right, val);
    }
}

void preOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    TreeNode* bstRoot = nullptr;
    ListNode* linkedListHead = nullptr;

    for (int i = 0; i < 35; i++) {
        int randomNum = rand() % 100;
        insertIntoBST(bstRoot, randomNum);
        insertIntoLinkedList(linkedListHead, randomNum);
    }

    cout << "BST Pre order traversal: ";
    preOrderTraversal(bstRoot);
    cout << "\n";

    cout << "BST In order traversal: ";
    inOrderTraversal(bstRoot);
    cout << "\n";

    cout << "BST Post order traversal: ";
    postOrderTraversal(bstRoot);
    cout << "\n";

    cout << "Linked List: ";
    displayLinkedList(linkedListHead);

    return 0;
}
