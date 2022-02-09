// Binary search tree

#include<iostream>
using namespace std;

// Node for Binary Search Tree
class Node{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data);
};

Node::Node(int data){
    this->data = data;
    this->left = NULL;
    this->right = NULL;
}

typedef Node node;

// BST class
class BST{

public:
    node* insert(node *root, int data);
    void inorder_trav(node *root);
    void preorder_trav(node *root);
    void postorder_trav(node *root);
};


node* BST::insert(node *root, int data){ // BST insert function
    node* new_node = new node(data);

    if(root == NULL)
        return new_node;

    else{
        if(root->data < data)
            root->right = insert(root->right, data);
        else
            root->left = insert(root->left, data);
    }

    return root;
}

void BST::inorder_trav(node *root){

    if( root == NULL )
        return;

    inorder_trav(root->left);
    cout<< root->data << " ";
    inorder_trav(root->right);
}

void BST::preorder_trav(node *root){

    if(root == NULL)
        return;

    cout<<root->data<<" ";
    preorder_trav(root->left);
    preorder_trav(root->right);
}

void BST::postorder_trav(node *root){

    if(root == NULL)
        return;

    postorder_trav(root->left);
    postorder_trav(root->right);
    cout<<root->data<<" ";
}


int main(){

    //  #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    
    node *root = NULL;
    BST bst;
    root = bst.insert(root, 4);
    root = bst.insert(root, 2);
    root = bst.insert(root, 3);
    root = bst.insert(root, 1);
    root = bst.insert(root, 5);

    bst.inorder_trav(root);
    cout<<endl;
    bst.preorder_trav(root);
    cout<<endl;
    bst.postorder_trav(root);

    return 0;
}

    