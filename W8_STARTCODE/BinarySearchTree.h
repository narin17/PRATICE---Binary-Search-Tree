#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Node.h"
#include <queue>

using namespace std;

class BinarySearchTree {
private:
    Node* root;
public:
    BinarySearchTree() : root(nullptr) {}
    BinarySearchTree(int value) {
        root = new Node(value);
    }
    int calculateHeight() {
        return calculateHeight(root);
    }
    Node* getroot() {
        return root;
    }
    std::string printTree() {
        std::string result = "";
        printTree(root, 0, result);
        return result;
    }

public:
    //exercise 1
    Node* getsuccesor(Node* root){
        Node* current = root->right;
        while(current != nullptr && current->left != nullptr){
            current = current->left;
        }
        return current;
    }

    bool search(Node* root, int key){
        //your code here
        if(root == nullptr){
            return false;
        }
        if(root->data == key){
            return true;
        }
        if(root->data < key){
            return search(root->right, key);
        }
        else{
            return search(root->left, key);
        }
        
    }
    void insert(Node*& root, int newValue) {
        //your code here
        if (root == nullptr) {
            root = new Node(newValue);
            return;
        }
        if (newValue < root->data) {
            insert(root->left, newValue);
        } else {
            insert(root->right, newValue);
        }
}
    void deleteNode(Node*& root, int value){
        //your code here
        if (root == nullptr) {
            return;
        }
        if (root->data > value) {
            deleteNode(root->left, value);
        } else if (root->data < value) {
            deleteNode(root->right, value);
        } else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                root = temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                root = temp;
            } else {
                Node* successor = getsuccesor(root);
                root->data = successor->data;
                deleteNode(root->right, successor->data);
            }
        }

    }
    //exercise 2
    std::string levelOrderTraverse() {
        std::string result = "";
        //your code here
        if (root == nullptr) return "";

        queue<Node*> q;       
        q.push(root);         

        while (!q.empty()) {
            Node* current = q.front(); 
            q.pop();                 
            result += to_string(current->data) + " "; 

            if (current->left != nullptr) {
                q.push(current->left);
            }

            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
        return result;
    }

    
private:
    void printTree(Node* node, int depth, std::string& result) {
        if (node == nullptr) return;
        for (int i = 0; i < depth; ++i) {
            result += "- ";
        }
        result += std::to_string(node->data) + "\n";
        printTree(node->left, depth + 1, result);
        printTree(node->right, depth + 1, result);
    }

    int calculateHeight(Node* node) {
        if (node == nullptr) return 0;
        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);
        return std::max(leftHeight, rightHeight) + 1;
    }

};

#endif // BINARYTREE_H