

#include <iostream>
#include <bits/stdc++.h>


class Node {

    public:
        int value;
        Node * leftChild;
        Node * rightChild;

        Node(int nodeVal){

            value = nodeVal;
            leftChild = NULL;
            rightChild = NULL;
        }

};


class BST{

    Node * root;


    public:
        BST(){
            root = NULL;
        }

        BST(int root){
            root = new Node(root);

        }
        Node * getRoot()){
            return root;
        }


        void insertBSTRecursive(Node * currentNode, int value){

            if (currentNode == NULL){
                return new Node(value);
            }

            if (currentNode->value > value){

                currentNode->leftChild = insertBSTRecursive(currentNode->leftChild,value);
            }
            else {
                  currentNode->rightChild = insertBSTRecursive(currentNode->rightChild,value);
            }


            return currentNode;
        }

        void insertBST(int value){

            if (getRoot()== NULL){

                root = new Node(value);
                return;
            }


            Node * currentNode = root;
            Node * nodeToInsert = new Node(value);
            Node * parentNode;

            while (currentNode)
            {
               parentNode = currentNode;
               if (currentNode->value > value){

                   currentNode = currentNode->leftChild;
               } else {
                   currentNode = currentNode->rightChild;
               }
            }



            if (parentNode->value > value){
                parentNode->leftChild = nodeToInsert;
            }else {
                parentNode->rightChild = nodeToInsert;
            }
        }

        void Inorder(Node * node){

            if (node != NULL){

                    Inorder(node->leftChild);
                    cout<< node->value << endl;
                     Inorder(node->rightChild);

            }

        }


        bool searchBST(int searchVal){

                if (root == NULL){
                    return false;
                }

                Node * currentNode = root;


                while (currentNode){

                        if (currentNode->value == searchVal){
                            return true;
                        }
                        else   if (currentNode->value  > searchVal){
                                  currentNode = currentNode->leftChild;  
                        }
                        else {
                                    currentNode = currentNode->rightChild;  
                        }
                }
                return false;
        }

         bool searchBST_recursive(Node * currentNode, int searchVal){
            
            if (currentNode == NULL){
                return false;
            }
            
            if (currentNode->value == searchVal){
                return true;
            }
            else if (currentNode->value > searchVal){
                return searchBST_recursive(currentNode->leftChild,searchVal);
            }
            else {
                return searchBST_recursive(currentNode->rightChild,searchVal);
            }
        }


};

int main(){
  
    BinarySearchTree bst(13);    
    bst.insertBST(5);
    bst.insertBST(16);
    bst.insertBST(1);
    bst.printInorder(bst.getNode());
    return 0;
}