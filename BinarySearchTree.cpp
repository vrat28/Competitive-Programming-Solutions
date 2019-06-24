

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

    
        bool deleteBST(int value){
            DeleteNode(root,value);
        }


      Node * findLeastLeftMostNode(Node * currentNode){
            Node * temp = currentNode;
            
            while (temp->leftChild != NULL){
                
                temp= temp->leftChild;
            }
            return temp;
        }

         bool DeleteNode(Node * currentNode, int value){
              
              //1. Empty Node
                if (currentNode == nullptr){
                    return false;
                }

                Node * parent ;

                while (currentNode && currentNode->value != value)
                {
                    parent = currentNode;

                    if (currentNode->leftChild-> value){
                        currentNode = currentNode->leftChild;
                    }
                   else {
                       currentNode = currentNode->rightChild;
                   }
                }
                

                //2. Not found
                if (currentNode == NULL){
                    return false;
                }
                
                // 3. Having no left/right child-> Leaf node
                else if (currentNode->leftChild == NULL && currentNode->rightChild == NULL){

                // Root 
                    if (root->value == currentNode->value){
                        delete root;
                        root = NULL;
                        return true;
                    }
                    // Left leaf Node
                    else if (parent->value > currentNode->value){
                        delete parent->leftChild;
                        parent->leftChild = NULL;
                        return true;
                    }
                    // Right Leaf Node
                    else {
                        delete parent->rightChild;
                        parent->rightChild = NULL;
                        return true;
                    }
                    
                }
                // 4.Having only Left Child
                else if ( currentNode->rightChild == NULL){
                    
                    // Root 
                    if (root->value == currentNode->value){
                        delete root;
                        root = currentNode->leftChild;
                        return true;
                    }
                    else {
                        
                        // node has left child and is left child of parent
                        
                        if (parent->value > currentNode->value){
                            
                            // it is left leftChild
                            parent->leftChild = currentNode->leftChild;
                            delete currentNode;
                            return true;
                        }
                        
                        // node has left child and is right child of parent
                        else {
                            
                            // it is a rightchild having only left node
                            parent->rightChild = currentNode->leftChild;
                            delete currentNode;
                            return true;
                            
                        }
                    }
                    
                }
                // 5. Having only right child
                else if (currentNode->leftChild == NULL){
                    
                    // 5(A) Root
                    if (root->value == currentNode->value){
                        
                        delete root;
                        root = currentNode->rightChild;
                        return true;
                    }
                    else {
                            // 5 B - Leaf Node with Only right Child
                            if (currentNode->value > parent->value){
                                // It is right child of parent-
                                
                                parent->rightChild = currentNode->rightChild;
                                delete currentNode;
                                return true;
                            }
                            else {
                                
                                delete parent->leftChild;
                                parent->leftChild = currentNode->rightChild;
                                return true;
                                // It is left child of parent
                            }
                    }
                }
                
                else  // Having both left and right children
                {
                    
                        Node * leastNodeOfRightSubtree = findLeastLeftMostNode(currentNode->rightChild);
                        
                        int temp = leastNodeOfRightSubtree->value;
                        DeleteNode(root,temp);
                        currentNode->value = temp;
                        return true;
                }

            return false;
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