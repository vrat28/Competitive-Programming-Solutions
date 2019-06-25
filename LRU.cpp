#include<iostream>
#include<map>
using namespace std;


class Node {
    public:

        int key;
        int value;
        Node * lastNode;
        Node * nextNode;

        Node(){
            key = 0;
            value = 0;
            nextNode = NULL;
            lastNode = NULL;
        }

        Node (int key,int value){

            this->key = key;
            this->value = value;
            lastNode = NULL;
            nextNode = NULL;
        }
};

class DoubleEndedQueue{

       
         Node * front;
         Node * rear;


        bool isEmpty(){
                return rear == NULL;
        }
    
    public:

        DoubleEndedQueue(): front(NULL), rear(NULL) {}

        Node * getFront(){
            return front;
        }

          Node * getRear(){
            return rear;
          }

    
        Node * addItemToFront(int key, int value){

            Node * page = new Node(key,value);

            if (front == NULL && rear == NULL){
                front = rear = page;
            }
            else {
                  page->nextNode = front;
                  front->lastNode =page;
                  front = page;

            }
            return page;
        }

        void movePageToFront(Node * page){

                if (front == NULL){
                    return;
                }

                if (page == rear){

                    rear = rear->lastNode;
                    rear->nextNode = NULL;
                }
                else {
                    page->lastNode->nextNode = page->nextNode;
                    page->nextNode->lastNode = page->lastNode;
                }

                page->nextNode = front;
                front->lastNode = page;
                page->lastNode = NULL;    
                front = page;
        }
    

        void removeLastElement(){

            if (isEmpty()){
                return;
            }

            if (front == rear){
                delete rear;
                front = rear = NULL;
            }


            Node * temp = rear;
            rear = rear->lastNode;
            rear->nextNode = NULL;
            delete temp;
        }
        

};

class LRU{

     int capacity,size;
    DoubleEndedQueue * queue;
        map<int,Node *> hashTable;

    public:

        LRU(int capacity){
            this->capacity = capacity;
            size = 0;
            hashTable = map<int , Node*>();
            queue = new DoubleEndedQueue();
        }

        int get(int key){

                if (hashTable.find(key) == hashTable.end()){
                        return -1;
                }

                int value = hashTable[key]->value;
                queue->movePageToFront(hashTable[key]);
                return value;
        }

        void set(int key,int value){

        
            if (hashTable.find(key)!= hashTable.end()){
            Node * node = hashTable[key];
            node->value = value;
            queue->movePageToFront(node);
            return;

            }

             if (size == capacity){

                    int lastKey = queue->getRear()->key;
                    hashTable.erase(lastKey);
                    removeLRUItem();
                    size--;

                }
             Node * newNode = queue->addItemToFront(key,value);
             hashTable[key] = newNode;
            size++;

        }

        void removeLRUItem(){
           queue->removeLastElement();
        }


        ~LRU(){

            map<int,Node *> :: iterator i;

            for (i = hashTable.begin(); i != hashTable.end();++i){
                delete i->second;
            }
           // delete hashTable;
        }

};


int main(){

    LRU cache(5);
    cache.set(2,2);
    cout << cache.get(2) << endl;
    cache.set(1,1);
    cache.set(1,5);
    cout << cache.get(1) << endl;
    cout << cache.get(2) << endl;

    return 0;
}

